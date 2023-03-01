#include "../include/tester.hpp"

void    set_relational_operators()
{
    int myints1[] = {1, 2, 3};
    int myints2[] = {7, 8, 9, 10};

    NAMESPACE::set<int> first(myints1, myints1 + 2);
    NAMESPACE::set<int> second(myints2, myints2 + 3);
    NAMESPACE::set<int> third(myints1, myints1 + 2);
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "first == second returns " << (first == second) << '\n';
    std::cout << "first != second returns " << (first != second) << '\n';
    std::cout << "first <  second returns " << (first < second) << '\n';
    std::cout << "first <= second returns " << (first <= second) << '\n';
    std::cout << "first >  second returns " << (first > second) << '\n';
    std::cout << "first >= second returns " << (first >= second) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "first == third returns " << (first == third) << '\n';
    std::cout << "first != third returns " << (first != third) << '\n';
    std::cout << "first <  third returns " << (first < third) << '\n';
    std::cout << "first <= third returns " << (first <= third) << '\n';
    std::cout << "first >  third returns " << (first > third) << '\n';
    std::cout << "first >= third returns " << (first >= third) << '\n';
}