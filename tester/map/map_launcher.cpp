#include "../include/tester.hpp"

int map_launcher()
{
    std::cout << "MAP TESTS: " << std::endl;

    void    (*farray[])() = {
        map_constructor,
        map_copy_assignment,
        map_begins_ends,
        map_empty,
        map_size,
        map_max_size,
        map_at_operator,
        map_insert,
        map_erase,
        map_swaps,
        map_clear,
        map_key_comp,
        map_value_comp,
        map_find,
        map_count,
        map_bounds,
        map_get_allocator,
        map_relational_operators
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
    fs << "MAP" << std::endl;  
    for (int    i = 0; i < 18; i++)
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