#ifndef __Stack_HPP__
#define __Stack_HPP__

#include <cassert>
#include <vector>

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
		if (!list_.empty()) return false;
		return true;
	}

	/** @brief get the top item.
	 * @pre not is_empty()
	 */
	const T& top() const
	{
		//TODO
		return list_.back();
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
		list_.push_back(new_it);
	}

	/** Remove the top item.
	 * @pre not is_empty()
	 */
	void pop()
	{
		//TODO
		list_.pop_back();
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
	std::vector <T> list_;
};

#endif
