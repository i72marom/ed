#ifndef __HASH_TABLE__
#define __HASH_TABLE__
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cassert>

#include <vector>
#include <list>
#include <utility>
#include <memory>

using namespace std;

/**
 * @brief Implement the HashTable[K,V] ADT.
 * The template parameter keyToInt is a functional to transform
 * values of type K into size_t. It must be implement the interface:
 *    size_t operator()(K const&k)
 */
template<class K, class V, class keyToInt>
class HashTable
{
public:
	/** @name Life cicle.*/
	/** @{*/

	/**
	  * @brief Create a new HashTable.
	  * @post is_empty()
	  * @post not is_valid()
	  */
	HashTable(size_t m, uint64_t a=32, uint64_t b=3, uint64_t p=4294967311l, keyToInt key_to_int=keyToInt()) :
			size_(m), a_(a), b_(b), p_(p) {
		//TODO
		hash_table_.resize(m);
		valid_keys_ = 0;
		current_.pos = 0;
		current_.it = hash_table_[0].begin();
		assert(is_empty());
		assert(!is_valid());
		// DONE
	}
	/** @}*/

	/** @name Observers*/
	/** @{*/

	/**
	 * @brief Is the table empty?
	 * @return true if it is empty.
	 */
	bool is_empty() {
		//TODO
		//for (size_t i = 0; i < size_; ++i)
		//	if (!hash_table_[i].empty()) return false;

		return num_of_valid_keys() == 0;
		// DONE
	}

	/**
	 * @brief is the cursor at a valid position?
	 * @return true if the cursor is at a valid position.
	 */
	bool is_valid() const {
		//TODO
		return (!hash_table_[current_.pos].empty() &&
				current_.pos < size_ &&
				current_.it != hash_table_[current_.pos].end()); 
		// DONE
	}

	/**
	 * @brief Get the number of valid keys in the table.
	 * @return the number of valid keys in the table.
	 */
	size_t num_of_valid_keys() const {
		//TODO
		return valid_keys_;
		// DONE
	}

	/**
	 * @brief Compute the load factor of the table.
	 * @return the load factor of the table.
	 */
	float load_factor() const {
		//TODO
		return num_of_valid_keys()/size_;
		// DONE
	}

	/**
	 * @brief Has the table this key?
	 * @param k the key to find.
	 * @return true if the key is saved into the table.
	 * @warning The cursor is not affected by this operation.
	 */
	bool has(K const& k) const {
		//TODO
		//You can use find() but
		//you must remenber to restore the cursor at the end.

		size_t h = hash(keyToInt()(k));

		if (!hash_table_[h].empty()) {
			for (auto it = hash_table_[h].cbegin(); it != hash_table_[h].cend(); ++it) {
				if (it->first == k) return true;
			}
		}

		return false;
		// DONE
	}


	/**
	 * @brief Get the key at cursor.
	 * @return return the key of the cursor.
	 */
	K const& get_key() const {
		assert(is_valid());
		//TODO
		return current_.it->first;
		// DONE
	}

	/**
	 * @brief Get tha value at cursor.
	 * @return return the value of the cursor.
	 */
	V const& get_value() const {
		assert(is_valid());
		//TODO
		return current_.it->second;
		// DONE
	}

	/**
	 * @brief hash a key value k.
	 * @return h = ((int(k)*a + b) % p) % m
	 */
	size_t hash(uint64_t k) const {
		//TODO
		return ((k*a_ + b_) % p_) % size_;
		// DONE
	}

	/** @}*/

	/** @name Modifiers*/
	/** @{*/

	/**
	 * @brief Find a key value.
	 * @return true if the key is found.
	 * @post !is_valid() or get_key()==k
	 */
	bool find(K const& k) {        
		bool is_found=false;

		//TODO
		//1. hash the key to get the table entry.
		size_t h = hash(keyToInt()(k));
		
		//2. Is the table entry empty
		//2.1 yes, not found
		//2.2 else find into the chain (list) of the entry.
		// !!Remenber to update the cursor state.

		auto it = hash_table_[h].begin();

		if (!hash_table_[h].empty()) {
			while (it != hash_table_[h].end()) {
				if (it->first == k) {
					is_found = true;
					break;
				} else it++;
			}
		}

		current_.pos = h;
		current_.it = it;

		return is_found;
		// DONE
	}

	/**
	 * @brief insert a new entry.
	 * If the key is currently in the table, the value is updated.
	 * @post is_valid()
	 * @post get_key()==k
	 * @post get_value()==v;
	 * @post not old(has(k)) -> num_of_valid_keys() = old(num_of_valid_keys())+1
	 */
	void insert(K const& k, V const& v)
	{
#ifndef NDEBUG //In Relase mode this macro is defined.
		bool old_has = has(k);
		size_t old_num_of_valid_keys = num_of_valid_keys();
#endif
		//TODO
		//1. find the key.
		//2.1 if it is found, reset the value part.
		//2.2 else, add the new pair (key,value) to the entry chain.
		//Remenber to update the cursor state and the valid keys counter.

		if (find(k)) set_value(v);
		else {
			size_t h = hash(keyToInt()(k));
			hash_table_[h].push_front(pair<K,V>(k,v));
			current_.pos = h;
			current_.it = hash_table_[h].begin();
			valid_keys_++;
		}

		if (load_factor() > 0.9) rehash();

		assert(is_valid());
		assert(get_key()==k);
		assert(get_value()==v);
		assert(old_has || (num_of_valid_keys()==old_num_of_valid_keys+1));
	}

	/**
	 * @brief remove the entry at the cursor position.
	 * The cursor will be move to the next valid position if there is.
	 * @pre is_valid()
	 * @post !is_valid() || old(goto_next() && get_key())==get_key()
	 * @post num_of_valid_keys() = old(num_of_valid_keys())-1
	 */
	void remove()
	{
		assert(is_valid());
#ifndef NDEBUG //In Relase mode this macro is defined.
		size_t old_n_valid_keys = num_of_valid_keys();
#endif        

		//TODO
		//First save the current cursor state.
		auto it = current_.it;
		size_t i = current_.pos;
		//

		goto_next(); //move the cursor to next position.
		  
		//TODO
		//Second, remove the old cursor position.
		hash_table_[i].erase(it);
		valid_keys_--;
		//
		
		assert( (num_of_valid_keys()+1)==old_n_valid_keys );
		return;
	}

	/**
	 * @brief set the value of the entry at the cursor position.
	 */
	void set_value(const V& v) {
		assert(is_valid());
		//TODO
		current_.it->second = v;
		// DONE
	}

	/**
	 * @brief rehash the table to double size.
	 * @warning A new hash function is random selected.
	 * @post old.is_valid() implies is_valid() && old.get_key()==get_key() && old.get_value()==get_value()
	 */
	void rehash()
	{
#ifndef NDEBUG  //In Relase mode this macro is defined.
		bool old_is_valid = is_valid();
		K old_key;
		V old_value;
		if (old_is_valid)
		{
			old_key = get_key();
			old_value = get_value();
		}
#endif
		//1. Save the state of the cursor.
		K aux = current_.it->first;
		
		//2. Pick up at random a new h.
		uint64_t P = p_;/*TODO use here the coefficiente P used for the hash function.*/ 
		const uint64_t a = 1 + static_cast<uint64_t>(rand()/(RAND_MAX+1.0) * static_cast<double>(P-1));
		const uint64_t b = static_cast<uint64_t>(rand()/(RAND_MAX+1.0) * static_cast<double>(P));

		//3. Create a new table with double size with the new hash.
		size_t M = size_; /*TODO use the current table size.*/ 
		HashTable<K, V, keyToInt> new_table (M*2, a, b);

		//TODO
		//4. Traversal the old table inserting the values into the new.
		//4.1 goto to the first entry.
		//4.2 while isValid() do
		//4.3    insert in new table current pair key,value
		//4.4    goto next entry.
		goto_begin();

		while (is_valid()) {
			new_table.insert(current_.it->first, current_.it->second);
			goto_next();
		}

		//TODO
		//5 commute the new_table with this.
		//THIS DEPENDS ON YOUR IMPLEMENTATION.
		//CHECK CAREFULY IF YOU NEED OR NOT TO
		//OVERLOAD THE ASSIGN OPERATOR.
		*this = new_table;

		//TODO
		//6. Before returning, the cursor must be restored
		//to the same state that old state.
		//
		find(aux);

		//post condition
		assert(!old_is_valid || (is_valid() && old_key==get_key() && old_value==get_value()));
	}

	/**
	 * @brief move the cursor to the first valid entry.
	 * @post is_empty() || is_valid()
	 */
	void goto_begin() {
		//TODO
		bool not_found = true;
		current_.pos = 0;

		while (not_found && current_.pos < size_) {
			if (!hash_table_[current_.pos].empty()) {
				current_.it = hash_table_[current_.pos].begin();
				not_found = false;
			} else current_.pos++;
		}

		assert(is_empty() || is_valid());
		// DONE
	}

	/**
	 * @brief Move the cursor to next valid position.
	 * @post not is_valid() marks none any more valid entry exists.
	 */
	void goto_next() {
		assert(is_valid());
		//TODO
		current_.it++;

		while (!is_valid() && current_.pos < size_) {
			if (current_.it == hash_table_[current_.pos].end()) {
				current_.pos++;
				current_.it = hash_table_[current_.pos].begin();
			} 

			else current_.it++;
		}
		// DONE
		
	}
	/** @} */

protected:

	//TODO
	//Care must be taken about the type of the attributes.
	//It is recommended to use types that not imply to overload
	//the assign operator used in the rehash method.

	struct Current {
		size_t pos;
		typename list <pair <K,V>>::iterator it;
	};

	size_t size_;
	vector<list <pair <K,V>>> hash_table_;
	uint64_t a_, b_, p_;
	size_t valid_keys_;
	Current current_;

	// DONE
};

#endif
