#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>
#include "heap.hpp"

/**
 * @brief Sort an array of values using a heap.
 * You can use std::less_equal to get a greater to lesser order.
 * You can use std::greater_equal to get a less to greater order.
 */
template<class T, class Comp>
void
heapsort(std::vector<T>& values, Comp const& comparison_fn_t = Comp())
{
    //TODO (try an O(N Log(N)) implementation.
    //May be you will need configure the proyect with
    //    cmake -DCMAKE_BUILT_TYPE=Release ..
    //to run the tests in time.
}

#endif // HEAPSORT_HPP
