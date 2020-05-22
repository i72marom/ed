#ifndef A_STAR_ALGORITHM_HPP
#define A_STAR_ALGORITHM_HPP

#include <tuple>
#include <queue>
#include <vector>
#include <limits>
#include <functional>

#include "graph.hpp"

/**
 * @brief A* algorithm.
 * Its a version of Dijkstra algorithm with an heuristic to find out the
 * the shortest path between two vertex.
 * @arg[in] g is the graph.
 * @arg[in] start,
 * @arg[in] end are the vertices to link.
 * @arg[in] distance is a functional to compute a heuristic of the distance between two vertices.
 * @arg[out] predecesors is the predecesor vector.
 * @arg[out] distances is the distances vector.
 * @return the number of iterations executed.
 * @pre g.has(source)
 * @pre g.has(end)
 */
template<class T, class Distance>
size_t
a_star_algorithm(WGraph<T>& g,
				 typename WGraph<T>::NodeRef const& start,
				 typename WGraph<T>::NodeRef const& end,
				 const Distance& distance,
				 std::vector<size_t>& predecessors,
				 std::vector<float>& distances)
{
	assert(g.has(start));
	assert(g.has(end));

	//Remember to use (dist-to-end,dist-front-start,u,v) format for the tuples due to they are lexicographicaly sorted.
	//Use typedef to create an alias. So we'll have an easier code.
	//TODO: typedef std::typle< ...... > Tuple;
	typedef std::tuple<float, float, typename WGraph<T>::NodeRef, typename WGraph<T>::NodeRef> Tuple;

	//Initialize data.
	size_t iterations = 0;
	g.set_visited(false);
	predecessors.resize(g.size());
	for (size_t i=0;i<predecessors.size();++i)
		predecessors[i]=i;
	distances.resize(g.size(), std::numeric_limits<float>::infinity());

	//TODO: Create a priority queue. Remember we want to pick up the lowest item into the queue.
	std::priority_queue <Tuple> p_queue;

	//TODO: Insert the first item. You can use std::make_tuple(...) for this.
	p_queue.push(std::make_tuple(distance(start, end), 0.0, start, start));

	//While there are nodes to visit and the end node has not been achieved ...
	while (!(p_queue.empty() || end->is_visited())) {
		iterations ++;

		// TODO: Get the next tuple to process and
		// remove the tuple from the queue.
		Tuple t = p_queue.top();		
		p_queue.pop();

		//TODO: Set u as the next vertex to visit.
		auto u = std::get<2>(t);
		g.goto_node(u);

		//If u is not visited yet, it will be processed.
		if (!u->is_visited()) {
			// Set u as visited.
			u->set_visited(true);
			
			// Update predessors[u] and distances[u]
			predecessors[u->label()] = std::get<3>(t)->label();
			distances[u->label()] = std::get<1>(t);

			//Add new tuples for not visited vertices linked with u.
			while (g.has_current_edge()) {
				auto v = g.current_edge()->other(u);
				if (!v->is_visited())
					p_queue.push(std::make_tuple(
						distances[u->label()] + g.current_edge()->item() + distance(v, end),
						distances[u->label()] + g.current_edge()->item(), v, u));

				g.goto_next_edge();
			}
		}
	}

	return iterations;
}

#endif // A_STAR_ALGORITHM_HPP
