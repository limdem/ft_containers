#include "../include/tester.hpp"

void    vector_capacity()
{
    NAMESPACE::vector<int> first;

    // set some content in the vector:
    for (int i=0; i<100; i++) first.push_back(i);

    std::cout << "size: " << (int) first.size() << '\n';
    std::cout << "capacity: " << (int) first.capacity() << '\n';
    std::cout << "max_size: " << (int) first.max_size() << '\n';
}