#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <stdexcept>
#include <string>

#include "iterator_traits.hpp"

namespace ft 
{
    template < class Iterator>
    class reverse_iterator{
        public:
            typedef	Iterator	                                            iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;
        protected:
            iterator_type	_p;
        public:
            reverse_iterator() : _p() {}
            explicit reverse_iterator (iterator_type p) : _p(p) {}
            template <class Iter>
            reverse_iterator (reverse_iterator<Iter> const &rev_it) : _p(rev_it.base()) {}

            reverse_iterator &operator=(const reverse_iterator<Iterator> &rev_it) {
                this->_p = rev_it.base();
                return (*this);
            }

            iterator_type base() const
            {
                return (_p);
            }

            reference operator*() const
            {
                iterator_type tmp = _p;
                return (*--tmp);
            }
            pointer operator->() const{
                return &(operator*());
            }
            reverse_iterator operator+ (difference_type n) const
            {
                return (reverse_iterator(_p - n));	
            }
            reverse_iterator& operator++()
            {
                --_p;
                return(*this);
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator temp = *this;
                --_p;
                return temp;	
            }
            reverse_iterator& operator+= (difference_type n){
                _p -= n;
                return (*this);
            }
            reverse_iterator operator- (difference_type n) const{
                return (reverse_iterator(_p + n)); 
            }
            reverse_iterator& operator--()
            {
                ++_p;
                return(*this);
            }
            reverse_iterator  operator--(int){
                reverse_iterator temp = *this;
                ++_p;
                return temp;
            }
            reverse_iterator& operator-= (difference_type n){
                _p += n;
                return (*this);
            }
            reference operator[] (difference_type n) const{
                return (*(*this + n));
            }

    };

    template <typename A>
    reverse_iterator<A> operator+(typename reverse_iterator<A>::difference_type n, reverse_iterator<A> &p) {
        return (p + n);
    }

    template <typename A, typename B>
    typename reverse_iterator<A>::difference_type operator-(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (r.base() - l.base());
    }

    template <typename A, typename B>
    bool operator==(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (l.base() == r.base());
    }
    template <typename A, typename B>
    bool operator!=(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (!(l.base() == r.base()));
    }
    template <typename A, typename B>
    bool operator>(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (l.base() < r.base());
    }
    template <typename A, typename B>
    bool operator<(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (l.base() > r.base());
    }
    template <typename A, typename B>
    bool operator>=(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (l.base() <= r.base());
    }
    template <typename A, typename B>
    bool operator<=(const reverse_iterator<A> &l, const reverse_iterator<B> &r) {
        return (l.base() >= r.base());
    }
}

#endif
