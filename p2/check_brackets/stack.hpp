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
	Stack () {
		//TODO
		head_ = NULL;
		assert(this->is_empty());
	}

	/** @brief Destroy a Stack.**/
	~Stack()
	{
		//TODO
		delete head_;
	}

	/** @}*/

	/** @name Observers*/

	/** @{*/

	/** @brief is the list empty?.*/
	bool is_empty () const
	{
		//TODO
		return (head_ == NULL);
	}

	/** @brief get the top item.
	 * @pre not is_empty()
	 */
	const T& top() const
	{
		//TODO
		assert(!this->is_empty());
		return head_->value;
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
		nodo *new_nd;
		new_nd = new nodo;
		new_nd->value = new_it;
		if (this->is_empty()) {
			head_ = new_nd;
		} else {
			new_nd->next = head_;
			head_ = new_nd;
		}
		//delete new_nd;
		assert(top()==new_it);
	}

	/** Remove the top item.
	 * @pre not is_empty()
	 */
	void pop()
	{
		//TODO
		assert(!this->is_empty());
		nodo *aux = head_;
		head_ = head_->next;
		delete aux;
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
	struct nodo {
		T value;
		nodo *next;
	};

	nodo *head_;};

#endif
