#include "../include/tester.hpp"

void    map_get_allocator()
{
    int psize;
    NAMESPACE::map<char,int> mymap;
    NAMESPACE::pair<const char,int>* p;

    // allocate an array of 5 elements using mymap's allocator:
    p = mymap.get_allocator().allocate(5);

    // assign some values to array
    psize = sizeof(NAMESPACE::map<char,int>::value_type) * 5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    mymap.get_allocator().deallocate(p,5);
}