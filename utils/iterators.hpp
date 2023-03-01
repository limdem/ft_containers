#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include "traits.hpp"
# include <iostream>

namespace ft
{ 

    template<typename Iterator>
    class   reverse_iterator
    {
    private:
        Iterator    _current;
        typedef iterator_traits<Iterator>   traits_type;

    public:
        typedef Iterator    iterator_type;
        typedef typename    traits_type::iterator_category  iterator_category;
        typedef typename    traits_type::value_type         value_type;
        typedef typename    traits_type::difference_type    difference_type;
        typedef typename    traits_type::reference          reference;
        typedef typename    traits_type::pointer            pointer;

        reverse_iterator()
            :_current()
        {}

        explicit reverse_iterator(iterator_type it)
            :_current(it)
        {}

        reverse_iterator(const reverse_iterator& src)
            :_current(src._current)
        {}

        template<typename U>
        reverse_iterator(const reverse_iterator<U>& src)
            :_current(src.base())
            
        {}

        iterator_type   base() const
        {
            return _current;
        }

        reference   operator*() const
        {
            Iterator    tmp(_current);
            return *--tmp;
        } 

        reverse_iterator    operator+(difference_type n) const
        {
            return reverse_iterator(_current - n);
        }

        reverse_iterator&   operator++()
        {
            --_current;
            return *this;
        }

        reverse_iterator   operator++(int)
        {
            reverse_iterator    tmp = *this;
            --_current;
            return tmp;
        }

        reverse_iterator&   operator+=(difference_type n)
        {
            _current -= n;
            return *this;
        }

        reverse_iterator    operator-(difference_type n) const
        {
            return reverse_iterator(_current + n);
        }

        reverse_iterator&   operator--()
        {
            ++_current;
            return *this;
        }

        reverse_iterator    operator--(int)
        {
            reverse_iterator    tmp = *this;

            ++_current;
            return tmp;
        }
        
        reverse_iterator&   operator-=(difference_type n)
        {
            _current += n;
            return *this;
        }

        pointer operator->() const
        {
            Iterator    tmp = _current;
            --tmp;
            return &*tmp;
        }

        reference   operator[](difference_type n) const
        {
            return *(*this + n);
        }
    };

    template<typename Iterator>
    bool    operator==(const reverse_iterator<Iterator>& lo, const reverse_iterator<Iterator>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename IteratorL, typename IteratorR>
    bool    operator==(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename Iterator>
    bool    operator!=(const reverse_iterator<Iterator>& lo, const reverse_iterator<Iterator>& ro)
    {
        return !(lo == ro);
    }

    template<typename IteratorL, typename IteratorR>
    bool    operator!=(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return !(lo == ro);
    }

    template<typename Iterator>
    bool    operator<(const reverse_iterator<Iterator>& lo, const reverse_iterator<Iterator>& ro)
    {
        return ro.base() < lo.base();
    }

    template<typename IteratorL, typename IteratorR>
    bool    operator<(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return ro.base() < lo.base();
    }

    template<typename Iterator>
    bool    operator<=(const reverse_iterator<Iterator>& lo, const reverse_iterator<Iterator>& ro)
    {
        return !(ro < lo);
    }

    template<typename IteratorL, typename IteratorR>
    bool    operator<=(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return !(ro < lo);
    }

    template<typename Iterator>
    bool    operator>(const reverse_iterator<Iterator>& lo, const reverse_iterator<Iterator>& ro)
    {
        return ro < lo;
    }

    template<typename IteratorL, typename IteratorR>
    bool    operator>(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return ro < lo;
    }

    template<typename Iterator>
    bool    operator>=(const reverse_iterator<Iterator>& lo, const reverse_iterator<Iterator>& ro)
    {
        return !(lo < ro);
    }

    template<typename IteratorL, typename IteratorR>
    bool    operator>=(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return !(lo < ro);
    }

    template<typename Iterator>
    reverse_iterator<Iterator>  operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return reverse_iterator<Iterator>(rev_it.base() - n);
    }

    template<typename IteratorL, typename IteratorR>
    typename reverse_iterator<IteratorL>::difference_type    operator-(const reverse_iterator<IteratorL>& lo, const reverse_iterator<IteratorR>& ro)
    {
        return ro.base() - lo.base();
    } 

    template<typename Iterator, typename Container>
    class   iterator
    {
    private:
        Iterator   _current;
        typedef std::iterator_traits<Iterator>    traits_type;

    public:
        typedef Iterator    iterator_type;
        typedef typename traits_type::iterator_category iterator_category;
        typedef typename traits_type::value_type        value_type;
        typedef typename traits_type::difference_type   difference_type;
        typedef typename traits_type::reference         reference;
        typedef typename traits_type::pointer           pointer;

        iterator()
            :_current()
        {}
        
        iterator(const iterator_type& current)
            :_current(current)
        {}

        iterator(const iterator& src)
            :_current(src._current)
        {}
        
        ~iterator()
        {}
        
        
        template<typename Iter>
        iterator(const iterator<Iter,
			  typename ft::enable_if<ft::is_same<Iter, typename Container::pointer>::value, Container >::type>& __i)
        : _current(__i.base())
        {}

        const Iterator&    base() const
        {
            return _current;
        }

        reference   operator*() const
        {
            return *_current;
        }

        iterator    operator+(difference_type n) const
        {
            return iterator(_current + n);
        }

        iterator&   operator++()
        {
            ++_current;
            return *this;
        }

        iterator    operator++(int)
        {
            return iterator(_current++);
        }

        iterator&   operator+=(difference_type n)
        {
            _current += n;
            return *this;
        }

        iterator    operator-(difference_type n) const
        {
            return iterator(_current - n);
        }

        iterator&   operator--()
        {
            --_current;
            return *this;
        }

        iterator    operator--(int)
        {
            return iterator(_current--);
        }

        iterator&   operator-=(difference_type n)
        {
            _current -= n;
            return *this;
        }

        pointer operator->() const
        {
            return _current;
        }

        reference   operator[](difference_type n)
        {
            return _current[n];
        }
    };

    template<typename Iterator, typename Container>
    bool    operator==(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    bool    operator==(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename Iterator, typename Container>
    bool    operator!=(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return !(lo == ro);
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    bool    operator!=(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return !(lo == ro);
    }

    template<typename Iterator, typename Container>
    bool    operator<(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return lo.base() < ro.base();
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    bool    operator<(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return lo.base() < ro.base();
    }

    template<typename Iterator, typename Container>
    bool    operator<=(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return !(lo > ro);
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    bool    operator<=(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return !(lo > ro);
    }

    template<typename Iterator, typename Container>
    bool    operator>(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return ro < lo;
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    bool    operator>(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return ro < lo;
    }

    template<typename Iterator, typename Container>
    bool    operator>=(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return !(lo < ro);
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    bool    operator>=(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return !(lo < ro);
    }

    template<typename Iterator, typename Container>
    iterator<Iterator, Container>   operator+(typename iterator<Iterator, Container>::difference_type n, const iterator<Iterator, Container>& it)
    {
        return iterator<Iterator, Container>(it.base() + n);
    }

    template<typename Iterator, typename Container>
    typename iterator<Iterator, Container>::difference_type operator-(const iterator<Iterator, Container>& lo, const iterator<Iterator, Container>& ro)
    {
        return lo.base() - ro.base();
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    typename iterator<IteratorL, Container>::difference_type    operator-(const iterator<IteratorL, Container>& lo, const iterator<IteratorR, Container>& ro)
    {
        return lo.base() - ro.base();
    }

    template<typename InputIterator>
    typename iterator_traits<InputIterator>::difference_type    distance(InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type    n = 0;
        for (; first != last; ++first, ++n);
        return n;
    }
}
#endif