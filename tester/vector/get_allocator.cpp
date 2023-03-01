#include "../include/tester.hpp"

void    vector_get_allocator()
{
    NAMESPACE::vector<int> first;
    int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = first.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i=0; i<5; i++) first.get_allocator().construct(&p[i],i);

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i=0; i<5; i++) first.get_allocator().destroy(&p[i]);
    first.get_allocator().deallocate(p,5);   
}