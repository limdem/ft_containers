#include "../include/tester.hpp"

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

void    set_constructor()
{
    NAMESPACE::set<int> first;                           // empty set of ints

    int myints[]= {10,20,30,40,50};
    NAMESPACE::set<int> second (myints,myints+5);        // range

    NAMESPACE::set<int> third (second);                  // a copy of second

    NAMESPACE::set<int> fourth (second.begin(), second.end());  // iterator ctor.

    NAMESPACE::set<int,classcomp> fifth;                 // class as Compare

    bool(*fn_pt)(int,int) = fncomp;
    NAMESPACE::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
}