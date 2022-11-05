#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <exception>
#include <stdexcept>
#include <string>
#include <limits>

#include "iterator_traits.hpp"

namespace ft 
{
    template < class Iterator>
    class random_access_iterator {
        public:
            typedef Iterator                                                        iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::value_type         value_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer            pointer;
		    typedef	typename ft::iterator_traits<iterator_type>::reference	        reference;
		    typedef	typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
            typedef	typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;
        
        private:
            iterator_type _ptr;
            
        public:
            random_access_iterator() : _ptr(nullptr) {}
            random_access_iterator(iterator_type p) : _ptr(p) {}
            random_access_iterator(const random_access_iterator &p) : _ptr(p.base()) {}
            template <class T> random_access_iterator(const random_access_iterator<T> &p) : _ptr(p.base()) {}
            ~random_access_iterator() {}

            random_access_iterator &operator=(random_access_iterator const &p) {
                if (this != &p)
                    this->_ptr = p.base();
                return (*this);
            }

            iterator_type base() const
            {
                return (this->_ptr);
            }

            reference operator*() const { return (*_ptr); }
            pointer operator->() const { return(this->_ptr); }

            random_access_iterator operator++(int) {
                random_access_iterator tmp(*this);
                ++(*this);
                return(tmp);
            }
            random_access_iterator& operator++() {
                ++(this->_ptr);
                return(*this);
            }
            random_access_iterator operator--(int) {
                random_access_iterator tmp(*this);
                --(*this);
                return(tmp);
            }
            random_access_iterator& operator--() {
                --(this->_ptr);
                return(*this);
            }

            random_access_iterator& operator +=(const difference_type &value) {
                this->_ptr += value;
                return (*this);
            }
            random_access_iterator operator +(difference_type value) const {
                random_access_iterator tmp(*this);
                return (tmp += value);
            }
            random_access_iterator& operator -=(const difference_type &value) {
                this->_ptr += -value;
                return (*this);
            }
            random_access_iterator operator -(difference_type value) const {
                return (*this + (-value));
            }

            reference operator[](difference_type nb) const {
                return (this->_ptr[nb]);
            }

            template<typename U>
            friend random_access_iterator operator+(difference_type n, const random_access_iterator<U>& rhs) {
                random_access_iterator t(rhs);
                t._ptr += n;
                return (t);
        }
    };

    template <typename A, typename B>
    typename random_access_iterator<A>::difference_type operator-(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return (l.base() - r.base());
    }
    
    template <typename A, typename B>
    bool operator==(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return (l.base() == r.base());
    }
    template <typename A, typename B>
    bool operator!=(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return !(l.base() == r.base());
    }
    template <typename A, typename B>
    bool operator>(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return (l.base() > r.base());
    }
    template <typename A, typename B>
    bool operator<(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return (l.base() < r.base());
    }
    template <typename A, typename B>
    bool operator>=(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return (l.base() >= r.base());
    }
    template <typename A, typename B>
    bool operator<=(const random_access_iterator<A> &l, const random_access_iterator<B> &r) {
        return (l.base() <= r.base());
    }
}

#endif
