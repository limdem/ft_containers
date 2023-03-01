#include "../include/tester.hpp"

void    set_bounds()
{
    NAMESPACE::set<int> first;
    NAMESPACE::set<int>::iterator itlow, itup;

    for (int i = 1; i < 10; i++) first.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    itlow = first.lower_bound(30);                //       ^
    itup = first.upper_bound(60);                 //                   ^

    first.erase(itlow,itup);                     // 10 20 70 80 90

    std::cout << "first contains:";
    for (NAMESPACE::set<int>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    NAMESPACE::set<int> second;

    for (int i = 1; i <= 5; i++) second.insert(i*10);   // second: 10 20 30 40 50

    NAMESPACE::pair<NAMESPACE::set<int>::const_iterator, NAMESPACE::set<int>::const_iterator> ret;
    ret = second.equal_range(30);

    std::cout << "the lower bound points to: " << *ret.first << '\n';
    std::cout << "the upper bound points to: " << *ret.second << '\n';
}