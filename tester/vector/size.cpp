#include "../include/tester.hpp"

void    vector_size()
{
    NAMESPACE::vector<int> first;

    std::cout << "0. size: " << first.size() << '\n';

    for (int i=0; i<10; i++) first.push_back(i);
    std::cout << "1. size: " << first.size() << '\n';

    first.insert (first.end(),10,100);
    std::cout << "2. size: " << first.size() << '\n';

    first.pop_back();
    std::cout << "3. size: " << first.size() << '\n';
}