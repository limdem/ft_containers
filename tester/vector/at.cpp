#include "../include/tester.hpp"

void    vector_at()
{
    NAMESPACE::vector<int> first(10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i < first.size(); i++)
        first.at(i)=i;

    std::cout << "first contains:";
    for (unsigned i=0; i < first.size(); i++)
        std::cout << ' ' << first.at(i);
    std::cout << '\n';
}