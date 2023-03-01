#include "../include/tester.hpp"

void    map_erase()
{
    NAMESPACE::map<char,int> first;
    NAMESPACE::map<char,int>::iterator it;

    // insert some values:
    first['a'] = 10;
    first['b']  =20;
    first['c'] = 30;
    first['d'] = 40;
    first['e'] = 50;
    first['f'] = 60;

    it = first.find('b');
    first.erase (it);                   // erasing by iterator

    first.erase ('c');                  // erasing by key

    it = first.find ('e');
    first.erase ( it, first.end() );    // erasing by range

    // show content:
    for (it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}