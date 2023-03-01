#include "../include/tester.hpp"

int    vector_launcher()
{
    std::cout << "VECTOR TESTS: " << std::endl;
    
    void    (*farray[])() = {
        vector_constructor,
        vector_copy_assignment,
        vector_begins_ends,
        vector_size,
        vector_max_size,
        vector_inception1,
        vector_inception2,
        vector_inception3,
        vector_resize,
        vector_capacity,
        vector_empty,
        vector_reserve,
        vector_at_operator,
        vector_at,
        vector_front,
        vector_back,
        vector_data,
        vector_assign,
        vector_push_back,
        vector_pop_back,
        vector_insert,
        vector_erase,
        vector_swaps,
        vector_clear,
        vector_get_allocator,
        vector_relational_operators
        };
    
    std::fstream    fs;
    # if SELECT_NAMESPACE == 1
        std::string file_name = "ft";
    # else
        std::string file_name = "stl";
    #endif
    
    file_name += "_perf.txt";
    fs.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);
    if (!fs)
    {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    fs << "VECTOR" << std::endl; 
    for (int    i = 0; i < 23; i++)
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