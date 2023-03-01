#include "../include/tester.hpp"

void    vector_push_back()
{
    NAMESPACE::vector<int> first;
    int myint = 667;

    while (myint--)
        first.push_back(myint);

    std::cout << "first stores " << int(first.size()) << " numbers.\n";
    for (NAMESPACE::vector<int>::const_iterator   it(first.begin()); it != first.end(); it++)
        std::cout << *it;

    NAMESPACE::vector<int> second;
    for (int    i = 0; i < 10000; i++)
        second.push_back(i * 2 + 1);
    std::cout << "second stores " << int(second.size()) << " numbers.\n";
    for (NAMESPACE::vector<int>::const_iterator   it(second.begin()); it != second.end(); it++)
        std::cout << *it;

}