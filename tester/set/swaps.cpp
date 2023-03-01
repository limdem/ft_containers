#include "../include/tester.hpp"

void    set_swaps()
{
    int myints1[] = {12,75,10,32,20,25};
    NAMESPACE::set<int> first(myints1, myints1 + 3);     // 10,12,75
    NAMESPACE::set<int> second(myints1 + 3, myints1 + 6);  // 20,25,32

    first.swap(second);

    std::cout << "first contains:";
    for (NAMESPACE::set<int>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "second contains:";
    for (NAMESPACE::set<int>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    int myints2[] = {1, 2, 3};
    int myints3[] = {7, 8, 9, 10};
    NAMESPACE::set<int> third(myints2, myints2 + 2);
    NAMESPACE::set<int> fourth(myints3, myints3 + 3);
 
    // Print state before swap
    std::cout << "third:";
    for (NAMESPACE::set<int>::iterator it = third.begin(); it != third.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << "\n" "fourth  :";
    for (NAMESPACE::set<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << ' ' << *it;
 
    std::cout << "-- SWAP\n";
    std::swap(third, fourth);
 
    // Print state after swap
    std::cout << "third:";
    for (NAMESPACE::set<int>::iterator it = third.begin(); it != third.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << "\n" "fourth  :";
    for (NAMESPACE::set<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << ' ' << *it;
}