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
	typedef typename GraphNode<T>::Ref NodeRef;

	std::stack <NodeRef> frontier;
	NodeRef u, v;
	
	frontier.push(g.current_node());

	while (!frontier.empty()){
		u = frontier.top();
		frontier.pop();

		if (!u->is_visited()) {
			u->set_visited(true);
			ret_val = p.apply(u);
			g.goto_node(u);

			while (g.has_current_edge()) {
				v = g.current_edge()->other(u);
				if (!v->is_visited()) frontier.push(v);
				g.goto_next_edge();
			}
		}
	}

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
	typedef typename GraphNode<T>::Ref NodeRef;

	std::queue <NodeRef> frontier;
	NodeRef u, v;
	
	frontier.push(g.current_node());

	while (!frontier.empty()){
		u = frontier.front();
		frontier.pop();

		if (!u->is_visited()) {
			u->set_visited(true);
			ret_val = p.apply(u);
			g.goto_node(u);

			while (g.has_current_edge()) {
				v = g.current_edge()->other(u);
				if (!v->is_visited()) frontier.push(v);
				g.goto_next_edge();
			}
		}
	}

	return ret_val;
}

#endif // __GRAPH_TRAVERSALS_HPP
