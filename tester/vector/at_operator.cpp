#include "../include/tester.hpp"

void    vector_at_operator()
{
    NAMESPACE::vector<int> first(10);   // 10 zero-initialized elements

    NAMESPACE::vector<int>::size_type sz = first.size();

    // assign some values:
    for (unsigned i=0; i < sz; i++) first[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i < sz / 2; i++)
    {
        int temp;
        temp = first[sz-1-i];
        first[sz-1-i]=first[i];
        first[i]=temp;
    }

    std::cout << "first contains:";
    for (unsigned i=0; i < sz; i++)
        std::cout << ' ' << first[i];
    std::cout << '\n';
}