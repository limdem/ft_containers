#include "../include/tester.hpp"

void    map_count()
{
    NAMESPACE::map<char,int> first;
    char c;

    first ['a']=101;
    first ['c']=202;
    first ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (first.count(c)>0)
        std::cout << " is an element of first.\n";
        else 
        std::cout << " is not an element of first.\n";
    }
}