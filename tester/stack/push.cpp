#include "../include/tester.hpp"

void    stack_push()
{
    NAMESPACE::stack<int> first;

    for (int i=0; i<5; ++i) first.push(i);

    std::cout << "Popping out elements...";
    while (!first.empty())
    {
        std::cout << ' ' << first.top();
        first.pop();
    }
    std::cout << '\n';   
}