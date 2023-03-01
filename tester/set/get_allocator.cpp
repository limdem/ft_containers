#include "../include/tester.hpp"

void    get_allocator()
{
    NAMESPACE::set<int> first;
    int * p;
    unsigned int i;

    // allocate an array of 5 elements using first's allocator:
    p = first.get_allocator().allocate(5);

    // assign some values to array
    for (i=0; i<5; i++) p[i]=(i+1)*10;

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';

    first.get_allocator().deallocate(p,5);
}