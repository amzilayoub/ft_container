# pragma once
# include "Node.hpp"
# include "ReverseIterator.hpp"
# include <limits>

namespace ft
{
template <typename T>
class ListIterator
{
	// Member type
	public:
		typedef T			value_type;
		typedef value_type*		pointer;
		typedef value_type const*	const_pointer;
		typedef value_type&		reference;
		typedef value_type const&	const_reference;
		typedef Node<value_type>	node_type;
		typedef node_type*		node_pointer;
		typedef std::ptrdiff_t		difference_type;

	//Attribute
	protected:
		node_pointer			node;

	//Constructors and Destructor
	public:
			ListIterator(void) : node(NULL) { }
			ListIterator(node_pointer &node) : node(node) { }
			ListIterator(ListIterator const &other) : node(other.node) { }
		virtual ~ListIterator() { }

	//Operators Overloading
	public:
		ListIterator &operator=(const ListIterator &other)
		{
			this->node = other.node;

			return (*this);
		}

		value_type &operator*()
		{
			return (this->node->getValue());
		}

		ListIterator &operator++()
		{
			this->node = this->node->getNext();
			return (*this);
		}

		ListIterator &operator++(int)
		{
			this->node = this->node->getNext();
			return (*this);
		}

		ListIterator &operator--()
		{
			this->node = this->node->getPrev();
			return (*this);
		}

		ListIterator &operator--(int)
		{
			this->node = this->node->getPrev();
			return (*this);
		}

		bool operator==(ListIterator const &other)
		{
			return ((this->node) == other.node);
		}

		bool operator!=(ListIterator const &other)
		{
			return ((this->node) != other.node);
		}

		bool operator<(ListIterator const &other)
		{
			return ((this->node) < other.node);
		}

		bool operator<=(ListIterator const &other)
		{
			return ((this->node) <= other.node);
		}

		bool operator>(ListIterator const &other)
		{
			return ((this->node) > other.node);
		}

		bool operator>=(ListIterator const &other)
		{
			return ((this->node) >= other.node);
		}

	// Getters
		node_pointer &getNode()
		{
			return (this->node);
		}
};

template<typename T>
class List
{
	// Member Type
	public:
		typedef T					value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef value_type&				reference;
		typedef value_type const&			const_reference;
		typedef value_type*				pointer;
		typedef value_type const*			const_pointer;
		typedef Node<T>					node_type;
		typedef node_type*				node_pointer;
		typedef ListIterator<value_type>		iterator;
		typedef ListIterator<value_type const>		const_iterator;
		typedef ReverseIterator<iterator>		reverse_iterator;
		typedef ReverseIterator<const_iterator>		const_reverse_iterator;

	//Member Attribute
	private:
		node_pointer	list_begin;
		node_pointer	list_end;
		size_type	list_size;

	public:
	// Constructors and Destructor
		List(void)
			: list_begin(nullptr), list_end(nullptr), list_size(0)
		{
			this->empty_node();
		}

		List(size_type n, const_reference val = value_type())
			: list_begin(nullptr), list_end(nullptr), list_size(0)
		{
			this->empty_node();
			this->assign(n, val);
		}

		List(List &other)
		{
			(*this) = (other);
		}

		virtual	~List(void)
		{
			// Destructor
			this->clear();
			delete this->list_end;
		}

		List &operator=(List &other)
		{
			this->clear();
			this->assign(other.begin(), other.end());

			return (*this);
		}

	// Iterators
		iterator begin()
		{
			return (iterator(this->list_begin));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->list_begin));
		}

		iterator end()
		{
			return (iterator(this->list_end));
		}

		const_iterator end() const
		{
			return (const_iterator(this->list_end));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->list_end->getPrev()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->list_end->getPrev()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->list_begin->getPrev()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->list_begin->getPrev()));
		}

	// Capacity Member Functions
		bool empty() const
		{
			return (this->list_size == 0);
		}

		size_type size() const
		{
			return (this->list_size);
		}

		size_type max_size() const
		{
			return (std::numeric_limits<difference_type>::max());
		}

	// Element access
		reference front()
		{
			return (this->list_begin->getValue());
		}

		const_reference front() const
		{
			return (this->list_begin->getValue());
		}

		reference back()
		{
			return (this->list_end->getPrev()->getValue());
		}

		const_reference back() const
		{
			return (this->list_end->getPrev()->getValue());
		}

	//Modifiers
		void assign(iterator begin, iterator end)
		{
			//clearing the list before assigning the new elements
			this->clear();
			while (begin != end)
			{
				this->push_back((*begin));
				begin++;
			}
		}

		void assign(size_type n, const_reference val)
		{
			//clearing the list before assigning the new elements
			this->clear();
			while (n-- > 0)
				this->push_back(val);
		}

		void	push_front(const_reference val)
		{
			node_pointer node = new node_type(val);
			this->list_begin->insert_before(node);
			this->list_begin = node;
			this->list_size++;
		}

		void	pop_front()
		{
			if (!this->list_size)
				return ;
			this->list_size--;
			node_pointer tmp = this->list_begin;
			this->list_begin = this->list_begin->getNext();
			this->list_begin->getPrev() = nullptr;
			delete tmp;
		}
		void	push_back(const_reference val)
		{
			node_pointer node = new node_type(val);
			this->list_end->insert_before(node);
			if (!this->list_size)
				this->list_begin = node;
			this->list_size++;
		}

		void	pop_back()
		{
			if (!this->list_size)
				return ;
			this->list_size--;
			node_pointer tmp = this->list_end;
			this->list_end = this->list_end->getPrev();
			this->list_end->getNext() = nullptr;
			delete tmp;
		}

		iterator insert(iterator position, const_reference val)
		{
			node_pointer node = new node_type(val);
			position.getNode()->insert_before(node);
			if (position == this->begin())
				this->list_begin = node;
			this->list_size++;
			return (--position);
		}

		void insert(iterator position, size_type n, const_reference val)
		{
			node_pointer	node = position.getNode();
			node_pointer	tmp;
			size_type 	i;

			i = 0;
			while (i++ < n)
			{
				this->list_size++;
				tmp = new node_type(val);
				if (i == 1 && position == this->begin())
					this->list_begin = tmp;
				node->insert_before(tmp);
			}
		}

		void insert (iterator position, iterator first, iterator last)
		{
			while (first != last)
			{
				this->insert(position, *first);
				first++;
			}
		}

		iterator erase(iterator position)
		{
			if (position == this->end())
				return (position);
			else if (position == this->begin())
				this->list_begin = this->list_begin->getNext();
			node_pointer tmp = position.getNode()->getNext();
			this->list_size--;
			position.getNode()->remove();
			return (iterator(tmp));
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = this->erase(first);
				if (first == this->end())
					return (first);
			}
			return (first);
		}

		void swap(List &other)
		{
			node_pointer tmp = other.list_begin;
			other.list_begin = this->list_begin;
			this->list_begin = tmp;

			tmp = other.list_end;
			other.list_end = this->list_end;
			this->list_end = tmp;

			size_type tmpSize = other.list_size;
			other.list_size = this->list_size;
			this->list_size = tmpSize;
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (this->list_size > n)
			{
				iterator it = this->begin();
				while (n-- > 0)
					it++;
				this->erase(it, this->end());
			}
			else if (this->list_size < n)
			{
				n -= this->list_size;
				while (n-- > 0)
					this->push_back(val);
			}
			else
				this->erase(this->begin(), this->end());
		}

		void clear()
		{
			this->erase(this->begin(), this->end());
			delete this->list_end;
			this->empty_node();
		}

	// Operations :
	void splice(iterator position, List &x)
	{
		List<value_type>::iterator it = x.begin();
		node_pointer tmp;
		while (it != x.end())
		{
			this->insert(position, (*it));
			it++;
		}
		x.clear();
	}

	void splice(iterator position, List &x, iterator i)
	{
		if (x.end() == i)
			return ;
		this->insert(position, (*i));
		x.erase(i);
	}

	void splice(iterator position, List &x, iterator first, iterator last)
	{
		iterator tmp = first;
		while (first != last)
		{
			if (first == x.end())
				return ;
			this->insert(position, (*first));
			first++;
		}
		x.erase(tmp, last);
	}

	void remove(const_reference val)
	{
		iterator it = this->begin();

		while (it != this->end())
		{
			if ((*it) == val)
				it = this->erase(it);
			else
				it++;
		}
	}

	template <class Predicate>
	void remove_if (Predicate pred)
	{
		iterator it = this->begin();
		while (it != this->end())
		{
			if ((*pred)((*it)))
				it = this->erase(it);
			else
				it++;
		}
	}

	void unique()
	{
		iterator i = this->begin();
		iterator j;

		while (i != this->end())
		{
			j = i;
			++j;
			while (j != this->end())
			{
				if ((*i) == (*j))
					j = this->erase(j);
				else
					++j;
			}
			++i;
		}
	}

	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred)
	{
		iterator i = this->begin();
		iterator j;

		while (i != this->end())
		{
			j = i;
			++j;
			while (j != this->end())
			{
				if ((*binary_pred)((*i), (*j)))
					j = this->erase(j);
				else
					++j;
			}
			++i;
		}
	}

	void merge(List &x)
	{
		iterator itThis = this->begin();
		iterator itX = x.begin();
		iterator endThis = this->end();
		iterator endX = x.end();

		while (itThis != endThis && itX != endX)
		{
			if ((*itThis) >= (*itX))
			{
				this->insert(itThis, (*itX));
				itX++;
			} else if ((*itThis) < (*itX))
			{
				itThis++;
			}
		}
		if (itX != this->end())
			this->insert(itThis, itX, x.end());
		x.clear();
	}

	template <class Compare>
	void merge (List &x, Compare comp)
	{
		iterator itThis = this->begin();
		iterator itX = x.begin();

		while (itThis != this->end() && itX != this->end())
		{
			if ((*comp)((*itThis), (*itX)))
			{
				this->insert(itThis, (*itX));
				itX++;
			} else if ((*itThis) < (*itX))
			{
				itThis++;
			}
		}
		if (itX != this->end())
			this->insert(itThis, itX, x.end());
		x.clear();
	}

	void sort()
	{
		if (this->size() == 1)
			return ;
		List<value_type> *tmp = (this->sort_helper(this));
		(*this) = (*tmp);
		delete tmp;
	}

	template <class Compare>
	void sort (Compare comp)
	{
		if (this->size() == 1)
			return ;
		List<value_type> *tmp = (this->sort_helper(this, comp));
		(*this) = (*tmp);
		delete tmp;
	}

	void reverse()
	{
		this->list_begin->reverse(this->list_begin);
		node_pointer tmp = this->list_begin;
		this->list_begin = this->list_end->getNext();
		this->list_end->disconnect();
		tmp->insert_after(this->list_end);
	}

	// Helper functions
	private:
		void	empty_node()
		{
			this->list_begin = new node_type();
			this->list_end = this->list_begin;
			this->list_begin->getNext() = nullptr;
			this->list_begin->getPrev() = nullptr;
		}

		List	*sort_helper(List *x)
		{
			// there is a leak here
			if (x->size() == 1)
				return (x);
			List<value_type>	*left = new List<value_type>();
			List<value_type>	*right = new List<value_type>();
			size_type		i;
			iterator		it;

			i = 0;
			it = x->begin();
			while (i++ < x->size() / 2)
				it++;
			left->assign(x->begin(), it);
			right->assign(it, x->end());

			left = sort_helper(left);
			right = sort_helper(right);

			left->merge((*right));
			//delete left;
			delete right;
			return (left);
		}

		template <class Compare>
		List *sort_helper(List *x, Compare comp)
		{
			// there is a leak here
			if (x->size() == 1)
				return (x);
			List<value_type>	*left = new List<value_type>();
			List<value_type>	*right = new List<value_type>();
			size_type		i;
			iterator		it;

			i = 0;
			it = x->begin();
			while (i++ < x->size() / 2)
				it++;
			left->assign(x->begin(), it);
			right->assign(it, x->end());

			left = sort_helper(left);
			right = sort_helper(right);

			left->merge((*right));
			//delete left;
			delete right;
			return (left);
		}
};

template<class T>
bool operator==(List<T> &x, List<T> &y)
{
	if (x.size() != y.size())
		return (false);

	typename ft::List<T>::iterator it1 = x.begin();
	typename ft::List<T>::iterator it2 = y.begin();
	while (it1 != x.end() && it2 != y.end())
	{
		if ((*it1) != (*it2))
			return (false);
		++it1;
		++it2;
	}
	return (true);
}

template<class T>
bool operator!=(List<T> &x, List<T> &y)
{
	return (!(x == y));
}

template<class T>
bool operator<(List<T> &x, List<T> &y)
{
	typename ft::List<T>::iterator it1 = x.begin();
	typename ft::List<T>::iterator it2 = y.begin();
	while (it1 != x.end() && it2 != y.end())
	{
		if ((*it1) < (*it2))
			return (true);
		++it1;
		++it2;
	}
	return (false);
}

template<class T>
bool operator<=(List<T> &x, List<T> &y)
{
	typename ft::List<T>::iterator it1 = x.begin();
	typename ft::List<T>::iterator it2 = y.begin();
	while (it1 != x.end() && it2 != y.end())
	{
		if ((*it1) <= (*it2))
			return (true);
		++it1;
		++it2;
	}
	return (false);
}

template<class T>
bool operator>(List<T> &x, List<T> &y)
{
	typename ft::List<T>::iterator it1 = x.begin();
	typename ft::List<T>::iterator it2 = y.begin();
	while (it1 != x.end() && it2 != y.end())
	{
		if ((*it1) > (*it2))
			return (true);
		++it1;
		++it2;
	}
	return (false);
}

template<class T>
bool operator>=(List<T> &x, List<T> &y)
{
	typename ft::List<T>::iterator it1 = x.begin();
	typename ft::List<T>::iterator it2 = y.begin();
	while (it1 != x.end() && it2 != y.end())
	{
		if ((*it1) >= (*it2))
			return (true);
		++it1;
		++it2;
	}
	return (false);
}

template<class T>
void swap(List<T> &x, List<T> &y)
{
	x.swap(y);
}
}
