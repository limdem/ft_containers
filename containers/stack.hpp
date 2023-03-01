#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
# include <deque>

namespace ft
{
    template<typename T, typename Container = vector<T> >
    class stack
    {
    public:
        typedef typename Container::value_type   value_type;
        typedef Container   container_type;
        typedef typename Container::size_type    size_type;

        explicit stack(const Container& cntr = Container())
            :c(cntr)
        {}

        stack(const stack& src)
            :c(src.c)
        {}

        ~stack()
        {}

        stack&  operator=(const stack& other)
        {
            c = other.c;
            return *this;
        }

        bool    empty() const
        {
            return c.empty();
        }

        size_type   size() const
        {
            return c.size();
        }

        value_type& top()
        {
            return c.back();
        }

        const value_type&   top() const
        {
            return c.back();
        }

        void    push(const value_type& val)
        {
            return c.push_back(val);
        }

        void    pop()
        {
            return c.pop_back();
        }

            template<typename To, typename Containero>
            friend bool    operator==(const ft::stack<To, Containero>& lo, const ft::stack<To, Containero>& ro);

            template<typename To, typename Containero>
            friend bool    operator!=(const ft::stack<To, Containero>& lo, const ft::stack<To, Containero>& ro);

            template<typename To, typename Containero>
            friend bool    operator<(const ft::stack<To, Containero>& lo, const ft::stack<To, Containero>& ro);

            template<typename To, typename Containero>
            friend bool    operator>(const ft::stack<To, Containero>& lo, const ft::stack<To, Containero>& ro);

            template<typename To, typename Containero>
            friend bool    operator<=(const ft::stack<To, Containero>& lo, const ft::stack<To, Containero>& ro);

            template<typename To, typename Containero>
            friend bool    operator>=(const ft::stack<To, Containero>& lo, const ft::stack<To, Containero>& ro);

    protected:
        container_type  c;
    };

    template<typename T, typename Container>
    bool    operator==(const ft::stack<T, Container>& lo, const ft::stack<T, Container>& ro)
    {
        return lo.c == ro.c;
    }

    template<typename T, typename Container>
    bool    operator!=(const ft::stack<T, Container>& lo, const ft::stack<T, Container>& ro)
    {
        return !(lo == ro);
    }

    template<typename T, typename Container>
    bool    operator<(const ft::stack<T, Container>& lo, const ft::stack<T, Container>& ro)
    {
        return lo.c < ro.c;
    }

    template<typename T, typename Container>
    bool    operator>(const ft::stack<T, Container>& lo, const ft::stack<T, Container>& ro)
    {
        return ro < lo;
    }

    template<typename T, typename Container>
    bool    operator<=(const ft::stack<T, Container>& lo, const ft::stack<T, Container>& ro)
    {
        return !(ro < lo);
    }

    template<typename T, typename Container>
    bool    operator>=(const ft::stack<T, Container>& lo, const ft::stack<T, Container>& ro)
    {
        return !(lo < ro);
    }
}

#endif