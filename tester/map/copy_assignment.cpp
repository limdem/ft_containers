#include "../include/tester.hpp"

void    map_copy_assignment()
{
    NAMESPACE::map<char,int> first;
    NAMESPACE::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints
    first=NAMESPACE::map<char,int>();  // and first is now empty

    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
}