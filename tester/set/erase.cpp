#include "../include/tester.hpp"

void    set_erase()
{
    NAMESPACE::set<int> first;
    NAMESPACE::set<int>::iterator it;

    // insert some values:
    for (int i=1; i<10; i++) first.insert(i*10);  // 10 20 30 40 50 60 70 80 90

    it = first.begin();
    ++it;                                         // "it" points now to 20

    first.erase (it);

    first.erase (40);

    it = first.find (60);
    first.erase (it, first.end());

    std::cout << "first contains:";
    for (it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}