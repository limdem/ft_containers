#include "../include/tester.hpp"

void    vector_inception1()
{
	int	tab1[] = {1, 2, 3};
	NAMESPACE::vector<int>	tmp1(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tmp2(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tmp3(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tmp4(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tmp5(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tmp6(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tmp7(tab1, tab1 + 2);
	NAMESPACE::vector<int>	tab2[] = {tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7};
	NAMESPACE::vector<NAMESPACE::vector<int> >	first(tab2, tab2 + 6);

	
	first.resize(2);
	first.reserve(4);
}