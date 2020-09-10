# include "containers/Stack.hpp"
# include <iostream>

int main()
{
    ft::Stack<int> t;

    t.push(5);
    t.push(10);
    std::cout << "top = " << t.top() << std::endl;
    t.pop();
    std::cout << "top = " << t.top() << std::endl;
    std::cout << "Size = " << t.size() << std::endl;
    std::cout << "empty = " << t.empty() << std::endl;
    t.pop();
    ft::Stack<int> t2(t);
    std::cout << "empty = " << t.empty() << std::endl;
    std::cout << "empty = " << t2.empty() << std::endl;
    std::cout << "== " << (t == t2) << std::endl;
    std::cout << "!= " << (t != t2) << std::endl;
    std::cout << "> " << (t > t2) << std::endl;
    std::cout << ">= " << (t >= t2) << std::endl;
    std::cout << "< " << (t < t2) << std::endl;
    std::cout << "<= " << (t <= t2) << std::endl;
    return (0);
}