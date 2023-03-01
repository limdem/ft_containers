#include "../include/tester.hpp"

void    set_find()
{
    NAMESPACE::set<int> first;
    NAMESPACE::set<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=5; i++) first.insert(i*10);    // set: 10 20 30 40 50

    it = first.find(20);
    first.erase(it);
    first.erase(first.find(40));

    std::cout << "first contains:";
    for (it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}