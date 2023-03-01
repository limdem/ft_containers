#include "../include/tester.hpp"

void    stack_constructor()
{
    std::deque<int> deq(3,100);          // deque with 3 elements
    NAMESPACE::vector<int> vect(2,200);        // vector with 2 elements

    NAMESPACE::stack<int> first;                    // empty stack
    NAMESPACE::stack<int, std::deque<int> > second (deq);         // stack initialized to copy of deque

    NAMESPACE::stack<int,NAMESPACE::vector<int> > third;  // empty stack using vector
    NAMESPACE::stack<int,NAMESPACE::vector<int> > fourth(vect);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';    
}