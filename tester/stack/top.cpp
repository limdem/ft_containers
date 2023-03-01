#include "../include/tester.hpp"

void    stack_top()
{
    NAMESPACE::stack<int> first;

    first.push(10);
    first.push(20);

    first.top() -= 5;

    std::cout << "first.top() is now " << first.top() << '\n';    
}