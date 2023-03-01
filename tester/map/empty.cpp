#include "../include/tester.hpp"

void    map_empty()
{
    NAMESPACE::map<char,int> first;

    first['a']=10;
    first['b']=20;
    first['c']=30;

    while (!first.empty())
    {
        std::cout << first.begin()->first << " => " << first.begin()->second << '\n';
        first.erase(first.begin());
  }    
}