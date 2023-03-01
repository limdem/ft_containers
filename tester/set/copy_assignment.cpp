#include "../include/tester.hpp"

void    set_copy_assignment()
{
    int myints[] = { 12,82,37,64,15 };
    NAMESPACE::set<int> first (myints,myints+5);   // set with 5 ints
    NAMESPACE::set<int> second;                    // empty set

    second = first;                          // now second contains the 5 ints
    first = NAMESPACE::set<int>();                 // and first is empty

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
}