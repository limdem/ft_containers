#include "../include/tester.hpp"

void    vector_insert()
{
    NAMESPACE::vector<int> first(3,100);
    NAMESPACE::vector<int>::iterator it;

    it = first.begin();
    it = first.insert( it , 200 );

    first.insert(it, 2, 300);

    // "it" no longer valid, get a new one:
    it = first.begin();

    NAMESPACE::vector<int> second(2,400);
    first.insert (it+2,second.begin(),second.end());

    int myarray [] = { 501,502,503 };
    first.insert (first.begin(), myarray, myarray+3);

    std::cout << "first contains:";
    for (it=first.begin(); it<first.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';


}