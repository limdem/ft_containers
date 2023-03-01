#include "../include/tester.hpp"

void    set_empty()
{
    NAMESPACE::set<int> first;

    first.insert(20);
    first.insert(30);
    first.insert(10);

    std::cout << "first contains:";
    while (!first.empty())
    {
        std::cout << ' ' << *first.begin();
        first.erase(first.begin());
    }
    std::cout << '\n';
}