#ifndef __Stack_HPP__
#define __Stack_HPP__

#include <cassert>

/**
 * @brief ADT Stack.
 * Models a Single linked list[T].
 */
template<class T>
class Stack
{
	public:

	/** @name Life cicle.*/
	/** @{*/

	/** @brief Create an empty Stack.
	 * @post is_empty()
	 */
	Stack ()
	{
		//TODO
		assert(this->is_empty());
		// DONE
	}

	/** @brief Destroy a Stack.**/
	~Stack()
	{
		//TODO
		// DONE
	}

	/** @}*/

	/** @name Observers*/

	/** @{*/

	/** @brief is the list empty?.*/
	bool is_empty () const
	{
		//TODO
		return (index_top_ == -1);
		// DONE
	}

	/** @brief get the top item.
	 * @pre not is_empty()
	 */
	const T& top() const
	{
		//TODO
		assert(!this->is_empty());
		return v_[index_top_];
		// DONE
	}

	/**@}*/

	/** @name Modifiers*/

	/** @{*/

	/** @brief Insert a new item.
	 * @post top() == new_it
	 */
	void push(const T& new_it)
	{
		//TODO
		assert(index_top_ < 99999);
		v_[++index_top_] = new_it;
		// DONE
	}

	/** Remove the top item.
	 * @pre not is_empty()
	 */
	void pop()
	{
		//TODO
		assert(!this->is_empty());
		index_top_--;
		// DONE
	}

	/** @} */

private:

	/** @brief Copy constructor.
	 * @warning we don't want a copy constructor.
	 */
	Stack(const Stack<T>& other)
	{}

	/** @brief Assign operator.
	 * @warning we don't want the assign operator.
	 */
	Stack<T>& operator=(const Stack<T>& other)
	{
		return *this;
	}

protected:

	//TODO
	T v_[100000];
	int index_top_ = -1;
	// DONE
};

#endif
