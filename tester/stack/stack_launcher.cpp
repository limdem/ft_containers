#include "../include/tester.hpp"

int stack_launcher()
{
    std::cout << "STACK TESTS: " << std::endl;

    void    (*farray[])() = {
        stack_constructor,
        stack_empty,
        stack_size,
        stack_top,
        stack_push,
        stack_pop,
        stack_relational_operators
    };

    std::fstream    fs;
    # if SELECT_NAMESPACE == 1
        std::string file_name = "ft";
    # else
        std::string file_name = "stl";
    #endif
    
    file_name += "_perf.txt";
    fs.open(file_name.c_str(), std::fstream::out | std::fstream::app);
    if (!fs)
    {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    fs << "STACK" << std::endl;   
    for (int    i = 0; i < 7; i++)
    {
        struct timeval begin;
        struct timeval end;
        gettimeofday(&begin, NULL);
        farray[i]();
        gettimeofday(&end, NULL);
        fs << 1000000 * (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec) << std::endl;
    }
        
    fs.close();
    return 0;
}