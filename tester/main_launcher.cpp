#include "./include/tester.hpp"



int main()
{
    if (vector_launcher())
        return 1;
    if (map_launcher())
        return 1;
    if (stack_launcher())
        return 1;
    if (set_launcher())
        return 1;
    return 0;
}

// GERER CAS OU UN TEST SEGFAULT