#ifndef __FLOYD_ALGORITHM_HPP__
#define __FLOYD_ALGORITHM_HPP__

#include <exception>
#include <limits>
#include <memory>
#include <valarray>
#include <vector>

#include "graph.hpp"

/**
 * @brief Apply the Prim algorithm to a undirected connected graph to get the minimum spannig tree.
 * The current node of g is used as root.
 * @arg[in] g is the graph.
 * @arg[out] mst is the list of edges of g that forms the minium spanning tree.
 * @return the total weigth of the mininum spanning tree.
 * @pre g is an undirected connected graph.
 * @pre g.hash_current()
 * @warning throw std:runtine_error("It is a non-connected graph.") if a solution could not be computed.
 */
template <class T>
float
prim_algorithm(WGraph<T>& g, std::vector<typename WGraph<T>::EdgeRef>& mst) noexcept(false)
{
	assert(g.has_current_node());

	//TODO: Declare the U, V and C vectors according to the algorithm (see class documentation.)

	float total_distance = 0.0;
	auto u = g.current_node();
	typename WGraph<T>::NodeRef v;

	std::vector <typename WGraph<T>::NodeRef> 
	U(g.capacity(), typename WGraph<T>::NodeRef(nullptr));
	std::vector <typename WGraph<T>::NodeRef> V(g.capacity(), nullptr);
	std::vector <float> C(g.capacity(), std::numeric_limits<float>::infinity());


	//TODO: Add the start node to the Minimum Spanning Tree (mst).
	U[u->label()] = u;
	U[u->label()]->set_visited(true);

	//ITERATE FOR the N-1 edges.
	for (size_t e=1; e<g.size(); ++e) {
		//TODO: Update vector of best distances regarding the last vertex added u to the mst.
		while (g.has_current_edge()) {
			auto other = g.current_edge()->other(u);

			if (C[other->label()] > g.current_weight() && !other->is_visited()) {
				U[other->label()] = other;
				V[other->label()] = u;
				C[other->label()] = g.current_weight();
			}

			g.goto_next_edge();
		}

		//TODO: Find the next vertex to be added to the mst.
		//Remeber: if a tie exists, select the vertex with lesser label.
		//You can use std::numeric_limits<float>::infinity() if it is necessary.
		//j = 0;
		C[u->label()] = std::numeric_limits<float>::infinity();
		
		for (int i = 0; i < C.size(); ++i) {
			if (C[u->label()] > C[i]) u = U[i];
		}

		//TODO: check if a valid condition is met for a connected graph.
		//Suggestion: What about the minimum distance found?
		if (total_distance == std::numeric_limits<float>::infinity()) 
			throw std::runtime_error("It is a non-connected graph.");

		//TODO:Add the edge found to the mst vector.
		mst.push_back(GraphEdge<T, float>::make(U[u->label()], V[u->label()], C[u->label()]));
		
		U[u->label()]->set_visited(true);
		V[u->label()] = nullptr;
		g.goto_node(u);

		//TODO: update the total distance of the mst with the new edge's weight.
		total_distance += C[u->label()];
	}

	return total_distance;
}



#endif //__FLOYD_ALGORITHM_HPP__
