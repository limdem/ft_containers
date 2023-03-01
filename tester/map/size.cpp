#include "../include/tester.hpp"

void    map_size()
{
    NAMESPACE::map<char,int> first;
    first['a']=101;
    first['b']=202;
    first['c']=302;

    std::cout << "first.size() is " << first.size() << '\n';
}