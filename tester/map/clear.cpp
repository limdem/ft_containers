#include "../include/tester.hpp"

void    map_clear()
{
    NAMESPACE::map<char,int> first;

    first['x']=100;
    first['y']=200;
    first['z']=300;

    std::cout << "first contains:\n";
    for (NAMESPACE::map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    first.clear();
    first['a']=1101;
    first['b']=2202;

    std::cout << "first contains:\n";
    for (NAMESPACE::map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}