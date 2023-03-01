#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include "pair.hpp"
# include "compare.hpp"
# include "traits.hpp"
# include "iterators.hpp"

#include <iostream>

namespace ft
{
    enum    Rb_tree_color
    {
        N_red = false,
        N_black = true
    };

    template<typename Val>
    struct  Rb_tree_node
    {
        typedef Rb_tree_node*  Node_ptr;
        typedef const Rb_tree_node*    Const_Node_ptr;

        Rb_tree_color   node_color;
        Node_ptr    node_parent;
        Node_ptr    node_left;
        Node_ptr    node_right;
        Val         value_pair;
        
        static Node_ptr    minimum(Node_ptr node)
        {
            while (node->node_left)
                node = node->node_left;
            return node;
        }

        static Node_ptr    maximum(Node_ptr node)
        {
            while (node->node_right)
                node = node->node_right;
            return node;
        }
    };

    template<typename Key_compare>
    struct  Rb_tree_key_compare
    {
        Key_compare _key_compare;

        Rb_tree_key_compare()
            :_key_compare()
        {}

        Rb_tree_key_compare(const Key_compare& comp)
            :_key_compare(comp)
        {}
    };

    template<typename Tp>
    struct  Rb_tree_header
    {
        Rb_tree_node<Tp>    _tree_header;
        std::size_t              _node_count;

        Rb_tree_header()
        {
            reset();
        }
        
        Rb_tree_header(std::size_t node_count)
        {
            reset();
            _node_count = node_count;
        }
        
        void    reset()
        {
            _tree_header.node_color = N_red;
            _tree_header.node_parent = 0;
            _tree_header.node_left = &_tree_header;
            _tree_header.node_right = &_tree_header;
            _node_count = 0;
        }
    };

    template<typename Tp>
    struct  Rb_tree_iterator
    {
        typedef Tp  value_type;
        typedef Tp& reference;
        typedef Tp* pointer;
        typedef std::bidirectional_iterator_tag  iterator_category;
        typedef std::ptrdiff_t   difference_type;
        typedef Rb_tree_iterator<Tp>    Self;
        typedef typename Rb_tree_node<Tp>::Node_ptr Node_ptr;
        typedef Rb_tree_node<Tp>*   Link_type;

        Rb_tree_iterator()
            :_node()
        {}

        explicit Rb_tree_iterator(Node_ptr x)
            :_node(x)
        {}
        
        Rb_tree_iterator(const Rb_tree_iterator& src)
            :_node(src._node)
        {}
        
        reference   operator*() const
        {
            return _node->value_pair;
        }

        pointer operator->() const
        {
            return  &_node->value_pair;
        }

        Self&   operator++()
        {
            tree_iterator_increment();
            return *this;
        }

        Self    operator++(int)
        {
            Self    tmp(*this);
            tree_iterator_increment();
            return tmp;
        }

        Self&   operator--()
        {
            tree_iterator_decrement();
            return *this;
        }

        Self    operator--(int)
        {
            Self    tmp(*this);
            tree_iterator_decrement();
            return tmp;
        }

        Node_ptr    base() const
        {
            return _node;
        }
    private:
        Node_ptr    _node;

    private:
        void    tree_iterator_increment()
        {
            if (_node->node_right)
            {
                _node = _node->node_right;
                while (_node->node_left)
                    _node = _node->node_left;
            }
            else
            {
                Node_ptr    parent(_node->node_parent);
                while (parent->node_right == _node)
                {
                    _node = parent;
                    parent = parent->node_parent;
                }
                if (_node->node_right != parent)
                    _node = parent;
            }
        }

        void  tree_iterator_decrement()
        {
            if (_node->node_parent->node_parent == _node && _node->node_color == N_red)
                _node = _node->node_right;
            else if (_node->node_left)
            {
                _node = _node->node_left;
                while (_node->node_right)
                    _node = _node->node_right;   
            }
            else
            {
                Node_ptr    parent(_node->node_parent);
                while (parent->node_left == _node)
                {
                    _node = parent;
                    parent = parent->node_parent;
                }
                _node = parent;
            }
        }
    };
    
    template<typename Tp>
    struct  Rb_tree_const_iterator
    {
        typedef Tp  value_type;
        typedef const Tp& reference;
        typedef const Tp* pointer;
        typedef Rb_tree_iterator<Tp>    iterator;
        typedef std::bidirectional_iterator_tag  iterator_category;
        typedef std::ptrdiff_t   difference_type;
        typedef Rb_tree_const_iterator<Tp>    Self;
        typedef typename Rb_tree_node<Tp>::Const_Node_ptr Node_ptr;
        typedef const Rb_tree_node<Tp>*   Link_type;

        Rb_tree_const_iterator()
            :_node()
        {}

        explicit Rb_tree_const_iterator(Node_ptr x)
            :_node(x)
        {}

        Rb_tree_const_iterator(const iterator& it)
            :_node(it.base())
        {}

        reference   operator*() const
        {
            return _node->value_pair;
        }

        pointer operator->() const
        {
            return &_node->value_pair;
        }

        Self&   operator++()
        {
            tree_iterator_increment();
            return *this;
        }

        Self    operator++(int)
        {
            Self    tmp(*this);
            tree_iterator_increment();
            return tmp;
        }

        Self&   operator--()
        {
            tree_iterator_decrement();
            return *this;
        }

        Self    operator--(int)
        {
            Self    tmp(*this);
            tree_iterator_decrement();
            return tmp;
        }

        Node_ptr    base() const
        {
            return _node;
        }

    private:
        Node_ptr    _node;

        void    tree_iterator_increment()
        {
            if (_node->node_right)
            {
                _node = _node->node_right;
                while (_node->node_left)
                    _node = _node->node_left;
            }
            else
            {
                Node_ptr    parent(_node->node_parent);
                while (parent->node_right == _node)
                {
                    _node = parent;
                    parent = parent->node_parent;
                }
                if (_node->node_right != parent)
                    _node = parent;
            }
        }

        void  tree_iterator_decrement()
        {
            if (_node->node_parent->node_parent == _node && _node->node_color == N_red)
                _node = _node->node_right;
            else if (_node->node_left)
            {
                _node = _node->node_left;
                while (_node->node_right)
                    _node = _node->node_right;   
            }
            else
            {
                Node_ptr    parent(_node->node_parent);
                while (parent->node_left == _node)
                {
                    _node = parent;
                    parent = parent->node_parent;
                }
                _node = parent;
            }
        }
    };

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<Val> >
    class   Rb_tree
    {
    public:

        template<typename Type>
        struct  rebind
        {
            typedef std::allocator<Type>    other;
        };
        typedef typename rebind<Rb_tree_node<Val> >::other  Node_allocator;

        typedef Rb_tree_node<Val>*  Node_ptr;
        typedef const Rb_tree_node<Val>*    Const_Node_ptr;
        typedef Allocator   allocator_type;
        typedef Key key_type;
        typedef Val value_type;
        typedef value_type* pointer;
        typedef const value_type*   const_pointer;
        typedef value_type& reference;
        typedef const value_type&   const_reference;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t  difference_type;
        typedef Rb_tree_iterator<value_type>    iterator;
        typedef Rb_tree_const_iterator<value_type>  const_iterator;
        typedef ft::reverse_iterator<iterator>  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

        Node_allocator& get_Node_allocator()
        {
            return this->_tree_wrpr;
        }

        const Node_allocator& get_Node_allocator() const
        {
            return _tree_wrpr;
        }

        template<typename Arg>
        void    construct_node(Node_ptr node, Arg arg)
        {
            get_Node_allocator().construct(node, Rb_tree_node<Arg>());
            try
            {
                allocator_type().construct(&node->value_pair, arg);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                get_Node_allocator().destroy(node);
                throw;
            }
        }

        template<typename Arg>
        Node_ptr  create_node(Arg& arg)
        {
            Node_ptr   node = get_Node_allocator().allocate(1);

            try
            {
                construct_node(node, arg);
            }
            catch(const std::exception& e)
            {
                get_Node_allocator().deallocate(node, 1);
                throw;
            }
            node->node_left = 0;
            node->node_right = 0;
            node->node_color = N_red;
            return node;        
        }

        Node_ptr   copy_node(Const_Node_ptr node)
        {
            Node_ptr    new_node(get_Node_allocator().allocate(1));
            try
            {
                construct_node(new_node, node->value_pair);
                new_node->node_left = 0;
                new_node->node_right = 0;
                new_node->node_color = node->node_color;
            }
            catch(const std::exception& e)
            {
                get_Node_allocator().deallocate(new_node, 1);
                throw;
            }
            return new_node;
        }

        void    drop_node(Node_ptr p)
        {
            get_Node_allocator().destroy(p);
            get_Node_allocator().deallocate(p, 1);
        }
        
    private:
        template<typename Key_compare>
        struct Rb_tree_wrapper
            : public Node_allocator, public Rb_tree_key_compare<Key_compare>, public Rb_tree_header<value_type>
        {
            typedef Rb_tree_key_compare<Key_compare>    Base_key_compare;
            typedef Rb_tree_header<value_type>  Base_tree_header;
            Rb_tree_wrapper()
            {}

            Rb_tree_wrapper(const Key_compare& comp, const allocator_type& a)
                : Node_allocator(a), Base_key_compare(comp), Rb_tree_header<value_type>()
            {}

            Rb_tree_wrapper(const Rb_tree_wrapper& src)
                : Node_allocator(src), Base_key_compare(src._key_compare), Base_tree_header(src._node_count)
            {}   
        };
        
        Rb_tree_wrapper<Compare> _tree_wrpr;

        static Node_ptr minimum(Node_ptr node)
        {
            return Rb_tree_node<value_type>::minimum(node);
        }

        static Node_ptr maximum(Node_ptr node)
        {
            return Rb_tree_node<value_type>::maximum(node);
        }

    public:
        Rb_tree(const Compare& comp, const allocator_type& a = allocator_type())
            :_tree_wrpr(comp, Node_allocator(a))
        {}

        Rb_tree(const Rb_tree& src)
            :_tree_wrpr(src._tree_wrpr)
        {
            if (src._tree_wrpr._tree_header.node_parent)
            {
                Node_ptr   z = copy_node(src.T_begin());
                _tree_wrpr._tree_header.node_parent = z;
                _tree_wrpr._tree_header.node_left = z;
                _tree_wrpr._tree_header.node_right = z;
                z->node_parent = &_tree_wrpr._tree_header;
                copy_tree(src.T_begin(), z);
                _tree_wrpr._tree_header.node_left = minimum(_tree_wrpr._tree_header.node_parent);
                _tree_wrpr._tree_header.node_right = maximum(_tree_wrpr._tree_header.node_parent);
            }
                
        }

        ~Rb_tree()
        {
            R_erase(T_begin());
        }

        iterator    begin()
        {
            return iterator(_tree_wrpr._tree_header.node_left);
        }

        const_iterator  begin() const
        {
            return const_iterator(_tree_wrpr._tree_header.node_left);
        }

        iterator    end()
        {
            return iterator(&_tree_wrpr._tree_header);
        }

        const_iterator  end() const
        {
            return const_iterator(&_tree_wrpr._tree_header);
        }

        reverse_iterator    rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator    rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator    rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator  rend() const
        {
            return const_reverse_iterator(begin());
        }

        Node_ptr   T_begin()
        {
            return _tree_wrpr._tree_header.node_parent;
        }
        
        Const_Node_ptr T_begin() const
        {
            return _tree_wrpr._tree_header.node_parent;
        }

        Node_ptr    T_end()
        {
            return &_tree_wrpr._tree_header;
        }

        Const_Node_ptr    T_end() const
        {
            return &_tree_wrpr._tree_header;
        }

        void    R_erase(Node_ptr x)
        {
            while (x != 0)
            {
                R_erase(x->node_right);
                Node_ptr    y = x->node_left;
                drop_node(x);
                x = y;
            }
        }

        template<typename KeyArg>
        iterator    get_node_pos(KeyArg& key, bool *equivalent_key)
        {
            
            Node_ptr    x = T_begin();
            Node_ptr    y = T_end();
            bool    direction;

            if (!_tree_wrpr._node_count)
                return iterator(y);
            while (x != 0)
            {
                y = x;
                direction = _tree_wrpr._key_compare(key, KeyOfValue()(x->value_pair));
                if (direction)
                    x = x->node_left;
                else
                    x = x->node_right;
            }
            iterator   it(y); 
            if (direction)
            {
                if (it == begin())
                    return iterator(y);
                it--;
            }
            if (_tree_wrpr._key_compare(KeyOfValue()(*it), key))
                return iterator(y);
            *equivalent_key = true;
            return iterator(it);
            

        }

        template<typename KeyArg>
        iterator    get_node_pos_hint(const_iterator position, KeyArg& key, bool *equivalent_key)
        {
            Node_ptr    pos_base = const_cast<Node_ptr>(position.base());
            if (position == end())
            {
                if (_tree_wrpr._key_compare(key, KeyOfValue()(_tree_wrpr._tree_header.node_right->value_pair)))
                    return get_node_pos(key, equivalent_key);
                return iterator(_tree_wrpr._tree_header.node_right);
            }
            else if (_tree_wrpr._key_compare(key, KeyOfValue()(pos_base->value_pair)))
            {
                iterator    before(pos_base);
                if (pos_base == _tree_wrpr._tree_header.node_left)
                    return iterator(_tree_wrpr._tree_header.node_left); 
                else if (_tree_wrpr._key_compare(KeyOfValue()((--before).base()->value_pair), key))
                {
                    if (!before.base()->node_right)
                        return iterator(const_cast<Node_ptr>(before.base()));  
                    else
                        return iterator(pos_base);    
                }
                else
                    return get_node_pos(key, equivalent_key);
            }
            else if (_tree_wrpr._key_compare(KeyOfValue()(pos_base->value_pair), key))
            {
                iterator    after(pos_base);
                if (pos_base == _tree_wrpr._tree_header.node_right)
                    return iterator(_tree_wrpr._tree_header.node_right); 
                else if (_tree_wrpr._key_compare(key, KeyOfValue()((++after).base()->value_pair)))
                {
                    if (!pos_base->node_right)
                        return iterator(pos_base);   
                    else
                        return iterator(const_cast<Node_ptr>(after.base()));  
                }
                else
                    return get_node_pos(key, equivalent_key); 
            }
            else
            {
                *equivalent_key = true;
                return iterator(pos_base);
            }
            
        }

        void    node_insertion(Node_ptr new_node, iterator node_pos)
        {
            new_node->node_parent = node_pos.base();
            if (node_pos.base() == &_tree_wrpr._tree_header)
            {
                _tree_wrpr._tree_header.node_parent = new_node;
                _tree_wrpr._tree_header.node_left = new_node;
                _tree_wrpr._tree_header.node_right = new_node;
            }
            else
            {
                if (_tree_wrpr._key_compare(KeyOfValue()(new_node->value_pair), KeyOfValue()(*node_pos)))
                {
                    node_pos.base()->node_left = new_node;
                    if (node_pos.base() == _tree_wrpr._tree_header.node_left)
                        _tree_wrpr._tree_header.node_left = new_node;
                }    
                else
                {
                    node_pos.base()->node_right = new_node;
                    if (node_pos.base() == _tree_wrpr._tree_header.node_right)
                        _tree_wrpr._tree_header.node_right = new_node;
                }
            }
            _tree_wrpr._node_count++;   
        }

        void    tree_left_rotation(Node_ptr left_node)
        {
            
            Node_ptr const  right_node(left_node->node_right);

            left_node->node_right = right_node->node_left;
            if (right_node->node_left)  
                right_node->node_left->node_parent = left_node;
            right_node->node_parent = left_node->node_parent;
            if (left_node == T_begin())
                _tree_wrpr._tree_header.node_parent = right_node;
            else if (left_node->node_parent->node_left == left_node)
                left_node->node_parent->node_left = right_node;
            else
                left_node->node_parent->node_right = right_node;
            right_node->node_left = left_node;
            left_node->node_parent = right_node;
        }

        void    tree_right_rotation(Node_ptr right_node)
        {
            Node_ptr const  left_node(right_node->node_left);

            right_node->node_left = left_node->node_right;
            if (left_node->node_right)
                left_node->node_right->node_parent = right_node;
            left_node->node_parent = right_node->node_parent;
            if (right_node == T_begin())
                _tree_wrpr._tree_header.node_parent = left_node;
            else if (right_node->node_parent->node_right == right_node)
                right_node->node_parent->node_right = left_node;
            else
                right_node->node_parent->node_left = left_node;
            left_node->node_right = right_node;
            right_node->node_parent = left_node;
        }

        Node_ptr     insert_fix_left(Node_ptr grandParent, Node_ptr new_node)
        {
            if (grandParent->node_right && grandParent->node_right->node_color == N_red)
            {
                grandParent->node_left->node_color = N_black;
                grandParent->node_right->node_color = N_black;
                grandParent->node_color = N_red;
                new_node = grandParent;
                return new_node;
            }
            else
            {
                if (new_node->node_parent->node_right == new_node)
                {
                    new_node = new_node->node_parent;
                    tree_left_rotation(new_node);
                }
                new_node->node_parent->node_color = N_black;
                grandParent->node_color = N_red;
                tree_right_rotation(grandParent);
                return new_node;
            }
        }

        Node_ptr    insert_fix_right(Node_ptr grandParent, Node_ptr new_node)
        {
            if (grandParent->node_left && grandParent->node_left->node_color == N_red)
            {
                grandParent->node_left->node_color = N_black;
                grandParent->node_right->node_color = N_black;
                grandParent->node_color = N_red;
                new_node = grandParent;
                return new_node;
            }
            else
            {
                if (new_node->node_parent->node_left == new_node)
                {
                    new_node = new_node->node_parent;
                    tree_right_rotation(new_node);
                }
                new_node->node_parent->node_color = N_black;
                grandParent->node_color = N_red;
                tree_left_rotation(grandParent);
                return new_node;
            }            
        }

        void     insert_fix(Node_ptr new_node)
        {
            while (new_node != _tree_wrpr._tree_header.node_parent && new_node->node_parent->node_color == N_red)
            {
                Node_ptr   parent(new_node->node_parent);
                Node_ptr   grandParent(new_node->node_parent->node_parent);
                if (grandParent->node_left == parent)
                    new_node = insert_fix_left(grandParent, new_node);                
                else
                    new_node = insert_fix_right(grandParent, new_node);       
            }
            _tree_wrpr._tree_header.node_parent->node_color = N_black;
        }

        template<typename Arg>
        pair<iterator, bool>    insert_node(Arg& arg)
        {
            typedef pair<iterator, bool>    Result;
            
            bool    equivalent_key = false;
            iterator    node_pos(get_node_pos(KeyOfValue()(arg), &equivalent_key));
            if (equivalent_key)
                return Result(node_pos, false);
            Node_ptr   new_node(create_node(arg));
            node_insertion(new_node, node_pos);
            insert_fix(new_node);
            return Result(iterator(new_node), true);
        }

        template<typename Arg>
        iterator    insert_node(const_iterator position, Arg& arg)
        {
            bool    equivalent_key = false;
            iterator    node_pos(get_node_pos_hint(position, KeyOfValue()(arg), &equivalent_key));
            if (equivalent_key)
            {
                iterator    test(const_cast<Node_ptr>(position.base()));
                return node_pos;
            }
            Node_ptr   new_node(create_node(arg));
            node_insertion(new_node, node_pos);
            insert_fix(new_node);
            return iterator(new_node);
        }
        
        template<typename InputIterator>
        void    insert_range(InputIterator first, InputIterator last)
        {
            for (; first != last; first++)
                insert_node(*first);
        }

        iterator    lower_bound(const key_type& k)
        {
            Node_ptr   x(T_begin());
            Node_ptr    y(T_end());

            while (x)
            {
                if (!_tree_wrpr._key_compare(KeyOfValue()(x->value_pair), k))
                {
                    y = x;
                    x = x->node_left;
                }
                else
                    x = x->node_right;
            }
            return iterator(y);
        }

        const_iterator    lower_bound(const key_type& k) const
        {
            Const_Node_ptr   x(T_begin());
            Const_Node_ptr    y(T_end());

            while (x)
            {
                if (!_tree_wrpr._key_compare(KeyOfValue()(x->value_pair), k))
                {
                    y = x;
                    x = x->node_left;
                }
                else
                    x = x->node_right;
            }
            return const_iterator(y);
        }

        iterator    upper_bound(const key_type& k)
        {
            Node_ptr   x(T_begin());
            Node_ptr    y(T_end());

            while (x)
            {
                if (_tree_wrpr._key_compare(k, KeyOfValue()(x->value_pair)))
                {
                    y = x;
                    x = x->node_left;
                }
                else
                    x = x->node_right;
            }
            return iterator(y);
        }

        const_iterator    upper_bound(const key_type& k) const
        {
            Const_Node_ptr   x(T_begin());
            Const_Node_ptr    y(T_end());

            while (x)
            {
                if (_tree_wrpr._key_compare(k, KeyOfValue()(x->value_pair)))
                {
                    y = x;
                    x = x->node_left;
                }
                else
                    x = x->node_right;
            }
            return const_iterator(y);
        }

        pair<iterator, iterator>    equal_range(const key_type& k)
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }

        pair<const_iterator, const_iterator>    equal_range(const key_type& k) const
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }
 
        void   copy_tree(Const_Node_ptr x, Node_ptr z)
        {
            while (x != 0)
            {
                Node_ptr   right_node;
                if (x->node_right)
                {
                    right_node = copy_node(x->node_right);
                    z->node_right = right_node;
                    right_node->node_parent = z;
                    copy_tree(x->node_right, z->node_right);
                }
                else
                    z->node_right = 0;
                Node_ptr   left_node;
                if (x->node_left)
                {
                    left_node = copy_node(x->node_left);
                    z->node_left = left_node;
                    left_node->node_parent = z;
                }    
                else
                     z->node_left = 0;
                x = x->node_left;
                z = z->node_left;
            }
        }

        void    swap(Rb_tree& other)
        {
            if (!_tree_wrpr._tree_header.node_parent)
            {
                if (other._tree_wrpr._tree_header.node_parent)
                { 
                    _tree_wrpr._tree_header.node_parent = other._tree_wrpr._tree_header.node_parent;
                    _tree_wrpr._tree_header.node_left = other._tree_wrpr._tree_header.node_left;
                    _tree_wrpr._tree_header.node_right = other._tree_wrpr._tree_header.node_right;
                    _tree_wrpr._tree_header.node_color = other._tree_wrpr._tree_header.node_color;
                    _tree_wrpr._tree_header.node_parent->node_parent = &_tree_wrpr._tree_header;
                    _tree_wrpr._node_count = other._tree_wrpr._node_count;
                    other._tree_wrpr.reset();
                }
            }
            else if (!other._tree_wrpr._tree_header.node_parent)
            {
                other._tree_wrpr._tree_header.node_parent = _tree_wrpr._tree_header.node_parent;
                other._tree_wrpr._tree_header.node_left = _tree_wrpr._tree_header.node_left;
                other._tree_wrpr._tree_header.node_right = _tree_wrpr._tree_header.node_right;
                other._tree_wrpr._tree_header.node_color = _tree_wrpr._tree_header.node_color;
                other._tree_wrpr._tree_header.node_parent->node_parent = &other._tree_wrpr._tree_header;
                other._tree_wrpr._node_count = _tree_wrpr._node_count;
                _tree_wrpr.reset();
            }
            else
            {
                std::swap(_tree_wrpr._tree_header.node_parent, other._tree_wrpr._tree_header.node_parent);
                std::swap(_tree_wrpr._tree_header.node_left, other._tree_wrpr._tree_header.node_left);
                std::swap(_tree_wrpr._tree_header.node_right, other._tree_wrpr._tree_header.node_right);
                _tree_wrpr._tree_header.node_parent->node_parent = T_end();
                other._tree_wrpr._tree_header.node_parent->node_parent = other.T_end();
                std::swap(_tree_wrpr._node_count, other._tree_wrpr._node_count);
            }
            std::swap(_tree_wrpr._key_compare, other._tree_wrpr._key_compare);
            std::swap(get_Node_allocator(), other.get_Node_allocator());
        }

        bool    empty() const
        {
            return _tree_wrpr._node_count == 0;
        }

        size_type   size() const
        {
            return _tree_wrpr._node_count;
        }

        size_type   max_size() const
        {
            return get_Node_allocator().max_size();
        }

        pair<Node_ptr, Node_ptr>   delete_node_one_two_null(Const_Node_ptr node)
        {
            typedef pair<Node_ptr, Node_ptr> Result;
            Node_ptr    x;
            Node_ptr    xp;

            if (!node->node_left)
                x = node->node_right; 
            else
                x = node->node_left;
            if (_tree_wrpr._tree_header.node_parent == node)
                _tree_wrpr._tree_header.node_parent = x;
            else
            {
                if (node->node_parent->node_left == node)
                    node->node_parent->node_left = x;       
                else
                    node->node_parent->node_right = x;
            }
            if (_tree_wrpr._tree_header.node_left == node)
            {
                if (!node->node_right)
                    _tree_wrpr._tree_header.node_left = node->node_parent;
                else
                    _tree_wrpr._tree_header.node_left = minimum(x);       
            }
            if (_tree_wrpr._tree_header.node_right == node)
            {
                if (!node->node_left)
                    _tree_wrpr._tree_header.node_right = node->node_parent;
                else
                    _tree_wrpr._tree_header.node_right = maximum(x);
            }
            if (x)
                x->node_parent = node->node_parent;
            xp = node->node_parent;
            return Result(x, xp);
        }

        pair<Node_ptr, Node_ptr>    delete_node_no_null(Const_Node_ptr node, Rb_tree_color *save_color)
        {
            typedef pair<Node_ptr, Node_ptr> Result;
            Node_ptr    x;
            Node_ptr    xp;

            Node_ptr    y(minimum(node->node_right));
            *save_color = y->node_color;
            x = y->node_right ;
            if (node->node_right == y)
                    xp = y;
            else
            {
                if (x)
                    x->node_parent = y->node_parent;
                y->node_parent->node_left = x;
                y->node_right = node->node_right;
                node->node_right->node_parent = y;
                xp = y->node_parent;
            } 
            if (_tree_wrpr._tree_header.node_parent == node)
                _tree_wrpr._tree_header.node_parent = y;
            else if (node->node_parent->node_left == node)
                node->node_parent->node_left = y;
            else
                node->node_parent->node_right = y;
            y->node_parent = node->node_parent;
            node->node_left->node_parent = y;
            y->node_left = node->node_left;
            y->node_color = node->node_color;
            return Result(x, xp);            
        }

        pair<Node_ptr, Node_ptr>    delete_node(Node_ptr node, Rb_tree_color *save_color)
        {
            *save_color = node->node_color;
            if (!(node->node_left && node->node_right))
                return delete_node_one_two_null(node);  
            else
                return delete_node_no_null(node, save_color);         
        }

        pair<Node_ptr, Node_ptr>    delete_node(Const_Node_ptr node, Rb_tree_color *save_color)
        {
            *save_color = node->node_color;
            if (!(node->node_left && node->node_right))
                return delete_node_one_two_null(node);
            else
                return delete_node_no_null(node, save_color);
        }

        int    delete_fix_left(Node_ptr *x, Node_ptr *xp)
        {
            Node_ptr    w((*xp)->node_right);
            if (w->node_color == N_red)
            {
                w->node_color = N_black;
                (*xp)->node_color = N_red;
                tree_left_rotation(*xp);
                w = (*xp)->node_right;
            }
            if ((!w->node_left || w->node_left->node_color == N_black) && (!w->node_right || w->node_right->node_color == N_black))
            {
                w->node_color = N_red;
                *x = *xp;
                *xp = (*xp)->node_parent;
            }
            else
            {
                if (!w->node_right || w->node_right->node_color == N_black)
                {
                    w->node_left->node_color = N_black;
                    w->node_color = N_red;
                    tree_right_rotation(w);
                    w = (*xp)->node_right;
                }
                w->node_color = (*xp)->node_color;
                (*xp)->node_color = N_black;
                if (w->node_right)
                    w->node_right->node_color = N_black;
                tree_left_rotation(*xp);
                return 1;
            }
            return 0;
        }

        int    delete_fix_right(Node_ptr *x, Node_ptr *xp)
        {
            Node_ptr    w((*xp)->node_left);
            if (w->node_color == N_red)
            {
                w->node_color = N_black;
                (*xp)->node_color = N_red;
                tree_right_rotation(*xp);
                w = (*xp)->node_left;
            }
            if ((!w->node_left || w->node_left->node_color == N_black) && (!w->node_right || w->node_right->node_color == N_black))
            {
                w->node_color = N_red;
                *x = *xp;
                *xp = (*xp)->node_parent;
            }
            else
            {
                if (!w->node_left || w->node_left->node_color == N_black)
                {
                    w->node_right->node_color = N_black;
                    w->node_color = N_red;
                    tree_left_rotation(w);
                    w = (*xp)->node_left;
                }
                w->node_color = (*xp)->node_color;
                (*xp)->node_color = N_black;
                if (w->node_left)
                    w->node_left->node_color = N_black;
                tree_right_rotation(*xp);
                return 1;
            }
            return 0;
        }
        
        void    delete_fix(Node_ptr x, Node_ptr xp)
        {
            int    stop = 0;
            while (x != _tree_wrpr._tree_header.node_parent && (!x || x->node_color == N_black))
            {
                if (xp->node_left == x)
                    stop = delete_fix_left(&x, &xp);           
                else
                    stop = delete_fix_right(&x, &xp);
                if (stop)
                    break ;
            }
            if (x)
                x->node_color = N_black; 
        }

        void   erase(const_iterator position)
        {
            typedef pair<Node_ptr, Node_ptr> Result;
            Rb_tree_color   save_color;
            Result    res(delete_node(position.base(), &save_color));
            Node_ptr    pos = const_cast<typename iterator::Node_ptr>(position.base());
            allocator_type().destroy(&pos->value_pair);
            get_Node_allocator().deallocate(pos, 1);
            _tree_wrpr._node_count--;
            if (save_color == N_black)
                delete_fix(res.first, res.second);
        }

        void    erase(const_iterator first, const_iterator last)
        {
            while (first != last)
                erase(first++);       
        }   

        size_type   erase(const key_type& k)
        {
            pair<iterator, iterator>    res(equal_range(k));

            if (res.first == res.second)
                return 0;
            erase(res.first);
            return 1;
        }

        void    clear()
        {
            R_erase(_tree_wrpr._tree_header.node_parent);
            _tree_wrpr.reset();
        }

        iterator    find(const key_type& k)
        {
            iterator    it(lower_bound(k));
            if (it == end() || _tree_wrpr._key_compare(k, KeyOfValue()(it.base()->value_pair)))
                return end();
            return  it;

        }

        const_iterator    find(const key_type& k) const
        {
            const_iterator    it(lower_bound(k));
            if (it == end() || _tree_wrpr._key_compare(k, KeyOfValue()(it.base()->value_pair)))
                return end();
            return  it;

        }

        size_type    count(const key_type& k) const
        {
            if (find(k) == end())
                return 0;
            return 1;
        }

        Compare key_comp() const
        {
            return _tree_wrpr._key_compare;
        }

        allocator_type  get_allocator() const
        {
            return allocator_type(get_Node_allocator());
        }
        
    };

    template<typename Tp>
    bool    operator==(const Rb_tree_iterator<Tp>& lo, const Rb_tree_iterator<Tp>& ro)
    {
        return lo.base() == ro.base();
    }
    
    template<typename Tp>
    bool    operator==(const Rb_tree_const_iterator<Tp>& lo, const Rb_tree_iterator<Tp>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename Tp>
    bool    operator==(const Rb_tree_iterator<Tp>& lo, const Rb_tree_const_iterator<Tp>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename Tp>
    bool    operator==(const Rb_tree_const_iterator<Tp>& lo, const Rb_tree_const_iterator<Tp>& ro)
    {
        return lo.base() == ro.base();
    }

    template<typename Tp>
    bool    operator!=(const Rb_tree_iterator<Tp>& lo, const Rb_tree_iterator<Tp>& ro)
    {
        return lo.base() != ro.base();
    }

    template<typename Tp>
    bool    operator!=(const Rb_tree_const_iterator<Tp>& lo, const Rb_tree_iterator<Tp>& ro)
    {
        return lo.base() != ro.base();
    }

    template<typename Tp>
    bool    operator!=(const Rb_tree_iterator<Tp>& lo, const Rb_tree_const_iterator<Tp>& ro)
    {
        return lo.base() != ro.base();
    }

    template<typename Tp>
    bool    operator!=(const Rb_tree_const_iterator<Tp>& lo, const Rb_tree_const_iterator<Tp>& ro)
    {
        return lo.base() != ro.base();
    }

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator>
    bool    operator==(const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& lo, const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& ro)
    {
        typedef typename Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>::const_iterator  const_iterator;
        
        if (lo.size() != ro.size()) 
            return false;
        const_iterator it1 = lo.begin();
        const_iterator it2 = ro.begin();
        for (; it1 != lo.end(); it1++, it2++)
        {
            if (*it1 != *it2)
                return false; 
        }
        return true;
    }

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator>
    bool    operator!=(const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& lo, const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& ro)
    {
        return !(lo == ro);
    }

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator>
    bool    operator<(const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& lo, const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& ro)
    {
        return ft::lexicographical_compare(lo.begin(), lo.end(), ro.begin(), ro.end());
    }

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator>
    bool    operator>(const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& lo, const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& ro)
    {
        return ro < lo;
    }

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator>
    bool    operator<=(const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& lo, const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& ro)
    {
        return !(lo > ro);
    }

    template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator>
    bool    operator>=(const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& lo, const Rb_tree<Key, Val, KeyOfValue, Compare, Allocator>& ro)
    {
        return !(lo < ro);
    }
}
#endif