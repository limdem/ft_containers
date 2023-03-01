#include "../include/tester.hpp"

void    set_max_size()
{
    int i;
    NAMESPACE::set<int> first;

    if (first.max_size()>1000)
    {
        for (i=0; i<1000; i++) first.insert(i);
        std::cout << "The set contains 1000 elements.\n";
    }
    else std::cout << "The set could not hold 1000 elements.\n";
}