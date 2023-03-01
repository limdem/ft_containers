#include "../include/tester.hpp"

void    vector_resize()
{
    NAMESPACE::vector<int> first;

    // set some initial content:
    for (int i=1;i<10;i++) first.push_back(i);

    first.resize(5);
    first.resize(8,100);
    first.resize(12);

    std::cout << "first contains:";
    for (std::size_t i=0;i<first.size();i++)
        std::cout << ' ' << first[i];
    std::cout << '\n';   
}