#include "../include/tester.hpp"

void    vector_copy_assignment()
{
    NAMESPACE::vector<int> first(3,0);
    NAMESPACE::vector<int> second(5,0);

    second = first;
    first = NAMESPACE::vector<int>();

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
  
}