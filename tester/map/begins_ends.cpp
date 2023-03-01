#include "../include/tester.hpp"

void    map_begins_ends()
{
   NAMESPACE::map<char,int> first;

    first['b'] = 100;
    first['a'] = 200;
    first['c'] = 300;

    // show content:
    for (NAMESPACE::map<char,int>::iterator it = first.begin(); it != first.end(); ++it)
       std::cout << it->first << " => " << it->second << '\n';

    NAMESPACE::map<char,int>::reverse_iterator rit;
    for (rit = first.rbegin(); rit != first.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';
}