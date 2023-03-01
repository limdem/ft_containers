#include "../include/tester.hpp"

void    map_at_operator()
{
    NAMESPACE::map<char,std::string> first;

    first['a']="an element";
    first['b']="another element";
    first['c']=first['b'];

    std::cout << "first['a'] is " << first['a'] << '\n';
    std::cout << "first['b'] is " << first['b'] << '\n';
    std::cout << "first['c'] is " << first['c'] << '\n';
    std::cout << "first['d'] is " << first['d'] << '\n';

    std::cout << "first now contains " << first.size() << " elements.\n";   
}