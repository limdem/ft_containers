#include "../include/tester.hpp"

void    set_size()
{
    NAMESPACE::set<int> first;
    std::cout << "0. size: " << first.size() << '\n';

    for (int i=0; i<10; ++i) first.insert(i);
    std::cout << "1. size: " << first.size() << '\n';

    first.insert (100);
    std::cout << "2. size: " << first.size() << '\n';

    first.erase(5);
    std::cout << "3. size: " << first.size() << '\n';
}