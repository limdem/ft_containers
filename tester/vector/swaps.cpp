#include "../include/tester.hpp"

void    vector_swaps()
{
    NAMESPACE::vector<int> first(3,100);   // three ints with a value of 100
    NAMESPACE::vector<int> second(5,200);   // five ints with a value of 200

    first.swap(second);

    std::cout << "first contains:";
    for (unsigned i=0; i<first.size(); i++)
        std::cout << ' ' << first[i];
    std::cout << '\n';

    std::cout << "second contains:";
    for (unsigned i=0; i<second.size(); i++)
        std::cout << ' ' << second[i];
    std::cout << '\n';
}