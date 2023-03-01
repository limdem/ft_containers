#include "../include/tester.hpp"

void    set_value_comp()
{
    NAMESPACE::set<int> first;

    NAMESPACE::set<int>::value_compare mycomp = first.value_comp();

    for (int i=0; i<=5; i++) first.insert(i);

    std::cout << "first contains:";

    int highest = *first.rbegin();
    NAMESPACE::set<int>::iterator it=first.begin();
    do {
        std::cout << ' ' << *it;
    } while (mycomp(*(++it),highest) );

    std::cout << '\n';
}