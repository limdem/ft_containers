#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template<typename Tp>
    struct Identity
    {
        Tp& operator()(Tp& x) const
        {
            return x;
        }

        const Tp&   operator()(const Tp& x) const
        {
            return x;
        }
    };

    template<typename Pair>
    struct  Select1st
    {
        typename Pair::first_type&  operator()(Pair& x) const
        {
            return x.first;
        }

        const typename Pair::first_type&    operator()(const Pair& x) const
        {
            return x.first;
        }

        template<typename Pair2>
        typename Pair2::first_type& operator()(Pair2 x) const
        {
            return x.first;
        }

        template<typename Pair2>
        const typename Pair2::first_type&   operator()(const Pair2& x) const
        {
            return x.first;
        }
    };

    template<typename T1, typename T2>
    struct  pair
    {
        typedef T1  first_type;
        typedef T2  second_type;

        T1  first;
        T2  second;

        pair()
            :first(), second()
        {}

        pair(const first_type& a, const second_type& b)
            :first(a), second(b)
        {}

        
        template<typename U, typename V>
        pair(const pair<U, V>& pr)
            :first(pr.first), second(pr.second)
        {}
    };

    template<typename T1, typename T2>
    ft::pair<T1, T2>  make_pair(T1 x, T2 y)
    {
        return ft::pair<T1, T2>(x, y);
    }

    template<typename T1, typename T2>
    bool    operator==(const ft::pair<T1, T2>& lo, const ft::pair<T1, T2>& ro)
    {
        return (lo.first == ro.first && lo.second == ro.second);
    }

    template<typename T1, typename T2>
    bool    operator!=(const ft::pair<T1, T2>& lo, const ft::pair<T1, T2>& ro)
    {
        return !(lo == ro);
    }

    template<typename T1, typename T2>
    bool    operator<(const ft::pair<T1, T2>& lo, const ft::pair<T1, T2>& ro)
    {
        if (lo.first < ro.first)
            return true;
        if (lo.first == ro.first && lo.second < ro.second)
            return true;
        return false;
    }

    template<typename T1, typename T2>
    bool    operator>(const ft::pair<T1, T2>& lo, const ft::pair<T1, T2>& ro)
    {
        return ro < lo;
    }

    template<typename T1, typename T2>
    bool    operator<=(const ft::pair<T1, T2>& lo, const ft::pair<T1, T2>& ro)
    {
        return !(lo > ro);
    }

    template<typename T1, typename T2>
    bool    operator>=(const ft::pair<T1, T2>& lo, const ft::pair<T1, T2>& ro)
    {
        return !(lo < ro);
    }
}
#endif