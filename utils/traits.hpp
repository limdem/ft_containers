#ifndef TRAITS_HPP
# define TRAITS_HPP

namespace ft
{
    template<typename T, T v>
    struct  integral_constant
    {
        static const T    value = v;
        typedef T   value_type;
        typedef integral_constant<T, v> type;
        operator bool () { return v;}
    };
    
    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>   false_type;

    template<class T, class U>
    struct is_same : false_type {};
    
    template<class T>
    struct is_same<T, T> : true_type {}; 

    template<typename>
    struct  is_integral_type
        : public false_type{};

    template<>
    struct  is_integral_type<bool>
        : public true_type {};

    template<>
    struct  is_integral_type<char>
        : public true_type {};

    template<>
    struct  is_integral_type<signed char>
        : public true_type {};

    template<>
    struct  is_integral_type<short int>
        : public true_type {};

    template<>
    struct  is_integral_type<int>
        : public true_type {};

    template<>
    struct  is_integral_type<long int>
        : public true_type {};

    template<>
    struct  is_integral_type<long long int>
        : public true_type {};

    template<>
    struct  is_integral_type<unsigned char>
        : public true_type {};

    template<>
    struct  is_integral_type<unsigned short int>
        : public true_type {};

    template<>
    struct  is_integral_type<unsigned int>
        : public true_type {};

    template<>
    struct  is_integral_type<unsigned long int>
        : public true_type {};

    template<>
    struct  is_integral_type<unsigned long long int>
        : public true_type {};

    template<typename Tp>
    struct  is_integral
        : public is_integral_type<Tp>::type
    {};

    template<bool Condition, typename T = void>
    struct  enable_if
    {};

    template<typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    struct input_iterator_tag { };

    struct  output_iterator_tag {};

    struct  forward_iterator_tag: public input_iterator_tag {};

    struct  bidirectional_iterator_tag: public forward_iterator_tag {};

    struct  random_access_iterator_tag: public bidirectional_iterator_tag {};

    template<typename Iterator>
    struct  iterator_traits
    {
        typedef typename    Iterator::iterator_category iterator_category;
        typedef typename    Iterator::value_type        value_type;
        typedef typename    Iterator::difference_type   difference_type;
        typedef typename    Iterator::pointer           pointer;
        typedef typename    Iterator::reference         reference;
    };

    template<typename Tp>
    struct  iterator_traits<Tp*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef Tp                          value_type;
        typedef std::ptrdiff_t              difference_type;
        typedef Tp*                         pointer;
        typedef Tp&                         reference;
    };

    template<typename Tp>
    struct  iterator_traits<const Tp*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef Tp                          value_type;
        typedef std::ptrdiff_t              difference_type;
        typedef const Tp*                   pointer;
        typedef const Tp&                   reference;
    };
}
#endif