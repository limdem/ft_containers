#include "../include/tester.hpp"

void    vector_inception2()
{
      int	tab1[] = {1, 2, 3};
      int	tab2[] = {4, 5, 6};
      int	tab3[] = {7, 8, 9};
      int	tab4[] = {10, 11, 12};
      int	tab5[] = {13, 14, 15};
      NAMESPACE::vector<int>	tmp1(tab1, tab1 + 3);
      NAMESPACE::vector<int>	tmp2(tab2, tab2 + 3);
      NAMESPACE::vector<int>	tmp3(tab3, tab3 + 3);
      NAMESPACE::vector<int>	tmp4(tab4, tab4 + 3);
      NAMESPACE::vector<int>	tmp5(tab1, tab1 + 3);
      NAMESPACE::vector<int>	tmp6(tab1, tab1 + 3);
      NAMESPACE::vector<int>	tmp7(tab1, tab1 + 3);


      NAMESPACE::vector<int>	tmp8(tab5, tab5 + 3);
      
      for (NAMESPACE::vector<int>::const_iterator	it = tmp1.begin(); it != tmp1.end(); it++)
        std::cout << "*it: " << *it << "";
      std::cout << std::endl;
      NAMESPACE::vector<int>	tab6[] = {tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7};
      NAMESPACE::vector<NAMESPACE::vector<int> >	first(tab6, tab6 + 6);

      first.resize(4);
      std::cout << "FIRST0:" << std::endl;
      for (NAMESPACE::vector<NAMESPACE::vector<int> >::iterator it = first.begin(); it != first.end(); it++)
        std::cout << (*it)[0] << std::endl;
      try
      {
        first.insert(first.begin() + 1, tmp8);
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
      std::cout << "FIRST1:" << std::endl;
      for (NAMESPACE::vector<NAMESPACE::vector<int> >::iterator it = first.begin(); it != first.end(); it++)
        std::cout << (*it)[0] << std::endl;
    
}