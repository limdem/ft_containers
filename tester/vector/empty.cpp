#include "../include/tester.hpp"

void    vector_empty()
{
    NAMESPACE::vector<int> first;
    int sum (0);

    for (int i=1;i<=10;i++) first.push_back(i);

    while (!first.empty())
    {
        sum += first.back();
        first.pop_back();
    }

    std::cout << "total: " << sum << '\n';
}