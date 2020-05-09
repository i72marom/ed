#ifndef __GRAPH_TRAVERSALS_HPP
#define __GRAPH_TRAVERSALS_HPP

#include <stack>
#include <queue>

#include "graph.hpp"

/**
 * @brief Depth first search from a vertex.
 * The current node will be used as start vertex.
 * @arg g is the graph.
 * @arg p is a functional to process the vertex.
 * @return the last p() return value.
 * @pre g.has_current_node()
 * @warning if p() return false, the search will be finished.
 * @warning only a spanning tree is searched.
 */
template<class T, class Processor>
bool depth_first_search(WGraph<T>& g, Processor& p)
{
    assert(g.has_current_node());
    bool ret_val = true;

    //TODO
    //Do an ITERATIVE implementation.



    return ret_val;
}

/**
 * @brief breadth first search from a vertex.
 * The current node will be used as start node.
 * @arg g is the graph.
 * @arg p is a functional to process the vertex.
 * @return the last p() return value.
 * @pre g.has_current_node()
 * @warning if p() return false, the search will be finished.
 * @warning only a spanning tree is searched.
 */
template<class T, class Processor>
bool breadth_first_search(WGraph<T>& g, Processor& p)
{
    assert(g.has_current_node());
    bool ret_val = true;

    //TODO

    return ret_val;
}

#endif // __GRAPH_TRAVERSALS_HPP
