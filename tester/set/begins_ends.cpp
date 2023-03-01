#include "../include/tester.hpp"

void    set_begins_ends()
{
    int myints1[] = {75,23,65,42,13};
    NAMESPACE::set<int> first(myints1, myints1 + 5);

    std::cout << "first contains:";
    for (NAMESPACE::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << '\n';

    int myints2[] = {21,64,17,78,49};
    NAMESPACE::set<int> second(myints2, myints2 + 5);

    NAMESPACE::set<int>::reverse_iterator rit;

    std::cout << "second contains:";
    for (rit=second.rbegin(); rit != second.rend(); ++rit)
        std::cout << ' ' << *rit;

    std::cout << '\n';

}