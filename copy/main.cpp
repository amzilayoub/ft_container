#include <iostream>
#include "containers/Node.hpp"
# include "containers/List.hpp"
# include "containers/ReverseIterator.hpp"

//# include <list>

bool even(const int &i, const int &j)
{
	return (i > j ? 1 : 0);
}

int main ()
{

	ft::List<int> ll;

	ll.push_back(1);
	ll.push_back(1);
	ft::List<int> assign1;
	ft::List<int> assign2;

	assign2.push_back(1);
	assign2.push_back(2);
	ll.push_back(3);
	ll.push_back(4);
	ll.push_back(5);

	//ll.swap(assign2);
	assign1.assign(ll.begin(), ll.end());
	std::cout << "EMPTY = " << ll.empty() << std::endl;
	std::cout << "SIZE = " << ll.size() << std::endl;
	std::cout << "MAX_SIZE = " << ll.max_size() << std::endl;
	std::cout << "FRONT = " << ll.front() << std::endl;
	std::cout << "BACK = " << ll.back() << std::endl;
	ft::List<int>::iterator it = assign1.begin();
	while (it != assign1.end())
	{
		std::cout << (*it) << std::endl;
		it++;
	}
	assign2.assign(5, 123);
	assign2.push_front(400);
	std::cout << "-------------- ASSIGN 2 ---------------" << std::endl;
	it = assign2.begin();
	while (it != assign2.end())
	{
		std::cout << (*it) << std::endl;
		it++;
	}
	ft::List<int> tmp;
	std::cout << "-------------- PUSH FRONT ---------------" << std::endl;
	tmp.erase(tmp.begin());
	tmp.push_front(5);
	tmp.push_front(1);
	ft::List<int>::iterator itTmp = tmp.begin();
	itTmp = tmp.insert(itTmp, 555);
	itTmp = tmp.begin();
	tmp.insert(itTmp, 5, 42);
	tmp.push_front(99);
	itTmp = tmp.begin();
//	itTmp++;
	std::cout << "SIZE = " << tmp.size() << std::endl;
	itTmp++;
	itTmp++;
	//tmp.erase(itTmp, ++tmp.end());
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	ft::List<int> newL;
	ft::List<int> sorted(3, 20);
	newL.push_back(500);
	newL.push_back(1);
	newL.push_back(70000);
	newL.push_back(2);
	ft::List<int>::iterator newIt = newL.begin();

	newIt = ++newL.begin();
	//tmp.splice(tmp.begin(), newL, newL.begin(), newL.end());
	//newL.remove_if(even);
	//newL.unique(even);
	newL.sort();
	newL.reverse();
	ft::List<int> dup;
	//dup = newL;
	std::cout << " == " << (dup < newL) << std::endl;
	//ft::swap(newL, assign2);
	//newL.merge(sorted, even);
	//newL.insert(newL.end(), sorted.begin(), sorted.end());
	newIt = newL.begin();
	while (newIt != newL.end())
	{
		std::cout << "NewL = " << (*newIt) << std::endl;
		newIt++;
	}
	itTmp = tmp.begin();
	ft::List<int>::reverse_iterator rit = tmp.rbegin();
	std::cout << "SIZE = " << tmp.size() << std::endl;
	while (itTmp != tmp.end())
	{
		std::cout << (*itTmp) << std::endl;
		itTmp++;
	}
	std::cout << "----------------- FINISH --------------------" << std::endl;
}
