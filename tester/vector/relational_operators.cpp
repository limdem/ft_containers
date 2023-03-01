#include "../include/tester.hpp"

void    vector_relational_operators()
{
    NAMESPACE::vector<int> first(3,100);   // three ints with a value of 100
    NAMESPACE::vector<int> second(2,200);   // two ints with a value of 200

    if (first == second) std::cout << "first and second are equal\n";
    if (first != second) std::cout << "first and second are not equal\n";
    if (first < second) std::cout << "first is less than second\n";
    if (first > second) std::cout << "first is greater than second\n";
    if (first <= second) std::cout << "first is less than or equal to second\n";
    if (first >= second) std::cout << "first is greater than or equal to second\n";
}