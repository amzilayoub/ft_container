# include "containers/Vector.hpp"
# include <iostream>
# include <vector>

int main()
{
	/*

	std::vector<int> vv;

	vv.push_back(5);
	vv.push_back(5);
	vv.reserve(10);
	std::vector<int>::iterator it = vv.begin();
	std::cout << vv.size() << std::endl;
	std::cout << vv.capacity() << std::endl;
	while (it != vv.end())
	{
		std::cout << (*it) << std::endl;
		it++;
	}
	*/
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
	//it = assigned.erase(assigned.end() - 1);
	it = assigned.begin();
	assigned.push_back(90);
	assigned.push_back(90);
	//it = assigned.insert(assigned.begin(), 50000);
	assigned.insert(assigned.begin(), 5, 50000);
	//assigned.push_back(1234);
	it = assigned.begin();
	int i = 1;
	while (it != assigned.end())
	{
		std::cout << "ASSIGNED = "<< i << " - " << (*it) << std::endl;
		it++;
		i++;
	}
	std::cout << "CAPACITY = " << assigned.capacity() << std::endl;
	std::cout << "EMPTY = " << assigned.empty() << std::endl;
	std::cout << "SIZE = " << assigned.size() << std::endl;
	std::cout << "MAX_SIZE = " << assigned.max_size() << std::endl;
}

