# pragma once

template <typename It>
class ReverseIterator : public It
{
	//Member Type
	using typename It::value_type;
	using typename It::node_pointer;

	//Constructors and Destructor
	public:
		ReverseIterator(void) : It() { }
		ReverseIterator(node_pointer &node) : It(node) { }
		ReverseIterator(ReverseIterator const &other) : It(other) { }
		~ReverseIterator() { }

	//Operators Overloading
	public:
		ReverseIterator &operator=(const ReverseIterator &other)
		{
			this->node = other.node;
			return (*this);
		}

		value_type operator*()
		{
			return (this->node->getValue());
		}

		It &operator++()
		{
			return (this->It::operator--());
		}

		It &operator++(int)
		{
			return (this->It::operator--());
		}

		It &operator--()
		{
			return (this->It::operator++());
		}

		It &operator--(int)
		{
			return (this->It::operator++());
		}
};
