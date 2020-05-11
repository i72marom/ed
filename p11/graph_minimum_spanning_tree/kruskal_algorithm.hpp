#ifndef __KRUSKAL_ALGORITHM_HPP__
#define __KRUSKAL_ALGORITHM_HPP__

#include <exception>
#include <limits>
#include <memory>
#include <vector>
#include <algorithm>

#include "graph.hpp"
#include "disjointsets.hpp"

/**
 * @brief Get the list of edges for a non directed graph.
 * @arg[in] the graph.
 * @arg[out] edge_list a vector with the edges.
 * @post only u--v with u<v edges are saved in the list.
 */
template <class T>
void compute_list_of_edges(WGraph<T>& g, std::vector<typename WGraph<T>::EdgeRef>& edge_list)
{
    edge_list.resize(0);
    //TODO: extract the edges.
}

/**
 * @brief functional to compare two edges.
 * This functional will be used to sort the edge list.
 * Remember that the list is sorted from lesser to greater weights,
 * and when equal weights, use the vertex's labels in the way: (a,b)<(b,c)<(b,d).
 */
template<class T>
struct KruskalEdgeCompare
{
  bool operator()(const typename WGraph<T>::EdgeRef & a, const typename WGraph<T>::EdgeRef & b) const
  {
      return true; //TODO: replace for a better check.
  }
};

/**
 * @brief Apply the kruskal algorithm to a undirected connected graph to get the minimum spannig tree.
 * The current node of g is used as root.
 * @arg[in] g is the graph.
 * @arg[out] mst is the list of edges of g that forms the minium spanning tree.
 * @return the total weigth of the mininum spanning tree.
 * @pre g is an undirected connected graph.
 */
template <class T>
float
kruskal_algorithm(WGraph<T>& g, std::vector<typename WGraph<T>::EdgeRef>& mst)
{    
    float total_distance = 0.0;

    //Get the list of edges.
    std::vector<typename WGraph<T>::EdgeRef> edges;        
    compute_list_of_edges(g, edges);

    std::sort(edges.begin(), edges.end(), KruskalEdgeCompare<T>());

    //Create the DisjointSet to colorize the vertices.
    DisjointSets sets (g.size());

    //TODO: Generate a "color" set for each vertex (see assignment description).

    //Scann the list of edges.
    for(size_t i = 0; i< edges.size(); ++i)
    {
        //TODO: if edge[i] u--v a valid edge, add the edge to mst,
        //update total distance and make u,v have the same color (see assignment description).

    }

    return total_distance;
}
#endif //__KRUSKAL_ALGORITHM_HPP__
