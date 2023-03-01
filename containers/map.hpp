#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "../utils/compare.hpp"
# include "../utils/pair.hpp"
# include "../utils/Rb_tree.hpp"

namespace ft
{
    template<typename Key, typename T, typename Compare = less<Key>, typename Allocator = std::allocator<pair<const Key, T> > >
    class   map
    {
    public:
        typedef Key key_type;
        typedef T   mapped_type;
        typedef pair<const key_type, mapped_type>   value_type;
        typedef Compare key_compare;
        typedef Allocator   allocator_type;
        typedef value_type&  reference;
        typedef const value_type&   const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

    private:
        typedef Rb_tree<key_type, value_type, Select1st<value_type>, key_compare, allocator_type>  Rb_tree_type;
        Rb_tree_type    _Rb_tree_hdl;

    public:
        typedef typename Rb_tree_type::size_type    size_type;
        typedef typename Rb_tree_type::difference_type  difference_type;
        typedef typename Rb_tree_type::iterator iterator;
        typedef typename Rb_tree_type::const_iterator   const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

    public:
        class   value_compare
        {
            friend class map;
        protected:
            key_compare comp;
            value_compare(key_compare c)
                :comp(c)
            {}
        public:
            bool    operator()(const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
        };

        explicit    map(const key_compare& comp = key_compare(), const allocator_type& allocator = allocator_type())
            :_Rb_tree_hdl(comp, allocator)
        {}

        template<typename InputIterator>
        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& allocator = allocator_type())
            :_Rb_tree_hdl(comp, allocator)
        {
            _Rb_tree_hdl.insert_range(first, last);
        }

        map(const map& src)
            :_Rb_tree_hdl(src._Rb_tree_hdl)
        {}

        ~map(){}

        map&    operator=(const map& other)
        {
            map tmp(other);
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

        const_reverse_iterator    rend() const
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

        mapped_type&    operator[](const key_type& k)
        {
            iterator    it(lower_bound(k));
            if (it == end() || key_compare()(k, (*it).first))
                it = insert(it, ft::make_pair<key_type, mapped_type>(k, mapped_type()));
            return (*it).second;
        }

        mapped_type&    at(const key_type& k)
        {
            iterator    it(lower_bound(k));
            if (it == end() || key_compare()(k, (*it).first))
                throw std::out_of_range("map::at");
            return (*it).second;
        }

        const mapped_type&    at(const key_type& k) const
        {
            iterator    it(lower_bound(k));
            if (it == end() || key_compare()(k, (*it).first))
                throw std::out_of_range("map::at");
            return (*it).second;
        }

        pair<iterator, bool>    insert(const value_type& val)
        {
            return _Rb_tree_hdl.insert_node(val);
        }

        iterator    insert(iterator position, const value_type& val)
        {
            return iterator(_Rb_tree_hdl.insert_node(position, val));
        }

        template<typename InputIterator>
        void    insert(InputIterator first, InputIterator last)
        {
           _Rb_tree_hdl.insert_range(first, last); 
        }

        void    erase(iterator position)
        {
            _Rb_tree_hdl.erase(position);
        }

        size_type   erase(const key_type& k)
        {
            return _Rb_tree_hdl.erase(k);
        }


        void    erase(iterator first, iterator last)
        {
            _Rb_tree_hdl.erase(first, last);    
        }

        void    swap(map& other)
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
            return value_compare(key_comp());
        }

        iterator    find(const key_type& k)
        {
            return _Rb_tree_hdl.find(k);
        }

        const_iterator  find(const key_type& k) const
        {
            return _Rb_tree_hdl.find(k);
        }

        size_type   count(const key_type& k) const
        {
            return _Rb_tree_hdl.count(k);
        }

        iterator    lower_bound(const key_type& k)
        {
            return _Rb_tree_hdl.lower_bound(k);
        }

        const_iterator  lower_bound(const key_type& k) const
        {
            return _Rb_tree_hdl.lower_bound(k);
        }

        iterator    upper_bound(const key_type& k)
        {
            return _Rb_tree_hdl.upper_bound(k);
        }

        const_iterator  upper_bound(const key_type& k) const
        {
            return _Rb_tree_hdl.upper_bound(k);
        }

        pair<iterator, iterator>   equal_range(const key_type& k)
        {
            return _Rb_tree_hdl.equal_range(k);
        }

        pair<const_iterator, const_iterator>    equal_range(const key_type& k) const
        {
            return _Rb_tree_hdl.equal_range(k);
        }

        allocator_type  get_allocator() const
        {
            return allocator_type();
        }

        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend bool    operator==(const ft::map<Keyo, To, Compareo, Allocatoro>& lo, const ft::map<Keyo, To, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend bool    operator!=(const ft::map<Keyo, To, Compareo, Allocatoro>& lo, const ft::map<Keyo, To, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend bool    operator<(const ft::map<Keyo, To, Compareo, Allocatoro>& lo, const ft::map<Keyo, To, Compareo, Allocatoro>& ro);


        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend bool    operator>(const ft::map<Keyo, To, Compareo, Allocatoro>& lo, const ft::map<Keyo, To, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend bool    operator<=(const ft::map<Keyo, To, Compareo, Allocatoro>& lo, const ft::map<Keyo, To, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend bool    operator>=(const ft::map<Keyo, To, Compareo, Allocatoro>& lo, const ft::map<Keyo, To, Compareo, Allocatoro>& ro);

        template<typename Keyo, typename To, typename Compareo, typename Allocatoro>
        friend void    swap(ft::map<Keyo, To, Compareo, Allocatoro>& lo, ft::map<Keyo, To, Compareo, Allocatoro>& ro);
    };

    template<typename Key, typename T, typename Compare, typename Allocator>
    bool    operator==(const ft::map<Key, T, Compare, Allocator>& lo, const ft::map<Key, T, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl == ro._Rb_tree_hdl;
    }

    template<typename Key, typename T, typename Compare, typename Allocator>
    bool    operator!=(const ft::map<Key, T, Compare, Allocator>& lo, const ft::map<Key, T, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl != ro._Rb_tree_hdl;
    }

    template<typename Key, typename T, typename Compare, typename Allocator>
    bool    operator<(const ft::map<Key, T, Compare, Allocator>& lo, const ft::map<Key, T, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl < ro._Rb_tree_hdl;
    }

    template<typename Key, typename T, typename Compare, typename Allocator>
    bool    operator>(const ft::map<Key, T, Compare, Allocator>& lo, const ft::map<Key, T, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl > ro._Rb_tree_hdl;
    }

    template<typename Key, typename T, typename Compare, typename Allocator>
    bool    operator<=(const ft::map<Key, T, Compare, Allocator>& lo, const ft::map<Key, T, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl <= ro._Rb_tree_hdl;
    }

    template<typename Key, typename T, typename Compare, typename Allocator>
    bool    operator>=(const ft::map<Key, T, Compare, Allocator>& lo, const ft::map<Key, T, Compare, Allocator>& ro)
    {
        return lo._Rb_tree_hdl >= ro._Rb_tree_hdl;
    }

    template<typename Key, typename T, typename Compare, typename Allocator>
    void    swap(ft::map<Key, T, Compare, Allocator>& lo, ft::map<Key, T, Compare, Allocator>& ro)
    {
        lo.swap(ro);
    }
}

#endif