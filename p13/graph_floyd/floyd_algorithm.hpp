#ifndef __FLOYD_ALGORITHM_HPP__
#define __FLOYD_ALGORITHM_HPP__

#include <stack>
#include <utility>
#include <valarray>

#include "graph.hpp"
#include "graph_utils.hpp"



/**
 * @brief Compute the weight matrix.
 * @arg[in] g is a weighted graph.
 * @arg[out] W is the Weight matrix.
 */
template<class T>
void compute_weight_matrix(WGraph<T>& g, std::valarray<std::valarray<float>>& W) {
	W.resize(g.size(), std::valarray<float>(std::numeric_limits<float>::infinity(), g.size()));
	//TODO
	g.goto_first_node();

	for (int i = 0; i < g.size(); ++i) {
		while (g.has_current_edge()) {
			auto first = g.current_edge()->first()->label();
			auto second = g.current_edge()->second()->label();
			
			if (g.current_weight() < W[first][second])
				W[first][second] = g.current_weight();

			g.goto_next_edge();
		}
		g.goto_next_node();
	}
}

/**
 * @brief Search for the minium path between vertices using the Floyd's algorithm.
 * @arg[in] g is a weighted graph.
 * @arg[out] D is the Distances matrix.
 * @arg[out] I is the Intermediate matrix.
 * @pre the weigths meet the triangular inequality: d(u,v) <= d(u,k) + d(k,v) for all u!=v!=k.
 * @post if none path between u,v exists then D[u][v]==inf and I[u][v]==-1
 * @post if an edge (u,v:w) exists then D[u][v]==w and I[u][v]==-1
 * @post if a path between u,v exits then D[u][v]<inf and D[u][v]==k, k is vertex in the minimum path linking u with v.
 */
template<class T>
void floyd_algorithm(WGraph<T>& g, std::valarray<std::valarray<float>>& D,
					 std::valarray<std::valarray<int>>& I)
{
	compute_weight_matrix<T>(g, D);
	//Set self-distances to zero.
	for (size_t i=0;i<g.size();++i)
		D[i][i]=0.0;
	I.resize(g.size(), std::valarray<int>(-1, g.size()));

	//TODO: codify the Floyd's algorithm.
	for (size_t k = 0; k < g.size(); ++k) {
		for (size_t i = 0; i < g.size(); ++i) {
			for (size_t j = 0; j < g.size(); ++j) {
				if ((D[i][k] + D[k][j]) < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					I[i][j] = k;
				}
			}
		}
	}
}

/**
 * @brief Given the Floyd's Intermidiate matrix, compute the path.
 * @arg[in] u is the label of the start vertex.
 * @arg[in] v is the label of the end vertex.
 * @arg[in] I is the Floyd's Intermidiate matrix.
 * @arg[out] path is a vector with the sequence of vertex's labels for the minimum path linking u with v.
 * @pre Let D be the Floyd's D matrix corresponding with I, D[u][v]<inf.
 * @post u is the first item of path.
 * @post v is the last item of path.
 */
inline void
floyd_compute_path(size_t u, size_t v, std::valarray<std::valarray<int>>& I, std::vector<size_t>& path)
{
	//Prec: distance (u,v) < inf
	path.resize(0);

	//TODO:
	//Think first: is it necessary to build a binary tree?
	// or
	// is it sufficient with a recursive descent by doing an in-depth search?
	std::stack <std::pair <int,int>> frontier;
	frontier.push(std::make_pair(u,v));

	while (!frontier.empty()) {
		size_t l = frontier.top().first, r = frontier.top().second;
		frontier.pop();

		if (I[l][r] == -1) path.push_back(l);
		else {
			frontier.push(std::make_pair(I[l][r],r));
			frontier.push(std::make_pair(l,I[l][r]));
		}
	}

	path.push_back(v);
}


#endif //__FLOYD_ALGORITHM_HPP__
