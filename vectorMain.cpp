# include "containers/Vector.hpp"
# include <iostream>
# include <vector>

int main()
{
	ft::Vector<int> vv;
	vv.push_back(5);
	vv.reserve(10);
	vv.assign(3, -1);
	vv.resize(9, 8);
	vv.push_back(2);
	vv[0] = 99;
	std::cout << "FRONT = " << vv.front() << std::endl;
	std::cout << "BACK = " << vv.back() << std::endl;
	ft::Vector<int>::iterator it = vv.begin();
	while (it != vv.end())
	{
		std::cout << "VV = " << (*it) << std::endl;
		it++;
	}
	std::cout << "CAPACITY = " << vv.capacity() << std::endl;
	std::cout << "EMPTY = " << vv.empty() << std::endl;
	std::cout << "SIZE = " << vv.size() << std::endl;
	std::cout << "MAX_SIZE = " << vv.max_size() << std::endl;
	ft::Vector<int> assigned;
	assigned.assign(vv.begin(), vv.end());
	//assigned.pop_back();
	it = assigned.erase(assigned.end() - 1);
	it = assigned.begin();
	while (it != assigned.end())
	{
		std::cout << "ASSIGNED = " << (*it) << std::endl;
		it++;
	}
	std::cout << "CAPACITY = " << assigned.capacity() << std::endl;
	std::cout << "EMPTY = " << assigned.empty() << std::endl;
	std::cout << "SIZE = " << assigned.size() << std::endl;
	std::cout << "MAX_SIZE = " << assigned.max_size() << std::endl;
}
