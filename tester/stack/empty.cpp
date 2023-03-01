#include "../include/tester.hpp"

void    stack_empty()
{
    NAMESPACE::stack<int> first;
    int sum (0);

    for (int i=1;i<=10;i++) first.push(i);

    while (!first.empty())
    {
        sum += first.top();
        first.pop();
    }

    std::cout << "total: " << sum << '\n';
}