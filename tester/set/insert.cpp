#include "../include/tester.hpp"

void    set_insert()
{
    NAMESPACE::set<int> first;
    NAMESPACE::set<int>::iterator it;
    NAMESPACE::pair<NAMESPACE::set<int>::iterator,bool> ret;

    // set some initial values:
    for (int i=1; i<=5; ++i) first.insert(i*10);    // set: 10 20 30 40 50

    ret = first.insert(20);               // no new element inserted

    if (ret.second==false) it = ret.first;  // "it" now points to element 20

    first.insert (it,25);                 // max efficiency inserting
    first.insert (it,24);                 // max efficiency inserting
    first.insert (it,26);                 // no max efficiency inserting

    int myints[]= {5,10,15};              // 10 already in set, not inserted
    first.insert (myints, myints + 3);

    std::cout << "first contains:";
    for (it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}