#ifndef __Queue_HPP__
#define __Queue_HPP__

#include <cassert>
#include <cstdlib>
#include <stack>


/**
 * @brief ADT Queue.
 * Models a queue of T.
 */
template<class T>
class Queue
{
	public:

		/** @name Life cicle.*/
		/** @{*/

		/** @brief Create an empty Queue.
		 * @post is_empty()
		 */
		Queue () : head_(NULL), tail_(NULL) {
			//TODO
			assert(this->is_empty());
			// DONE
		}

		/** @brief Destroy a Queue.**/
		~Queue() {
			//TODO
			while (!this->is_empty()) this->deque();
			// DONE
		}

		/** @}*/

		/** @name Observers*/

		/** @{*/

		/** @brief is the list empty?.*/
		bool is_empty () const {
			//TODO
			return (head_ == NULL);
			// DONE
		}

		/** @brief Gets the number of items in the queue.*/
		size_t size() const {
			//TODO
			int cont = 0;
			nodo *aux;
			aux = new nodo;
			aux = head_;

			while ((aux = aux->next) != NULL) cont++;

			return cont;

			// DONE
		}

		/** @brief get the front item (the oldest one).
		 * @pre not is_empty()
		 */
		const T& front() const {
			//TODO
			return head_->value;
			// DONE
		}

		/** @brief get the back item (the newest one).
		 * @pre not is_empty()
		 */
		const T& back() const {
			//TODO
			assert(!this->is_empty());
			return tail_->value;
			// DONE
		}

		/**@}*/

		/** @name Modifiers*/

		/** @{*/

		/** @brief Insert a new item.
		 * @post !is_empty()
		 */
		void enque(const T& new_it) {
			//TODO

			// creo un nuevo nodo auxiliar para introducir 
			// el nuevo elemento en la cola
			nodo *new_nd;
			new_nd = new nodo;
			new_nd->value = new_it;

			// si la cola ya esta creada, el elemento siguiente
			// al ultimo elemento actual ahora apunta al nuevo elemento
			// y el ultimo elemento ahoraes ese nuevo elemento
			if (tail_ != NULL) tail_->next = new_nd;
			tail_ = new_nd;

			// si la cola no esta creada, head_ apunta a NULL
			// por tanto, al crearla apunta al nuevo elemento
			if (head_ == NULL) head_ = new_nd;

			assert(!this->is_empty());

			// DONE
		}

		/** Remove the front item.
		 * @pre not is_empty()
		 * @post !is_empty() || size()==0
		 */
		void deque() {
			//TODO
			assert(!this->is_empty());

			// para eliminar el primer elemento de la lista
			// necesitamos que el puntero apunte a su siguiente elemento
			// el primer elemento lo guardamos en un puntero auxiliar 
			// para despues liberar memoria con delete
			nodo *aux = head_;
			head_ = head_->next;
			delete aux;

			// DONE
		}

		/** @} */

	private:

		/** @brief Copy constructor.
		 * @warning we don't want a copy constructor.
		 */
		Queue(const Queue<T>& other)
		{}

		/** @brief Assign operator.
		 * @warning we don't want the assign operator.
		 */
		Queue<T>& operator=(const Queue<T>& other)
		{
			return *this;
		}

	protected:
		//TODO
		struct nodo {
			T value;
			nodo *next;
		};

		nodo *head_;
		nodo *tail_;
		// DONE
};

#endif
