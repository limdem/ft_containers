#include "../include/tester.hpp"

void    map_bounds()
{
    NAMESPACE::map<char,int>first;
    NAMESPACE::map<char,int>::iterator itlow, itup;

   first['a'] = 20;
   first['b'] = 40;
   first['c'] = 60;
   first['d'] = 80;
   first['e'] = 100;

    itlow = first.lower_bound ('b');  // itlow points to b
    itup = first.upper_bound ('d');   // itup points to e (not d!)

   first.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (NAMESPACE::map<char,int>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    NAMESPACE::map<char,int> second;

    second['a'] = 10;
    second['b'] = 20;
    second['c'] = 30;

    NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
    ret = second.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
}