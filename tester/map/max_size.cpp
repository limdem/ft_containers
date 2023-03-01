#include "../include/tester.hpp"

void    map_max_size()
{
    int i;
    NAMESPACE::map<int,int> first;

    if (first.max_size()>1000)
    {
        for (i=0; i<1000; i++) first[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";    
}