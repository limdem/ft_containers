#include "../include/tester.hpp"

void    set_key_comp()
{
    NAMESPACE::set<int> first;
    int highest;

    NAMESPACE::set<int>::key_compare mycomp = first.key_comp();

    for (int i=0; i<=5; i++) first.insert(i);

    std::cout << "first contains:";

    highest = *first.rbegin();
    NAMESPACE::set<int>::iterator it = first.begin();
    do {
        std::cout << ' ' << *it;
    } while (mycomp(*(++it),highest) );

    std::cout << '\n';
}