# pragma once
# include <iostream>

template <typename T>
class Node
{
	//Member attribut
	private:
		T		value;
		Node<T>		*prev;
		Node<T>		*next;

	//Constructors & Destructor
	public:
		Node(void) : prev(nullptr), next(nullptr) { }
		Node(T const &value) : prev(nullptr),value(value), next(nullptr) { }
		Node(Node<T> *prev, T const &value, Node<T> *next = nullptr) : prev(prev),value(value), next(next) { }
		Node(const Node<T> &other)
		{
			(*this) = other;
		}

		~Node(void) { }

	//Operators overload
	public:
		Node &operator=(const Node &other)
		{
			this->value = other.value;
			this->next = other.next;
			this->prev = other.prev;

			return (*this);
		}

/*
		bool operator==(Node *other)
		{
			Node<T> *node1;
			Node<T> *node2;

			if ((sizeof node1) != (sizeof node2))
				return (false);
			node1 = (this);
			node2 = other;
			while (node1 != nullptr && node2 != nullptr)
			{
				if ((node1->value != node2->value))
					return (false);
				node1 = node1->next;
				node2 = node2->next;
			}
			return ((node1 == nullptr && node2 == nullptr) ? true : false);
		}

		bool operator!=(Node *other)
		{
			return (!((*this) == (other)));
		}

		bool operator<(Node *other)
		{
			Node<T> *node1;
			Node<T> *node2;

			node1 = (this);
			node2 = other;
			while (node1 != nullptr && node2 != nullptr)
			{
				if ((node1->value < node2->value))
					return (true);
				node1 = node1->next;
				node2 = node2->next;
			}
			return (false);
		}

		bool operator<=(Node *other)
		{
			Node<T> *node1;
			Node<T> *node2;

			node1 = (this);
			node2 = other;
			while (node1 != nullptr && node2 != nullptr)
			{
				if ((node1->value <= node2->value))
					return (true);
				node1 = node1->next;
				node2 = node2->next;
			}
			return (false);
		}

		bool operator>(Node *other)
		{
			Node<T> *node1;
			Node<T> *node2;

			node1 = (this);
			node2 = other;
			while (node1 != nullptr && node2 != nullptr)
			{
				if ((node1->value > node2->value))
					return (true);
				node1 = node1->next;
				node2 = node2->next;
			}
			return (false);
		}

		bool operator>=(Node *other)
		{
			Node<T> *node1;
			Node<T> *node2;

			node1 = (this);
			node2 = other;
			while (node1 != nullptr && node2 != nullptr)
			{
				if ((node1->value >= node2->value))
					return (true);
				node1 = node1->next;
				node2 = node2->next;
			}
			return (false);
		}
*/


	//Getters
	public:
		T	&getValue(void)
		{
			return (this->value);
		}

		Node	*&getNext(void)
		{
			return (this->next);
		}

		Node	*&getPrev(void)
		{
			return (this->prev);
		}

	// Member Functions
	public:
		void	insert_before(Node *node)
		{
			if (this->prev)
			{
				node->prev = this->prev;
				this->prev->next = node;
			}
			this->prev = node;
			node->next = this;
		}

		void	insert_after(Node *node)
		{
			if (this->next)
			{
				node->next = this->next;
				this->next->prev = node;
			}
			this->next = node;
			node->prev = this;
		}

		void	remove(void)
		{
			if (this->next == nullptr)
			{
				Node<T> *tmp = this;
				(*this) = (*this->prev);
				this->next = nullptr;
				delete tmp;
			}
			else if (this->prev == nullptr)
			{
				Node<T> *tmp = this;
				(*this) = (*this->next);
				this->prev = nullptr;
				delete tmp;
			}
			else
			{
				this->prev->next = this->next;
				this->next->prev = this->prev;
				delete this;
			}
		}

		void reverse(Node<T> *node)
		{
			if (node == nullptr)
				return ;
			this->reverse(node->next);
			//std::cout << "REV = " << node->value << std::endl;
			Node<T> *tmp = node->prev;
			node->prev = node->next;
			node->next = tmp;
			//node->prev->prev = node;
		}

		void disconnect()
		{
			if (this->next == nullptr)
			{
				this->prev->next = nullptr;
				this->prev = nullptr;
			}
			else if (this->prev == nullptr)
			{
				this->next->prev = nullptr;
				this->next = nullptr;
			}
			else
			{
				this->prev->next = this->next;
				this->next->prev = this->prev;
			}
		}

};
