#include "../include/tester.hpp"

void    vector_max_size()
{
    NAMESPACE::vector<int> first;

    // set some content in the vector:
    for (int i=0; i<100; i++) first.push_back(i);

    std::cout << "size: " << first.size() << "\n";
    std::cout << "capacity: " << first.capacity() << "\n";
    std::cout << "max_size: " << first.max_size() << "\n";
}