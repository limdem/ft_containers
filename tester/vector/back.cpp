#include "../include/tester.hpp"

void    vector_back()
{
    NAMESPACE::vector<int> first;

    first.push_back(10);

    while (first.back() != 0)
    {
        first.push_back ( first.back() -1 );
    }

    std::cout << "first contains:";
    for (unsigned i=0; i<first.size() ; i++)
        std::cout << ' ' << first[i];
    std::cout << '\n';
}