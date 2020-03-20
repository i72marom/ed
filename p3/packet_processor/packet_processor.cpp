#include "packet_processor.hpp"

PacketProcessor::PacketProcessor(size_t size) {
	//TODO
	size_ = size;
	// DONE
}

Response 
PacketProcessor::process(const Packet &packet)
{
	//TODO
	//Cuando llega un paquete:
	//
	// 1. quitaremos de la cola todos los que llegaron antes y que
	//	  ya han sido procesados.
	// 2. Si no hay espacio en la cola, este paquete será dropped y termina
	//    su procesado retornando Response(true, 0).
	// 3. Sino
	// 3.1 Si la cola está vacía, el paquete será procesado inmediatamente
	//     retornando Response(false, tiempo de llegada)
	// 3.2 Sino será encolado y su tiempo de inicio de proceso será 
	//     por lo tanto el tiempo finalización del procesado del
	//     último paquete encolado retornando 
	//     Response(false, tiempo de finalización del último paquete).
	//
	// Cuestión: En la cola, ¿qué encolamos?; el tiempo de llegada o 
	// el tiempo de finalización.
	// 
	// en este caso se encola el tiempo de finalizacion
	if (!buffer_.is_empty() && (packet.arrival_time >= buffer_.front())) buffer_.deque();
	if (buffer_.size() == size_) return Response(true, 0);
	if (buffer_.is_empty()) {
		buffer_.enque(packet.arrival_time + packet.process_time);
		return Response(false, packet.arrival_time);
	}

	int back = buffer_.back();
	buffer_.enque(buffer_.back() + packet.process_time);
	return Response(false, back);

  /*  // 1
    if (!this->PacketProcessor_.is_empty())
        if (packet.arrival_time >= this->PacketProcessor_.front())
            this->PacketProcessor_.deque();

    // 2
    if (this->PacketProcessor_.size() == this->size_)
        return Response(true, 0);

    // 3.1
    if (this->PacketProcessor_.is_empty())
    {
        this->PacketProcessor_.enque(packet.arrival_time + packet.process_time);
        return Response(false, packet.arrival_time);
    }

    // 3.2
    int old_back = this->PacketProcessor_.back();
    int time_work = this->PacketProcessor_.back() + packet.process_time;
    this->PacketProcessor_.enque(time_work);
    return Response(false, old_back);
    //DONE*/
}


/** @brief process the packets and generate a response for each of them.*/
std::vector <Response>
process_packets(const std::vector <Packet> &packets,
				PacketProcessor& p)
{
	std::vector <Response> responses;
	for (size_t i = 0; i < packets.size(); ++i)
		responses.push_back(p.process(packets[i]));
	return responses;
}

/** @brief print the processing start times for the packets.*/
std::ostream&
write_responses(std::ostream &out, const std::vector <Response> &responses)
{
	for (size_t i = 0; i < responses.size(); ++i)
		out << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
	return out;
}
