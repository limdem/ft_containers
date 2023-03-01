#include "../include/tester.hpp"

void    vector_reserve()
{
  NAMESPACE::vector<int>::size_type sz;

  NAMESPACE::vector<int> first;
  sz = first.capacity();
  std::cout << "making first grow:\n";
  for (int i=0; i<100; ++i) {
    first.push_back(i);
    if (sz!=first.capacity()) {
      sz = first.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  NAMESPACE::vector<int>second;
  sz = second.capacity();
 second.reserve(100);   // this is the only difference with first above
  std::cout << "makingsecond grow:\n";
  for (int i = 0; i < 100; ++i) {
   second.push_back(i);
    if (sz != second.capacity()) {
      sz = second.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
}