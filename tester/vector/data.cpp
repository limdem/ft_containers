#include "../include/tester.hpp"

void    vector_data()
{
    NAMESPACE::vector<int> myvector (5);

    int* p = myvector.data();

    *p = 10;
    ++p;
    *p = 20;
    p[2] = 100;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}