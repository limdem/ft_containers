#ifndef TESTER_HPP
# define TESTER_HPP


# if SELECT_NAMESPACE == 1
# define NAMESPACE ft
# elif SELECT_NAMESPACE == 2
# define NAMESPACE std
# endif




# include "../../containers/vector.hpp"
# include "../../containers/map.hpp"
# include "../../containers/stack.hpp"
# include "../../containers/set.hpp"
# include <vector>
# include <map>
# include <stack>
# include <set>
# include <iostream>
# include <sys/time.h>
# include <fstream>
# include <sys/time.h>
# include <ctime>

# include <deque>


// VECTOR
int    vector_launcher();
void    vector_constructor();
void    vector_copy_assignment();
void    vector_begins_ends();
void    vector_size();
void    vector_max_size();
void    vector_inception1();
void    vector_inception2();
void    vector_inception3();
void    vector_resize();
void    vector_capacity();
void    vector_empty();
void    vector_reserve();
void    vector_at_operator();
void    vector_at();
void    vector_front();
void    vector_back();
void    vector_data();
void    vector_assign();
void    vector_push_back();
void    vector_pop_back();
void    vector_insert();
void    vector_erase();
void    vector_swaps();
void    vector_clear();
void    vector_relational_operators();
void    vector_get_allocator();

// MAP
int map_launcher();
void    map_constructor();
void    map_copy_assignment();
void    map_begins_ends();
void    map_empty();
void    map_size();
void    map_max_size();
void    map_at_operator();
void    map_at();
void    map_insert();
void    map_erase();
void    map_swaps();
void    map_clear();
void    map_key_comp();
void    map_value_comp();
void    map_find();
void    map_count();
void    map_bounds();
void    map_get_allocator();
void    map_relational_operators();

// STACK
int stack_launcher();
void    stack_constructor();
void    stack_empty();
void    stack_size();
void    stack_top();
void    stack_push();
void    stack_pop();
void    stack_relational_operators();

// SET
int set_launcher();
void    set_constructor();
void    set_copy_assignment();
void    set_begins_ends();
void    set_empty();
void    set_size();
void    set_max_size();
void    set_insert();
void    set_erase();
void    set_swaps();
void    set_clear();
void    set_key_comp();
void    set_value_comp();
void    set_find();
void    set_count();
void    set_relational_operators();
#endif