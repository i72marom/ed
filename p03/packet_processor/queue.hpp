#ifndef __Queue_HPP__
#define __Queue_HPP__

#include <cassert>
#include <cstdlib>
#include <list>

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
		Queue () {
			//TODO
			assert(this->is_empty());
			// DONE
		}

		/** @brief Destroy a Queue.**/
		~Queue() {
			//TODO
			queue_.clear();
			// DONE
		}

		/** @}*/

		/** @name Observers*/

		/** @{*/

		/** @brief is the list empty?.*/
		bool is_empty () const {
			//TODO
			return queue_.empty();
			// DONE
		}

		/** @brief Gets the number of items in the queue.*/
		size_t size() const {
			//TODO
			
			return queue_.size();

			// DONE
		}

		/** @brief get the front item (the oldest one).
		 * @pre not is_empty()
		 */
		const T& front() const {
			//TODO
			return queue_.front();
			// DONE
		}

		/** @brief get the back item (the newest one).
		 * @pre not is_empty()
		 */
		const T& back() const {
			//TODO
			assert(!this->is_empty());
			return queue_.back();
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

			queue_.push_back(new_it);

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

			queue_.pop_front();

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
		std::list <T> queue_;
		// DONE
};

#endif
