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
	}

	/** @brief Destroy a Stack.**/
	~Stack()
	{
		//TODO
	}

	/** @}*/

	/** @name Observers*/

	/** @{*/

	/** @brief is the list empty?.*/
	bool is_empty () const
	{
		//TODO
		return (index_top_ == -1);
	}

	/** @brief get the top item.
	 * @pre not is_empty()
	 */
	const T& top() const
	{
		//TODO
		assert(!this->is_empty());
		return v_[index_top_];
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
		v_[++index_top_] = new_it;
	}

	/** Remove the top item.
	 * @pre not is_empty()
	 */
	void pop()
	{
		//TODO
		assert(!this->is_empty());
		index_top_--;
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
	T v_[100];
	int index_top_ = -1;
};

#endif
