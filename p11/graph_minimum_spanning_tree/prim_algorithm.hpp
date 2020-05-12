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
	float distance;
	int j;

	std::vector <std::pair <typename WGraph<T>::NodeRef, bool>> 
	U(g.capacity(), std::pair<typename WGraph<T>::NodeRef, bool>(nullptr, false));
	std::vector <typename WGraph<T>::NodeRef> V(g.capacity(), nullptr);
	std::vector <float> C(g.capacity(), std::numeric_limits<float>::infinity());


	//TODO: Add the start node to the Minimum Spanning Tree (mst).
	U[u->label()].first = u;
	U[u->label()].second = true;

	//ITERATE FOR the N-1 edges.
	for (size_t e=1; e<g.size(); ++e) {
		//TODO: Update vector of best distances regarding the last vertex added u to the mst.
		while (g.has_current_edge()) {
			if (C[g.current_edge()->other(u)->label()] > g.current_weight()) {
				U[g.current_edge()->other(u)->label()].first = g.current_edge()->other(u);
				V[g.current_edge()->other(u)->label()] = u;
				C[g.current_edge()->other(u)->label()] = g.current_weight();
			}

			g.goto_next_edge();
		}

		//TODO: Find the next vertex to be added to the mst.
		//Remeber: if a tie exists, select the vertex with lesser label.
		//You can use std::numeric_limits<float>::infinity() if it is necessary.
		j = 0;
		distance = std::numeric_limits<float>::infinity();
		
		for (int i = 0; i < C.size(); ++i) {
			if (distance > C[i] && !U[i].second) {
				distance = C[i];
				j = i;
			}
		}

		//TODO: check if a valid condition is met for a connected graph.
		//Suggestion: What about the minimum distance found?
		if (total_distance == std::numeric_limits<float>::infinity()) 
			throw std::runtime_error("It is a non-connected graph.");

		//TODO:Set vertex found as beloning to the mst.

		//TODO:Add the edge found to the mst vector.
		mst.push_back(GraphEdge<T, float>::make(U[j].first, V[j], C[j]));
		U[j].second = true;
		C[j] = std::numeric_limits<float>::infinity();
		V[j] = nullptr;
		u = U[j].first;
		g.goto_node(u);

		//TODO: update the total distance of the mst with the new edge's weight.
		total_distance += distance;
	}

	return total_distance;
}



#endif //__FLOYD_ALGORITHM_HPP__
