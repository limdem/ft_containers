#include "../include/tester.hpp"

void    vector_begins_ends()
{
    NAMESPACE::vector<int> first;
    for (int i=1; i<=5; i++) first.push_back(i);

    std::cout << "first contains:";
    for (NAMESPACE::vector<int>::iterator it = first.begin() ; it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    NAMESPACE::vector<int> second(5);  // 5 default-constructed ints

    int i=0;

    NAMESPACE::vector<int>::reverse_iterator rit = second.rbegin();
    for (; rit!= second.rend(); ++rit)
        *rit = ++i;

    std::cout << "second contains:";
    for (NAMESPACE::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}