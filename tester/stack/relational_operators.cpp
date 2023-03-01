#include "../include/tester.hpp"
#include <vector>
#include <list>

void    stack_relational_operators()
{
    NAMESPACE::stack<int, std::vector<int> > first, second, third;

    // The following would have cause an error because stacks with
    // different base containers are not equality comparable
    // stack <int, list<int> >  third;

    first.push(1);
    second.push(2);
    third.push(1);

    if ( first != second )
        std::cout << "The stacks first and second are not equal." << std::endl;
    else
        std::cout << "The stacks first and second are equal." << std::endl;

    if ( first != third )
        std::cout << "The stacks first and third are not equal." << std::endl;
    else
        std::cout << "The stacks first and third are equal." << std::endl;

    NAMESPACE::stack<int, std::list<int> > fourth, fifth, sixth;

    fourth.push( 2 );
    fourth.push( 4 );
    fourth.push( 6 );
    fourth.push( 8 );
    fifth.push( 5 );
    fifth.push( 10 );
    sixth.push( 2 );
    sixth.push( 4 );
    sixth.push( 6 );
    sixth.push( 8 );

    if ( fourth >= fifth )
        std::cout << "The stack fourth is greater than or equal to "
            << "the stack fifth." << std::endl;
    else
        std::cout << "The stack fourth is less than "
            << "the stack fifth." << std::endl;

    if ( fourth>= sixth )
        std::cout << "The stack fourth is greater than or equal to "
            << "the stack sixth." << std::endl;
    else
        std::cout << "The stack fourth is less than "
            << "the stack sixth." << std::endl;

    // to print out the stack fourth ( by unstacking the elements):
    NAMESPACE::stack<int>::size_type i_size_fourth = fourth.size( );
    std::cout << "The stack fourth from the top down is: ( ";
    unsigned int i;
    for ( i = 1 ; i <= i_size_fourth ; i++ )
    {
        std::cout << fourth.top( ) << " ";
        fourth.pop( );
    }
    std::cout << ")." << std::endl;

    NAMESPACE::stack<int> seventh, eigth, ninth;

    seventh.push( 5 );
    seventh.push( 10 );
    eigth.push( 1 );
    eigth.push( 2 );
    ninth.push( 5 );
    ninth.push( 10 );

    if ( seventh <= eigth )
        std::cout << "The stack seventh is less than or equal to "
            << "the stack eigth." << std::endl;
    else
        std::cout << "The stack seventh is greater than "
            << "the stack eigth." << std::endl;

    if ( seventh <= ninth )
        std::cout << "The stack seventh is less than or equal to "
            << "the stack ninth." << std::endl;
    else
        std::cout << "The stack seventh is greater than "
            << "the stack ninth." << std::endl;

   // Declares stacks with vector base containers
   NAMESPACE::stack<int, std::vector<int> > tenth, eleventh, twelfth;

   // The following would have cause an error because stacks with
   // different base containers are not equality comparable
   // stack <int, list<int> > twelfth;

   tenth.push( 1 );
   eleventh.push( 2 );
   twelfth.push( 1 );

   if ( tenth == eleventh )
      std::cout << "The stacks tenth and eleventh are equal." << std::endl;
   else
      std::cout << "The stacks tenth and eleventh are not equal." << std::endl;

   if ( tenth == twelfth )
      std::cout << "The stacks tenth and twelfth are equal." << std::endl;
   else
      std::cout << "The stacks tenth and twelfth are not equal." << std::endl;

    NAMESPACE::stack<int, std::list<int> > thirteenth, forteenth, fifteenth;

    thirteenth.push( 1 );
    thirteenth.push( 2 );
    thirteenth.push( 3 );
    forteenth.push( 5 );
    forteenth.push( 10 );
    fifteenth.push( 1 );
    fifteenth.push( 2 );

    if ( thirteenth > forteenth )
        std::cout << "The stack thirteenth is greater than "
            << "the stack forteenth." << std::endl;
    else
        std::cout << "The stack thirteenth is not greater than "
            << "the stack forteenth." << std::endl;

    if ( thirteenth > fifteenth )
        std::cout << "The stack thirteenth is greater than "
            << "the stack fifteenth." << std::endl;
    else
        std::cout << "The stack thirteenth is not greater than "
            << "the stack fifteenth." << std::endl;

    NAMESPACE::stack<int, std::list<int> > sixteenth, seventeenth, eighteenth;

    sixteenth.push( 1 );
    sixteenth.push( 2 );
    seventeenth.push( 5 );
    seventeenth.push( 10 );
    eighteenth.push( 1 );
    eighteenth.push( 2 );

    if ( sixteenth >= seventeenth )
        std::cout << "The stack sixteenth is greater than or equal to "
            << "the stack seventeenth." << std::endl;
    else
        std::cout << "The stack sixteenth is less than "
            << "the stack seventeenth." << std::endl;

    if ( sixteenth>= eighteenth )
        std::cout << "The stack sixteenth is greater than or equal to "
            << "the stack eighteenth." << std::endl;
    else
        std::cout << "The stack sixteenth is less than "
            << "the stack eighteenth." << std::endl;
}
