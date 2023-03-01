#include "../include/tester.hpp"

void    map_key_comp()
{
    NAMESPACE::map<char,int> first;

    NAMESPACE::map<char,int>::key_compare mycomp = first.key_comp();

    first['a']=100;
    first['b']=200;
    first['c']=300;

    std::cout << "first contains:\n";

    char highest = first.rbegin()->first;     // key value of last element

    NAMESPACE::map<char,int>::iterator it = first.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );

    std::cout << '\n';
}