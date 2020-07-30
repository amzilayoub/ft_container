# pragma once
# include "ReverseIterator.hpp"
# include <limits>
# include <stdlib.h>
# include <stdexcept>
# include <iostream>
# define ARRAY_STRETCH 10

namespace ft
{
template <typename T>
class VectorIterator
{
	// Member type
	public:
		typedef T			value_type;
		typedef value_type*		pointer;
		typedef value_type const*	const_pointer;
		typedef value_type&		reference;
		typedef value_type const&	const_reference;
		typedef std::ptrdiff_t		difference_type;

	//Attribute
	protected:
		pointer				array;

	//Constructors and Destructor
	public:
			VectorIterator(void) : array(NULL) { }
			VectorIterator(pointer &array) : array(array) { }
			VectorIterator(pointer const &array) : array(array) { }
			VectorIterator(VectorIterator const &other) : array(other.array) { }
		virtual ~VectorIterator() { }

	//Operators Overloading
	public:
		VectorIterator &operator=(const VectorIterator &other)
		{
			this->array = other.array;

			return (*this);
		}

		reference operator*()
		{
			return ((*this->array));
		}

		const_reference operator*() const
		{
			return ((*this->array));
		}

		VectorIterator &operator++()
		{
			++this->array;
			return (*this);
		}

		VectorIterator operator++(int)
		{
			VectorIterator tmp(*this);
			++this->array;
			return (tmp);
		}

		pointer operator->()
		{
			return (this->array);
		}

		const_pointer operator->() const
		{
			return (this->array);
		}

		reference operator[](int index)
		{
			return (this->array[index]);
		}

		const_reference operator[](int index) const
		{
			return (this->array[index]);
		}

		VectorIterator operator+(int val) const
		{
			VectorIterator tmp(*this);
			return (tmp.getArray() + val);
		}

		VectorIterator operator-(int val) const
		{
			VectorIterator tmp(*this);
			return (tmp.getArray() - val);
		}

		difference_type operator-(VectorIterator const &it) const
		{
			VectorIterator tmp(*this);
			return (tmp.array - it.array);
		}

		VectorIterator &operator--()
		{
			--this->array;
			return (*this);
		}

		VectorIterator operator--(int)
		{
			VectorIterator tmp(*tmp);
			--this->array;
			return (tmp);
		}

		bool operator==(VectorIterator const &other) const
		{
			return ((this->array) == other.array);
		}

		bool operator!=(VectorIterator const &other) const
		{
			return ((this->array) != other.array);
		}

		bool operator<(VectorIterator const &other) const
		{
			return ((this->array) < other.array);
		}

		bool operator<=(VectorIterator const &other) const
		{
			return ((this->array) <= other.array);
		}

		bool operator>(VectorIterator const &other) const
		{
			return ((this->array) > other.array);
		}

		bool operator>=(VectorIterator const &other) const
		{
			return ((this->array) >= other.array);
		}

	// Getters
		pointer &getArray()
		{
			return (this->array);
		}
};

template<typename T>
class Vector
{
	// Member Type
	public:
		typedef T					value_type;
		typedef value_type&				reference;
		typedef value_type const&			const_reference;
		typedef value_type*				pointer;
		typedef value_type const*			const_pointer;
		typedef VectorIterator<value_type>		iterator;
		typedef VectorIterator<value_type> const	const_iterator;
		typedef ReverseIterator<iterator>		reverse_iterator;
		typedef ReverseIterator<const_iterator>		const_reverse_iterator;
		typedef std::ptrdiff_t				difference_type;
		typedef std::size_t				size_type;

	//Member Attribute
	private:
		pointer		array;
		size_type	array_capacity;
		size_type	array_size;

	public:
	// Constructors and Destructor
		Vector(void) :array(NULL), array_capacity(0), array_size(0) {}

		Vector(size_type n, const value_type& val = value_type())
			:array(NULL), array_capacity(0), array_size(0)
		{
			this->assign(n, val);
		}

		Vector (iterator first, iterator last)
			:array(NULL), array_capacity(0), array_size(0)
		{
			this->assign(first, last);
		}

		Vector(Vector const &x)
			:array(NULL), array_capacity(0), array_size(0)
		{
			this->assign(x.begin(), x.end());
		}

		~Vector()
		{
			this->erase(this->begin(), this->end());
			delete this->array;
			this->array_size = 0;
			this->array_capacity = 0;
			this->array = NULL;
		}

		Vector &operator=(Vector const &x)
		{
			this->erase(this->begin(), this->end());
			this->assign(x.begin(), x.end());

			return ((*this));
		}

	// Iterators
		iterator begin()
		{
			return (iterator(this->array));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->array));
		}

		iterator end()
		{
			return (iterator(&this->array[this->array_size]));
		}

		const_iterator end() const
		{
			return (const_iterator(&this->array[this->array_size]));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(&this->array[this->array_size]));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(&this->array[this->array_size]));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->array));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->array));
		}

	// Capacity Member Functions
		size_type size() const
		{
			return (this->array_size);
		}

		size_type max_size() const
		{
			return (std::numeric_limits<difference_type>::max());
		}

		void resize(size_type n, value_type val = value_type())
		{
			this->reserve(n);
			if (n < this->array_size)
			{
				while (this->array_size != n)
				{
					this->array[--this->array_size].value_type::~value_type();
					this->array[this->array_size] = static_cast<value_type>(NULL);
				}
			} else if (n > this->array_size)
			{
				while (this->array_size != n)
					new (&this->array[this->array_size++]) value_type(val);
			}
		}

		size_type capacity() const
		{
			return (this->array_capacity);
		}

		bool empty() const
		{
			return (this->array_size == 0);
		}

		void reserve(size_type n)
		{
			if (this->array_capacity == 0)
			{
				n = (n > ARRAY_STRETCH) ? n : ARRAY_STRETCH;
				this->array = new value_type[n];
				this->array_capacity = n;
			} else if (this->array_capacity < n)
			{
				pointer tmp = new value_type[n + ARRAY_STRETCH];
				int	i = -1;
				while (++i < this->array_capacity)
					new(tmp + i) value_type(this->array[i]);
				delete this->array;
				this->array = tmp;
				this->array_capacity = n + ARRAY_STRETCH;
				//this->array_size = n;
			}
		}

	// Element access
		reference operator[] (size_type n)
		{
			return (this->array[n]);
		}

		const_reference operator[] (size_type n) const
		{
			return (this->array[n]);
		}

		reference at (size_type n)
		{
			if (n >= this->array_size)
				throw std::out_of_range("Out of Range !");
			return (this->array[n]);
		}

		const_reference at (size_type n) const
		{
			if (n >= this->array_size)
				throw std::out_of_range("Out of Range !");
			return (this->array[n]);
		}

		reference front()
		{
			return ((*this->array));
		}

		const_reference front() const
		{
			return ((*this->array));
		}

		reference back()
		{
			return (this->array[this->array_size - 1]);
		}

		const_reference back() const
		{
			return (this->array[this->array_size - 1]);
		}

	//Modifiers
		void assign (iterator first, iterator last)
		{
			difference_type res = last - first;
			size_type	i = 0;
			this->reserve(res);
			while (first != last)
			{
				if (i >= this->array_size)
					new(&this->array[i]) value_type(*first);
				else
					this->array[i] = (*first);
				++first;
				++i;
			}
			if (i > this->array_size)
				this->array_size = i;
		}

		void assign (size_type n, const value_type& val)
		{
			this->reserve(n);
			size_type i = 0;

			while (i < n)
			{
				if (i >= this->array_size)
					new(&this->array[i++]) value_type(val);
				else
					this->array[i++] = val;
			}
			if (i > this->array_size)
				this->array_size = i;
		}

		void push_back(const value_type& val)
		{
			if (this->array_capacity <= this->array_size)
				this->reserve(this->array_capacity + 1);
			this->array[this->array_size] = val;
			this->array_size++;
		}

		void pop_back()
		{
			if (this->array_capacity == 0)
				return ;
			this->array[--this->array_size].value_type::~value_type();
			this->array[this->array_size] = static_cast<value_type>(NULL);
		}
		//INSERT
		iterator insert(iterator position, const value_type& val)
		{
			size_type j = this->array_capacity;
			while (position.getArray() != (&this->array[j]) && j != 0)
				--j;
			if (this->array_size >= this->array_capacity)
				this->resize(this->array_capacity + 1);
			size_type i = this->array_capacity;
			while (j < i)
			{
				this->array[i] = this->array[i - 1];
				--i;
			}
			this->array[i] = val;
			this->array_size = 1 + ((i > this->array_size) ? i : this->array_size);
			return (iterator(&this->array[i]));
		}

		// Not finished yet
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type j = this->array_capacity;
			while (position.getArray() != (&this->array[j]) && j != 0)
				--j;
			if (j + n >= this->array_capacity)
				this->reserve(j + n);
			else if (this->array_size + n >= this->array_capacity)
				this->reserve(this->array_size + n);
			size_type lastIndex = this->array_size + n;
			size_type curIndex = this->array_size;
			while (j <= curIndex)
			{
				this->array[lastIndex] = this->array[curIndex];
				if (curIndex == j)
					break;
				--lastIndex;
				--curIndex;
			}
			while (j < lastIndex)
			{
				this->array[j] = val;
				++j;
			}
			this->array_size += n;
		}

		void insert (iterator position, iterator first, iterator last)
		{
			difference_type n = (last - first);
			size_type j = this->array_capacity;
			while (position.getArray() != (&this->array[j]) && j != 0)
				--j;
			if (j + n >= this->array_capacity)
				this->reserve(j + n);
			else if (this->array_size + n >= this->array_capacity)
				this->reserve(this->array_size + n);
			size_type lastIndex = this->array_size + n;
			size_type curIndex = this->array_size;
			while (j <= curIndex)
			{
				this->array[lastIndex] = this->array[curIndex];
				if (curIndex == j)
					break;
				--lastIndex;
				--curIndex;
			}
			while (first != last)
			{
				this->array[j] = (*first);
				++first;
				++j;
			}
			this->array_size += n;
		}

		iterator erase (iterator position)
		{
		/*
			iterator itEnd = iterator(&this->array[this->size()]);
			iterator ret = position;
			while (position != itEnd && position != this->end())
			{
				(*position).value_type::~value_type();
				(*position) = (*(position + 1));
				++position;
			}
			this->array_size--;
			return (ret);
		*/
			return (this->erase(position, position + 1));
		}

		iterator erase (iterator first, iterator last)
		{
			iterator it = first;
			while (first != last)
			{
				(*first).value_type::~value_type();
				(*first) = static_cast<value_type>(NULL);
				++first;
				--this->array_size;
			}
			while (it != this->end() && last != this->end())
			{
				(*it) = (*last);
				(*last).value_type::~value_type();
				(*last) = static_cast<value_type>(NULL);
				++it;
				++last;
			}
			return (first);
		}
 
		void swap (Vector &x)
		{
			Vector<value_type> tmp;

			tmp = (*this);
			(*this) = x;
			x = tmp;
		}

		void clear()
		{
			this->erase(this->begin(), this->end());
		}
};

template<class T>
bool operator==(Vector<T> const &lhs, Vector<T> const &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename Vector<T>::iterator leftIt = lhs.begin();
	typename Vector<T>::iterator rightIt = rhs.begin();
	for (; leftIt < lhs.end(); leftIt++, rightIt++)
	{
		if ((*leftIt) != (*rightIt))
			return (false);
	}
	return (true);
}

template<class T>
bool operator<(Vector<T> const &lhs, Vector<T> const &rhs)
{
	typename Vector<T>::iterator leftIt = lhs.begin();
	typename Vector<T>::iterator rightIt = rhs.begin();
	for (; leftIt != lhs.end() && rightIt != rhs.end(); leftIt++, rightIt++)
	{
		if ((*leftIt) < (*rightIt))
			return (true);
	}
	return (false);
}

template<class T>
bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (!(rhs < lhs));
}

template<class T>
bool operator>(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (rhs < lhs);
}

template<class T>
bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (!(lhs < rhs));
}

template<class T>
void swap(Vector<T> &x, Vector<T> &y)
{
	x.swap(y);
}
}
