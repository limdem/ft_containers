CC=c++
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -std=c++98
COMPILATION_ERROR_FILE=compilation_errors
NAME_FT = ft_exec
NAME_STL = stl_exec
NAME_TESTER= tester
SRCS = main_launcher.cpp\
	vector/assign.cpp\
	vector/at_operator.cpp\
	vector/at.cpp\
	vector/back.cpp\
	vector/begins_ends.cpp\
	vector/capacity.cpp\
	vector/clear.cpp\
	vector/constructor.cpp\
	vector/copy_assignment.cpp\
	vector/data.cpp\
	vector/empty.cpp\
	vector/erase.cpp\
	vector/front.cpp\
	vector/get_allocator.cpp\
	vector/inception1.cpp\
	vector/inception2.cpp\
	vector/inception3.cpp\
	vector/insert.cpp\
	vector/max_size.cpp\
	vector/pop_back.cpp\
	vector/push_back.cpp\
	vector/relational_operators.cpp\
	vector/reserve.cpp\
	vector/resize.cpp\
	vector/size.cpp\
	vector/swaps.cpp\
	vector/vector_launcher.cpp\
	map/at_operator.cpp\
	map/begins_ends.cpp\
	map/bounds.cpp\
	map/clear.cpp\
	map/constructor.cpp\
	map/copy_assignment.cpp\
	map/count.cpp\
	map/empty.cpp\
	map/erase.cpp\
	map/find.cpp\
	map/get_allocator.cpp\
	map/insert.cpp\
	map/key_comp.cpp\
	map/max_size.cpp\
	map/relational_operators.cpp\
	map/size.cpp\
	map/swaps.cpp\
	map/value_comp.cpp\
	map/map_launcher.cpp\
	stack/constructor.cpp\
	stack/empty.cpp\
	stack/pop.cpp\
	stack/push.cpp\
	stack/relational_operators.cpp\
	stack/size.cpp\
	stack/top.cpp\
	stack/stack_launcher.cpp\
	set/begins_ends.cpp\
	set/bounds.cpp\
	set/clear.cpp\
	set/constructor.cpp\
	set/copy_assignment.cpp\
	set/count.cpp\
	set/empty.cpp\
	set/erase.cpp\
	set/find.cpp\
	set/get_allocator.cpp\
	set/insert.cpp\
	set/key_comp.cpp\
	set/max_size.cpp\
	set/relational_operators.cpp\
	set/size.cpp\
	set/swaps.cpp\
	set/value_comp.cpp\
	set/set_launcher.cpp

OBJS = $(SRCS:.cpp=.o)
OBJS_FT_DIR = obj/ft/
OBJS_STL_DIR = obj/stl/
OBJS_FT_PATH = $(addprefix obj/ft/, $(OBJS))
OBJS_STL_PATH = $(addprefix obj/stl/, $(OBJS))
OTHER_FILES = ft_output.txt stl_output.txt ft_perf.txt stl_perf.txt

all:	$(NAME_FT) $(NAME_STL) $(NAME_TESTER)

$(NAME_FT):	$(OBJS_FT_PATH)
	c++ -o $(NAME_FT) $(OBJS_FT_PATH)

obj/ft/%.o: %.cpp
	c++ $(CFLAGS) -DSELECT_NAMESPACE=1 -c $< -o $@

$(NAME_STL): $(OBJS_STL_PATH)
	c++ -o $(NAME_STL) $(OBJS_STL_PATH)

obj/stl/%.o: %.cpp
	c++ $(CFLAGS) -DSELECT_NAMESPACE=2 -c $< -o $@

$(NAME_TESTER): tester_launcher.o
	c++ -o $(NAME_TESTER) tester_launcher.o

tester_launcher.o: tester_launcher.cpp
	c++ $(CFLAGS) -DSELECT_NAMESPACE=2 -c $< -o $@

clean:
	$(RM) $(OBJS_FT_PATH) $(OBJS_STL_PATH) tester_launcher.o $(OTHER_FILES)

clean_ft:
	$(RM) $(OBJS_FT_PATH)

clean_stl:
	$(RM) $(OBJS_STL_PATH)

clean_tester:
	$(RM) tester_launcher.o

clean_other_files:
	$(RM) $(OTHER_FILES)

fclean: clean
	$(RM) $(NAME_FT) $(NAME_STL) $(NAME_TESTER)

fclean_ft: clean_ft
	$(RM) $(NAME_FT)

fclean_stl: clean_stl
	$(RM) $(NAME_STL)

fclean_tester: clean_tester
	$(RM) $(NAME_TESTER)

fclean_other_files: clean_other_files
	$(RM) $(OTHER_FILES)