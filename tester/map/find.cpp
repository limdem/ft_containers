#include "../include/tester.hpp"

void    map_find()
{
    NAMESPACE::map<char,int> first;
    NAMESPACE::map<char,int>::iterator it;

    first['a'] = 50;
    first['b'] = 100;
    first['c'] = 150;
    first['d'] = 200;

    it = first.find('b');
    if (it != first.end())
        first.erase (it);

    // print content:
    std::cout << "elements in first:" << '\n';
    std::cout << "a => " << first.find('a')->second << '\n';
    std::cout << "c => " << first.find('c')->second << '\n';
    std::cout << "d => " << first.find('d')->second << '\n';   
}