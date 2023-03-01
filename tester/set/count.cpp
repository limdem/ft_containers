#include "../include/tester.hpp"

void    set_count()
{
    NAMESPACE::set<int> first;

    // set some initial values:
    for (int i=1; i<5; ++i) first.insert(i*3);    // set: 3 6 9 12

    for (int i=0; i<10; ++i)
    {
        std::cout << i;
        if (first.count(i)!=0)
            std::cout << " is an element of first.\n";
        else
            std::cout << " is not an element of first.\n";
    }
}