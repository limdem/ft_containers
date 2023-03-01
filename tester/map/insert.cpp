#include "../include/tester.hpp"

void    map_insert()
{
    std::cout << "MAP INSERT" << std::endl;
    NAMESPACE::map<char,int> first;

    // first insert function version (single parameter):
    first.insert (NAMESPACE::pair<char,int>('a',100) );
    first.insert (NAMESPACE::pair<char,int>('z',200) );

    NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
    ret = first.insert (NAMESPACE::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    NAMESPACE::map<char,int>::iterator it = first.begin();
    first.insert (it, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
    first.insert (it, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    NAMESPACE::map<char,int> second;
    second.insert(first.begin(),first.find('c'));

    // showing contents:
    std::cout << "first contains:\n";
    for (it=first.begin(); it!=first.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "second contains:\n";
    for (it=second.begin(); it!=second.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    NAMESPACE::map<int,int>    third;

    for (int    i = 0; i < 10000; i++)
        third.insert(NAMESPACE::pair<int, int>(i, i * 2));

    for (NAMESPACE::map<int, int>::const_iterator it = third.begin(); it != third.end(); it++)
        std::cout << "it->first: " << it->first << " et it->second: " << it->second;
}