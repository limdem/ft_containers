#include "../include/tester.hpp"

void    map_constructor()
{
    NAMESPACE::map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    NAMESPACE::map<char,int> second (first.begin(),first.end());

    NAMESPACE::map<char,int> third(second);

    for (NAMESPACE::map<char, int>::const_iterator  it = first.begin(); it != first.end(); it++)
        std::cout << "it->first: " << it->first << "it->second: " << it->second;
    std::cout << std::endl;
    for (NAMESPACE::map<char, int>::const_iterator  it = second.begin(); it != second.end(); it++)
        std::cout << "it->first: " << it->first << "it->second: " << it->second;
    std::cout << std::endl;
    for (NAMESPACE::map<char, int>::const_iterator  it = third.begin(); it != third.end(); it++)
        std::cout << "it->first: " << it->first << "it->second: " << it->second;
    std::cout << std::endl;

}