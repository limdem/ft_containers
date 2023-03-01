#ifndef NULLPOINTER_HPP
# define NULLPOINTER_HPP


namespace ft
{

    struct  nptr_t
    {
        void*    _ptr;

        nptr_t()
            : _ptr(0)
        {}
    
    private:
        void    operator&() const;

    public:
        template<typename T>
        inline operator T*() const { return 0;}

        template<typename C, typename T>
        inline operator T C::*() const { return 0;}
    };

    inline ft::nptr_t   get_ptr_t()
    {
        return nptr_t();
    }
    #define nptr get_ptr_t()
}

#endif