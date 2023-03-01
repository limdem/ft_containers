#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "../utils/iterators.hpp"
# include "../utils/traits.hpp"
# include "../utils/nptr.hpp"
# include "../utils/compare.hpp"

namespace   ft
{
    template<typename T, typename Allocator = std::allocator<T> >
    class   vector
    {
    public:
        typedef T                                   value_type;
        typedef Allocator                           allocator_type;
        typedef std::size_t                         size_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef ft::iterator<pointer, vector>       iterator;
        typedef ft::iterator<const_pointer, vector> const_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    private:
        pointer         _start;
        pointer         _finish;
        pointer         _end_of_storage;
        allocator_type  _allocator;

        template<typename ForwardIterator>
        void    fill_value(ForwardIterator  first, size_type n, const value_type& val)
        {
            ForwardIterator it(first);
            try
            {
                for (; n > 0; n--, it++)
                    _allocator.construct(&*it, val);
            }
            catch(const std::exception& e)
            {
                for (; first != it; first++)
                    _allocator.destroy(&*first);
                throw ;
            }
        }

        template<typename InputIterator, typename ForwardIterator>
        ForwardIterator fill_range(InputIterator first, InputIterator last, ForwardIterator position)
        {
            ForwardIterator   it(position);
            try
            {
                for (; first != last; ++first, ++it)
                    _allocator.construct(&*it, *first);    
            }
            catch(const std::exception& e)
            {
                for (; position != it; position++)
                    _allocator.destroy(&*position);
                throw;
            }
            return it;
        }
        
        template<typename InputIterator, typename ForwardIterator>
        void move_range_backward(InputIterator first, InputIterator last, ForwardIterator position)
        {
            while (first != last)
                *--position = *--last;
        }
        
        void    insert_relocate(iterator position, const value_type& val)
        {
            _allocator.construct(_finish, *(_finish - 1));
            ++_finish;
            move_range_backward(position.base(), _finish - 2, _finish - 1);
            *position = val;
        }
        
        size_type   check_allocate(size_type n, const char *message) const
        {
            if (max_size() - size() < n)
                throw std::length_error(message);
            const size_type space = size() + (std::max)(size(), n);
            if (space > max_size())
                return max_size();
            return space;
        }
        
        void    insert_reallocate(iterator position, const value_type& val)
        {
            const size_type   space = check_allocate(1, "vector::insert_reallocate");
            pointer new_start(_allocator.allocate(space));
            pointer new_finish = new_start;
            try
            {
                new_finish = fill_range(begin(), position, new_start);
                _allocator.construct(new_start + (position - begin()), val);
                new_finish++;
                new_finish = fill_range(position, end(), new_finish);
            }
            catch(const std::exception& e)
            {        
                for (pointer    it = new_start; it != new_finish; it++)
                    _allocator.destroy(it);
                _allocator.deallocate(new_start, space);
               throw;
            }
            for (iterator   it = begin(); it != end(); it++)
                _allocator.destroy(it.base());
            _allocator.deallocate(_start, _end_of_storage - _start);
            _start = new_start;
            _finish = new_finish;
            _end_of_storage = _start + space;
        }
    
        void    insert_reallocate(iterator position, size_type n, const value_type& val)
        {
            const size_type space = check_allocate(n, "vector::insert_reallocate");
            const size_type elems_before = position - begin();
            pointer new_start(_allocator.allocate(space));
            pointer new_finish = new_start;
            
            try
            {
                new_finish = fill_range(begin(), position, new_start);
                fill_value(new_start + elems_before, n, val);
                new_finish += n;
                new_finish = fill_range(position, end(), new_finish);
            }
            catch(const std::exception& e)
            {
                for (; new_start != new_finish; new_start++)
                    _allocator.destroy(new_start);
                _allocator.deallocate(new_start, space);
               throw;
            }
            for (iterator   it = begin(); it != end(); it++)
                _allocator.destroy(it.base());
            _allocator.deallocate(_start, _end_of_storage - _start);
            _start = new_start;
            _finish = new_finish;
            _end_of_storage = _start + space;
        }

        template<typename InputIterator>
        void    insert_reallocate(iterator position, InputIterator first, InputIterator last)
        {
            typename iterator_traits<InputIterator>::difference_type    len = ft::distance(first, last);
            const size_type space = check_allocate(len, "vector::insert_reallocate");
            pointer new_start(_allocator.allocate(space));
            pointer new_finish = new_start;
            try
            {
                new_finish = fill_range(begin(), position, new_start);               
                new_finish = fill_range(first, last, new_finish);
                new_finish = fill_range(position, end(), new_finish);
            }
            catch(const std::exception& e)
            {
                for (pointer    it = new_start; it != new_finish; it++)
                    _allocator.destroy(it);
                _allocator.deallocate(new_start, space);
            }
            for (iterator   it = begin(); it != end(); it++)
                _allocator.destroy(it.base());
            _allocator.deallocate(_start, _end_of_storage - _start);
            _start = new_start;
            _finish = new_finish;
            _end_of_storage = _start + space;
        }

        iterator    insert_value(iterator position, const value_type& val)
        {
            const size_type n = position - begin();
            if (_finish != _end_of_storage)
            {
                if (position == end())
                {
                    _allocator.construct(_finish, val);
                    _finish++;
                }    
                else
                    insert_relocate(position, val);
            }
            else
                insert_reallocate(position, val);  
            return iterator(_start + n);
        }

        void    insert_value_range(iterator position, size_type n, const value_type& val)
        {
            if (!n)
                return ;
            if ((size_type)(_end_of_storage - _finish) >= n)
            {
                pointer new_finish;
                pointer  old_finish(_finish);
                
                if ((size_type)(end() - position) > n)
                { 
                    new_finish = move_range(_finish - n, _finish, _finish);
                    move_range_backward(position.base(), old_finish - n, old_finish);
                    fill_value(position, n, val);
                }
                else
                {
                    new_finish = move_range(position.base(), _finish, _finish);
                    fill_value(position, n, val);
                    new_finish += n;
                }
                _finish = new_finish;
            }
            else
                insert_reallocate(position, n, val);          
        }

        template<typename InputIterator>
        void    insert_range(iterator position, InputIterator first, InputIterator last)
        {
            if (first == last)
                return ;
            typename iterator_traits<InputIterator>::difference_type len = ft::distance(first, last);
            if (_end_of_storage - _finish >= len)
            {
                if ((end() - position) > len)
                {   
                    pointer new_finish(fill_range(_finish - len, _finish, _finish));
                    move_range_backward(position.base(), _finish - len, _finish);
                    move_range(first, last, position);
                    _finish = new_finish; 
                }
                else
                {
                    pointer new_finish(move_range(position.base(), _finish, _finish));
                    move_range(first, last, position);
                    _finish = new_finish;
                }
            }
            else
                insert_reallocate(position, first, last);         
        }

        void    erase_at_end(pointer pos)
        {
            pointer save_pos(pos);

            while (pos < _finish)
            {
                _allocator.destroy(pos);
                pos++;
            }
            _finish = save_pos;
        }
        
    public:
        explicit    vector(const allocator_type& allocator = allocator_type())
            :_start(), _finish(), _end_of_storage(), _allocator(allocator)
        {}

        explicit    vector(size_type n, const value_type& val = value_type(), const allocator_type& allocator = allocator_type())
            :_start(), _finish(), _end_of_storage(), _allocator(allocator)
        {
            if (!n)
                return ;
            _start = _allocator.allocate(n);
            _finish = _start + n;
            _end_of_storage = _finish;
            try
            {
                fill_value(_start, n, val);
            }
            catch(const std::exception& e)
            {
                _allocator.deallocate(_start, _end_of_storage - _start);
                throw;
            }    
        }
        
        template<typename InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& allocator = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, ft::nptr_t >::type = ft::nptr)
            :_start(), _finish(), _end_of_storage(), _allocator(allocator)
        {
            typename iterator_traits<InputIterator>::difference_type len = ft::distance(first, last);
            _start = _allocator.allocate(len);
            _finish = _start + len;
            _end_of_storage = _finish;
            try
            {
                fill_range(first, last, begin());
            }
            catch(const std::exception& e)
            {
                _allocator.deallocate(_start, _end_of_storage - _start);
                throw;
            } 
        }

        vector(const vector& src)
            :_allocator(src._allocator)
        {
            _start = _allocator.allocate(src.size());
            _finish = _start + src.size();
            _end_of_storage = _finish;
            try
            {
                fill_range(src.begin(), src.end(), begin());
            }
            catch(const std::exception& e)
            {
                _allocator.deallocate(_start, _end_of_storage - _start);
                throw;
            }
        }

        vector& operator=(const vector& other)
        {
            vector  tmp(other);

            swap(tmp);
            return *this;
        }
        
        ~vector()
        {
            erase_at_end(_start);
            _allocator.deallocate(_start, _end_of_storage - _start);
        }

        iterator    begin()
        {
            return iterator(_start);
        }

        const_iterator  begin() const
        {
            return const_iterator(_start);
        }

        iterator    end()
        {
            return iterator(_finish);
        }

        const_iterator  end() const
        {
            return const_iterator(_finish);
        }

        reverse_iterator    rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator  rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator    rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator  rend() const
        {
            return  const_reverse_iterator(begin());
        }

        size_type   size() const
        {
            return _finish - _start;
        }

        size_type   max_size() const
        {
            return _allocator.max_size();
        }

        void    resize(size_type n, value_type val = value_type())
        {
            if (n > size())
                insert_value_range(end(), n - size(), val);     
            else if (n < size())
                erase_at_end(_start + n);   
        }

        size_type   capacity() const
        {
            return _end_of_storage - _start;
        }

        bool    empty() const
        {
            return begin() == end();
        }

        void    reserve(size_type n)
        {
            if (n > max_size())
                throw std::length_error("vector::reserve");
            if (capacity() < n)
            {
                const size_type space = check_allocate(n, "vector::reserve");
                pointer new_start(_allocator.allocate(space));
                pointer new_finish;
                try
                {
                    new_finish = fill_range(begin(), end(), new_start);
                }
                catch(const std::exception& e)
                {
                    _allocator.deallocate(new_start, space);
                    throw;
                }
                for (iterator   it = begin(); it != end(); it++)
                    _allocator.destroy(it.base());
                _allocator.deallocate(_start, _end_of_storage - _start);
                _start = new_start;
                _finish = new_finish;
                _end_of_storage = _start + space;
            }
        }

        reference   operator[](size_type n)
        {
            return _start[n];
        }

        const_reference operator[](size_type n) const
        {
            return _start[n];
        }

        reference   at(size_type n)
        {
            if (n >= size())
                throw std::out_of_range("position out of range");
            return (*this)[n];
        }

        const_reference at(size_type n) const
        {
            if (n >= size())
                throw std::out_of_range("position out of range");
            return (*this)[n];
        }

        reference   front()
        {
            return *begin();
        }

        const_reference front() const
        {
            return *begin();
        }

        reference   back()
        {
            return *(end() - 1);
        }

        const_reference back() const
        {
            return *(end() - 1);
        }

        value_type* data()
        {
            return  _start;
        }

        const value_type*   data() const
        {
            return _start;
        }

        void    assign(size_type n, const value_type& val)
        {
            if (n > capacity())
            {
                vector  tmp(n, val);
                swap(tmp);
            }
            else
            {
                erase_at_end(_start);
                fill_value(begin(), n, val);
                _finish += n;
            }
            
        }

        template<typename InputIterator>
        void    assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, ft::nptr_t>::type = ft::nptr)
        {
            
            typename iterator_traits<InputIterator>::difference_type len = ft::distance(first, last);
            if (capacity() >= (size_type)len)
            {
                pointer it(_start);
                
                for (; first != last; first++, it++)
                    *it = *first;
                pointer new_finish(it);
                erase_at_end(it);
                _finish = new_finish;
            }
            else
                insert_range(end(), first, last);
            
        }

        void    push_back(const value_type& val)
        {
            if (_finish != _end_of_storage)
            {
                _allocator.construct(_finish, val);
                _finish++;
            }
            else
                insert_reallocate(end(), val);
        }

        void    pop_back()
        {
            if (empty())
                throw std::invalid_argument("vector::pop back");
            _finish--;
            _allocator.destroy(_finish);
        }

        iterator    insert(iterator position, const value_type& val)
        {
            return insert_value(position, val);
        }

        void    insert(iterator position, size_type n, const value_type& val)
        {
            insert_value_range(position, n, val);
        }

        template<typename InputIterator>
        void    insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, ft::nptr_t>::type = ft::nptr)
        {
            insert_range(position, first, last);
        }

        template<typename InputIterator, typename ForwardIterator>
        ForwardIterator    move_range(InputIterator first, InputIterator last, ForwardIterator result)
        {
            for (; first != last; first++, result++)
                *result = *first;
            return result;
        }

        iterator    erase(iterator position)
        {
            if (position + 1 != end()) 
                move_range(position + 1, end(), position);
            _finish--;
            _allocator.destroy(_finish);
            return position;
        }

        iterator    erase(iterator first, iterator last)
        {
            if (first != last)
            {
                if (last != end())
                    move_range(last, end(), first);
                erase_at_end(first.base() + (end() - last));
            }
            return first;
        }

        void    swap(vector& other)
        {
            pointer start_saver(_start);
            pointer finish_saver(_finish);
            pointer _end_of_storage_saver(_end_of_storage);
            allocator_type  allocator_saver(_allocator);

            _start = other._start;
            _finish = other._finish;
            _end_of_storage = other._end_of_storage;
            _allocator = other._allocator;
            other._start = start_saver;
            other._finish = finish_saver;
            other._end_of_storage = _end_of_storage_saver;
            other._allocator = allocator_saver;
        }

        void    clear()
        {
            erase_at_end(_start);
        }

        allocator_type  get_allocator() const
        {
            return _allocator;
        }
    };

    template<typename T, typename Allocator>
    bool    operator==(const ft::vector<T, Allocator>& lo, const ft::vector<T, Allocator>& ro)
    {
        if (lo.size() != ro.size())
            return false ;
        typename ft::vector<T>::const_iterator    it1 = lo.begin();
        typename ft::vector<T>::const_iterator    it2 = ro.begin();
        for (; it1 != lo.end(); it1++, it2++)
        {
            if (*it1 != *it2)
                return false ;  
        }
        return true ;
    }

    template<typename T, typename Allocator>
    bool    operator!=(const ft::vector<T, Allocator>& lo, const ft::vector<T, Allocator>& ro)
    {
        return !(lo == ro);
    }

    template<typename T, typename Allocator>
    bool    operator<(const ft::vector<T, Allocator>& lo, const ft::vector<T, Allocator>& ro)
    {
        return ft::lexicographical_compare(lo.begin(), lo.end(), ro.begin(), ro.end());
    }

    template<typename T, typename Allocator>
    bool    operator>(const ft::vector<T, Allocator>& lo, const ft::vector<T, Allocator>& ro)
    {
        return ro < lo;
    }

    template<typename T, typename Allocator>
    bool    operator<=(const ft::vector<T, Allocator>& lo, const ft::vector<T, Allocator>& ro)
    {
        return !(lo > ro);
    }

    template<typename T, typename Allocator>
    bool    operator>=(const ft::vector<T, Allocator>& lo, const ft::vector<T, Allocator>& ro)
    {
        return !(lo < ro);
    }

    template<typename T, typename Allocator>
    void    swap(ft::vector<T, Allocator>& lo, ft::vector<T, Allocator>& ro)
    {
        lo.swap(ro);
    }
}
#endif