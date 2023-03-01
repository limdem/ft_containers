#include "../include/tester.hpp"

void    map_relational_operators()
{
    NAMESPACE::map<int, char> first;
    
    first.insert(NAMESPACE::pair<int, char>(1, 'a'));
    first.insert(NAMESPACE::pair<int, char>(2, 'b'));
    first.insert(NAMESPACE::pair<int, char>(3, 'c'));

    NAMESPACE::map<int, char> second;
    
    second.insert(NAMESPACE::pair<int, char>(7, 'Z'));
    second.insert(NAMESPACE::pair<int, char>(8, 'Y'));
    second.insert(NAMESPACE::pair<int, char>(9, 'X'));
    second.insert(NAMESPACE::pair<int, char>(10, 'W'));

    NAMESPACE::map<int, char> third;
    
    third.insert(NAMESPACE::pair<int, char>(1, 'a'));
    third.insert(NAMESPACE::pair<int, char>(2, 'b'));
    third.insert(NAMESPACE::pair<int, char>(3, 'c'));
 
 
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