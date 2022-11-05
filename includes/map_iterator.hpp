#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "util.hpp"
#include "iterator_traits.hpp"
#include "AVL_tree.hpp"

namespace ft 
{
    template < class K, class M, bool isConst = false>
    class map_iterator {
        public:
            typedef map_iterator<K, M, isConst>	        iterator;
            typedef ft::pair<const K, M>														value_type;
            typedef std::ptrdiff_t											difference_type;
            typedef typename ft::choose_type<const value_type&, value_type&, isConst>::type       reference;
            typedef typename ft::choose_type<const value_type*, value_type*, isConst>::type       pointer;
            typedef typename choose_type<const AVLNode<value_type>*, AVLNode<value_type>*, isConst>::type   iterator_type;

            typedef std::bidirectional_iterator_tag							iterator_category; 

        public:
            iterator_type _ptr;
            
        public:
            map_iterator() : _ptr(nullptr) {}
            map_iterator(iterator_type p) : _ptr(p) {}
            map_iterator(const map_iterator<K, M, false> &p) : _ptr(p._ptr) {}
            map_iterator(const map_iterator<K, M, true> &p) : _ptr(p._ptr) {}

            ~map_iterator() {}

            iterator &operator=(iterator const &p) {
                if (this != &p)
                    this->_ptr = p._ptr;
                return (*this);
            }

            iterator_type base() const
            {
                return (this->_ptr);
            }

            template <bool B>
            bool operator== (const map_iterator<K, M, B>& rhs) const { return _ptr == rhs._ptr; }
            template <bool B>
	        bool operator!= (const map_iterator<K, M, B>& rhs) const { return _ptr != rhs._ptr; }


            reference operator*()  { return (_ptr->value); }
            const reference operator*() const { return (_ptr->value); }
            pointer operator->()  { return &(_ptr->value); }
            const pointer operator->() const { return &(_ptr->value); }

            iterator operator++ (int) {
                iterator tmp = *this;
                this->_ptr = this->_ptr->next();
                return(tmp);
            }

            iterator& operator++ () {
                this->_ptr = this->_ptr->next();
                return *this;
            }

            iterator operator-- (int) {
                iterator tmp = *this;
                _ptr = _ptr->prev();
                return(tmp);
            }

            iterator& operator-- () {
                _ptr = _ptr->prev();
                return *this;
            }
    };
}

#endif
