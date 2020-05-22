#include "a_star_algorithm.hpp"
#include "maze_solver.hpp"

#include <stack>
#include <list>
#include <cmath>

/**
 * @brief Convert from vertex label to x,y coordinates.
 * @param v is the vertex label.
 * @param grid_width is the width of the grid.
 * @return a tuple <x,y>.
 */
static inline std::tuple<int, int>
label_to_grid_coord(size_t v, int grid_width) {
	//TODO
	return std::make_tuple(v % grid_width, v / grid_width);
	// DONE
}

/**
 * @brief Functional to compute the euclidean distance between graph vertices.
 */
struct Distance {
	size_t size_;

	Distance(size_t size) {
		//TODO
		size_t size_ = size;
		// DONE
	}

	float operator()(const WGraph<int>::NodeRef& a, const WGraph<int>::NodeRef& b) const {
		//TODO
		std::tuple <int, int> coord_a = label_to_grid_coord(a->label(), size_);
		std::tuple <int, int> coord_b = label_to_grid_coord(b->label(), size_);

		return sqrt(pow(std::get<0>(coord_b) - std::get<0>(coord_a), 2) + pow(std::get<1>(coord_b) - std::get<1>(coord_a), 2));
		// DONE
	}
};

void
maze_solver(WGraph<int>& maze, 
			WGraph<int>::NodeRef& start, 
			WGraph<int>::NodeRef& end, 
			const int grid_width, 
			std::vector<std::tuple<int, int> > &path) {
	
	std::vector<size_t> predecesors;
	std::vector<float> distances;

	//TODO
	//Call to a*  with the proper arguments.
	a_star_algorithm(maze, start, end, Distance(grid_width), predecesors, distances);

	//
	path.resize(0);

	if (end->is_visited()) {
		//If there is a path, save it into path vector.
		//Remenber: the result will be tuples <x,y> for 
		//the all the points in the path from start point to end point.

		//TODO
		size_t p = predecesors.back();
		std::list <std::tuple<int, int>> aux;
		aux.push_front(label_to_grid_coord(end->label(), grid_width));
		
		while (p != start->label()) {
			aux.push_front(label_to_grid_coord(p, grid_width));
			p = predecesors[p];
		}

		aux.push_front(label_to_grid_coord(start->label(), grid_width));
		path.assign(aux.begin(), aux.end());
	}
}
