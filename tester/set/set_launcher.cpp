#include "../include/tester.hpp"

int set_launcher()
{
    std::cout << "SET TESTS: " << std::endl;

    void    (*farray[])() = {
        set_constructor,
        set_copy_assignment,
        set_begins_ends,
        set_empty,
        set_size,
        set_max_size,
        set_insert,
        set_erase,
        set_swaps,
        set_clear,
        set_key_comp,
        set_value_comp,
        set_find,
        set_count,
        set_relational_operators
    };

    std::fstream    fs;
    # if SELECT_NAMESPACE == 1
        std::string file_name = "ft";
    # else
        std::string file_name = "stl";
    # endif

    file_name += "_perf.txt";
    fs.open(file_name.c_str(), std::fstream::out | std::fstream::app);
    if (!fs)
    {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    fs << "SET" << std::endl; 
    for (int    i = 0; i < 15; i++)
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