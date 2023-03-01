#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include "../utils/compare.hpp"
# include "../utils/pair.hpp"
# include "../utils/Rb_tree.hpp"

namespace ft
{
    template<typename T, typename Compare = less<T>, typename Allocator = std::allocator<T> >
    class set
    {
    public:
        typedef T key_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;

    private:
        typedef Rb_tree<key_type, value_type, Identity<value_type>, key_compare, allocator_type>    Rb_tree_type;
        Rb_tree_type    _Rb_tree_hdl;

    public:
        typedef typename Rb_tree_type::size_type    size_type;
        typedef typename Rb_tree_type::difference_type  difference_type;
        typedef typename Rb_tree_type::const_iterator iterator;
        typedef typename Rb_tree_type::const_iterator   const_iterator;
        typedef typename ft::reverse_iterator<const_iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
    

        explicit set(const key_compare& comp = key_compare(), const allocator_type& allocator = allocator_type())
            :_Rb_tree_hdl(comp, allocator)
        {}

        template<typename InputIterator>
        set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& allocator = allocator_type())
            :_Rb_tree_hdl(comp, allocator)
        {
            _Rb_tree_hdl.insert_range(first, last);
        }

        set(const set& src)
            :_Rb_tree_hdl(src._Rb_tree_hdl)
        {}

        ~set(){}

        set&    operator=(const set& other)
        {
            set tmp(other);
            swap(tmp);
            return *this;
        }

        iterator    begin()
        {
            return _Rb_tree_hdl.begin();
        }

        const_iterator  begin() const
        {
            return _Rb_tree_hdl.begin();
        }

        iterator    end()
        {
            return _Rb_tree_hdl.end();
        }

        const_iterator  end() const
        {
            return _Rb_tree_hdl.end();
        }

        reverse_iterator    rbegin()
        {
            return _Rb_tree_hdl.rbegin();
        }

        const_reverse_iterator  rbegin() const
        {
            return _Rb_tree_hdl.rbegin();
        }

        reverse_iterator    rend()
        {
            return _Rb_tree_hdl.rend();
        }

        const_reverse_iterator  rend() const
        {
            return _Rb_tree_hdl.rend();
        }

        bool    empty() const
        {
            return _Rb_tree_hdl.empty();
        }

        size_type   size() const
        {
            return _Rb_tree_hdl.size();
        }

        size_type   max_size() const
        {
            return _Rb_tree_hdl.max_size();
        }

        pair<iterator, bool>    insert(const value_type& val)
        {
            return _Rb_tree_hdl.insert_node(val);
        }

        iterator    insert(iterator position, const value_type& val)
        {
            return _Rb_tree_hdl.insert_node(position, val);
        }

        template<typename InputIterator>
        void    insert(InputIterator first, InputIterator last)
        {
            return _Rb_tree_hdl.insert_range(first, last);
        }

        void    erase(iterator position)
        {
            _Rb_tree_hdl.erase(position);
        }

        size_type   erase(const value_type& val)
        {
            return _Rb_tree_hdl.erase(val);
        }

        void    erase(iterator first, iterator last)
        {
            _Rb_tree_hdl.erase(first, last);
        }

        void    swap(set& other)
        {
            _Rb_tree_hdl.swap(other._Rb_tree_hdl);
        }

        void    clear()
        {
            _Rb_tree_hdl.clear();
        }

        key_compare key_comp() const
        {
            return _Rb_tree_hdl.key_comp();
        }

        value_compare   value_comp() const
        {
            return _Rb_tree_hdl.key_comp();
        }

        iterator    find(const value_type& val)
        {
            return _Rb_tree_hdl.find(val);
        }

        const_iterator    find(const value_type& val) const
        {
            return _Rb_tree_hdl.find(val);
        }

        size_type   count(const value_type& val) const
        {
            return _Rb_tree_hdl.count(val);
        }

        iterator    lower_bound(const value_type& val)
        {
            return _Rb_tree_hdl.lower_bound(val);
        }

        const_iterator  lower_bound(const value_type& val) const
        {
            return _Rb_tree_hdl.lower_bound(val);
        }

        iterator    upper_bound(const value_type& val)
        {
            return _Rb_tree_hdl.upper_bound(val);
        }

        const_iterator    upper_bound(const value_type& val) const
        {
            return _Rb_tree_hdl.upper_bound(val);
        }

        pair<iterator, iterator>    equal_range(const value_type& val)
        {
            return _Rb_tree_hdl.equal_range(val);
        }

        pair<const_iterator, const_iterator>    equal_range(const key_type& k) const
        {
            return _Rb_tree_hdl.equal_range(k);
        }

        allocator_type  get_allocator() const
        {
            return allocator_type();
        }

        template<typename Keyo, typename Compareo, typename Allocatoro>
        friend bool operator==(const ft::set<Keyo, Compareo, Allocatoro>& lo, const ft::set<Keyo, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename Compareo, typename Allocatoro>
        friend bool operator!=(const ft::set<Keyo, Compareo, Allocatoro>& lo, const ft::set<Keyo, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename Compareo, typename Allocatoro>
        friend bool operator<(const ft::set<Keyo, Compareo, Allocatoro>& lo, const ft::set<Keyo, Compareo, Allocatoro>& ro);


        template<typename Keyo, typename Compareo, typename Allocatoro>
        friend bool operator>(const ft::set<Keyo, Compareo, Allocatoro>& lo, const ft::set<Keyo, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename Compareo, typename Allocatoro>
        friend bool operator<=(const ft::set<Keyo, Compareo, Allocatoro>& lo, const ft::set<Keyo, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename Compareo, typename Allocatoro>
        friend bool operator>=(const ft::set<Keyo, Compareo, Allocatoro>& lo, const ft::set<Keyo, Compareo, Allocatoro>& ro);
    };
    
    template<typename Key, typename Compare, typename Allocator>
    bool    operator==(const ft::set<Key, Compare, Allocator>& lo, const ft::set<Key, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl == ro._Rb_tree_hdl;
    }

    template<typename Key, typename Compare, typename Allocator>
    bool    operator!=(const ft::set<Key, Compare, Allocator>& lo, const ft::set<Key, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl != ro._Rb_tree_hdl;
    }

    template<typename Key, typename Compare, typename Allocator>
    bool    operator<(const ft::set<Key, Compare, Allocator>& lo, const ft::set<Key, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl < ro._Rb_tree_hdl;
    }

    template<typename Key, typename Compare, typename Allocator>
    bool    operator>(const ft::set<Key, Compare, Allocator>& lo, const ft::set<Key, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl > ro._Rb_tree_hdl;
    }

    template<typename Key, typename Compare, typename Allocator>
    bool    operator<=(const ft::set<Key, Compare, Allocator>& lo, const ft::set<Key, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl <= ro._Rb_tree_hdl;
    }

    template<typename Key, typename Compare, typename Allocator>
    bool    operator>=(const ft::set<Key, Compare, Allocator>& lo, const ft::set<Key, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl >= ro._Rb_tree_hdl;
    }   
}
#endif