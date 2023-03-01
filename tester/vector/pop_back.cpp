#include "../include/tester.hpp"

void    vector_pop_back()
{
    NAMESPACE::vector<int> first;
    int sum (0);
    first.push_back (100);
    first.push_back (200);
    first.push_back (300);

    while (!first.empty())
    {
        sum += first.back();
        first.pop_back();
    }

    std::cout << "The elements of first add up to " << sum << '\n';
}