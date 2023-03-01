#include "../include/tester.hpp"

void    vector_front()
{
    NAMESPACE::vector<int> first;

    first.push_back(78);
    first.push_back(16);

    // now front equals 78, and back 16

    first.front() -= first.back();

    std::cout << "first.front() is now " << first.front() << '\n';
}