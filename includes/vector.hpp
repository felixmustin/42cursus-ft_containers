#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "util.hpp"

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <iterator>
# include <iostream>
# include <memory>
# include <limits>


namespace ft {

    template < class T, class Alloc = std::allocator<T> >
    class vector {
        public:
			//Member type
            typedef T					                        value_type;

            typedef Alloc				                        allocator_type;

		    typedef	typename allocator_type::difference_type 	difference_type;

			typedef	typename allocator_type::size_type 			size_type;

            typedef typename allocator_type::reference          reference;

            typedef typename allocator_type::const_reference 	const_reference;

            typedef typename allocator_type::pointer 		    pointer;

            typedef typename allocator_type::const_pointer 	    const_pointer;

			typedef ft::random_access_iterator<pointer>         iterator;

			typedef ft::random_access_iterator<const_pointer>   const_iterator;

			typedef ft::reverse_iterator<iterator>		        reverse_iterator;

			typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

		private:
            pointer _first;
			allocator_type _alloc;
            size_type _size;
            size_type _capacity;
                
        public:
			//Member function
			//Default constructor
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _first = 0;
                _size = 0;
                _capacity = 0;
			}
			//Fill constructor
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
            _alloc(alloc), _size(n), _capacity(n)
            {
                if (_capacity)
                _first = _alloc.allocate(n);
                for (size_type i = 0; i < _size; i++)
				    _alloc.construct(_first + i, val);
            }
			//Range constructor
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral <InputIterator>::value, InputIterator>::type * = nullptr) :
            _alloc(alloc)
            {
                _size = ft::distance(first, last);
                _capacity = _size;
                if (_capacity)
                    _first = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++) {
				    _alloc.construct(_first + i, *first);
                    first++;
                }
            }
			/*-----------Copy constructor------------*/
            vector (const vector& x) : _first(nullptr), _size(0), _capacity(0)
            {
                *this = x;
            }
			/*-----------Operator=------------*/
            vector &operator=(const vector & x) 
            {
				if (this == &x)
					return (*this);
                for (size_type i = 0; i < _size; i++)
				    _alloc.destroy(_first + i);
                _size  = x._size;
				_alloc = x._alloc;
				if (_capacity < _size)
                {
                    if (_capacity != 0)
					    _alloc.deallocate(_first, _capacity);
				_capacity = _size;
				_first = _alloc.allocate(_capacity);
                }
				for (size_type i = 0; i < _size; i++)
				    _alloc.construct(_first + i, x[i]);
			    return *this;
            }
			/*-----------Destructor------------*/
            ~vector(void)
            {
                for (size_type i = 0; i < _size; i++)
				    _alloc.destroy(_first + i);
				if (_capacity)
                    _alloc.deallocate(_first, _capacity);
			}


            /*-----------Capacity------------*/
            size_type size() const { return (this->_size); }

            size_type max_size() const { return (this->_alloc.max_size()); }

            size_type capacity() const { return (this->_capacity); }

            bool empty() const { return (this->_size == 0); }

            void reserve( size_type new_cap )
            {
                if (new_cap > this->_alloc.max_size())
                    throw std::length_error("vector::reserve");
                if (new_cap > this->_capacity)
                {
                    pointer new_ptr = _alloc.allocate(new_cap);
                    for (size_type j = 0; j < _size; j++) {
                        _alloc.construct(new_ptr + j, this->_first[j]);    
                        _alloc.destroy(this->_first + j);
                    }
                    if (_capacity)
                        _alloc.deallocate(_first, _capacity);
                    _capacity = new_cap;
                    _first = new_ptr;
                }
            }

            void resize(size_type n, value_type val = value_type())
            {
                if (n < this->_size)
                {
                    for (size_type j = n; j < this->_size; j++)
                        _alloc.destroy(this->_first + j);
                    this->_size = n;
                }
                else if (n > this->_size)
                {
                    if (n > this->_capacity) {
                        if (this->_capacity * 2 > n)
                            reserve(this->_capacity * 2);
                        else
                            reserve(n);
                    }
                    for (size_type i = this-> _size; i < n; i++){
                        _alloc.construct(this->_first + i, val);
                        this->_size++;
				    }
                }
            }

            /*-----------Element access------------*/
            reference operator[](size_type nb) { return (_first[nb]); }

            const_reference operator[](size_type nb) const { return (_first[nb]); }

            reference at(size_type nb) 
            {
                if (nb >= this->_size)
                    throw std::out_of_range("vector access");
                return (this->_first[nb]);
            }

            const_reference at(size_type nb) const 
            {
                if (nb >= this->_size)
                    throw std::out_of_range("vector access");
                return (this->_first[nb]);
            }

            reference front() { return (this->_first[0]); }

            const_reference front() const { return (this->_first[0]); }

            reference back() { return (this->_first[this->_size - 1]); }
            
            const_reference back() const { return (this->_first[this->_size - 1]); }

            T* data() { return this->_first; }

            const T* data() const {  return this->_first; }


            /*-----------Modifiers------------*/
            template < class InputIterator >
            void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral <InputIterator>::value, InputIterator>::type * = nullptr)
            {
                size_type   save_size = this->_size;
				
				_size = ft::distance(first, last);

                for (size_type j = 0; save_size > 0 && j < (save_size); j++)
                    _alloc.destroy(this->_first + j);
				if (_size <= _capacity)
				{
                    for (size_type i=0; i < this->_size; i++)
				        _alloc.construct(_first + i, *(first++));
				}
				else
				{
                    if (_capacity)
					    _alloc.deallocate(_first, _capacity);
					_capacity = _size;
					_first = _alloc.allocate(_capacity);
                    for ( size_type	i = 0; i < _size; ++i)
				        _alloc.construct(_first + i, *(first++));
				}
            }
            
            void assign(size_type count, const value_type& value)
            {
                size_type	i = -1;
				size_type   save_size = this->_size;

				this->_size = count; 
                while (++i < save_size)
                    _alloc.destroy(_first + i);
				if (this->_size <= _capacity)
				{
                    for (size_type i=0; i < this->_size; i++)
				        _alloc.construct(_first + i, value);
				}
				else
				{
                    if (_capacity)
					    _alloc.deallocate(_first, _capacity);
					this->_capacity = this->_size;
					this->_first = _alloc.allocate(_capacity);
                    for (size_type k = 0; k < _size; k++)
				        _alloc.construct(_first + k, value);
				}
            }

            void push_back (const value_type& val)
            {
                resize(_size + 1, val);
            }

            void pop_back(void) 
            {
                if (_size) {
                    _alloc.destroy(_first + _size - 1);
					_size--;
                }
            }

            //fill
            void insert (iterator position, size_type n, const value_type& val)
            {
                size_type ind = ft::distance(this->begin(), position);
                if (this->_size + n > this->_capacity) {
                    if (this->_capacity * 2 > this->_size + n)
                        reserve(this->_capacity * 2);
                    else
                        reserve(this->_size + n);
                }
                for (size_type i = n + _size - 1; i > ind + n - 1; i--) {
                    _alloc.construct(&_first[i], _first[i - n]);
                    _alloc.destroy(&_first[i - n]);
                }
                for (size_type i = ind; i < ind + n; i++) {
                    _alloc.construct(&_first[i], val);
                    _size++;
                }
            }
            //range
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral <InputIterator>::value, InputIterator>::type * = nullptr)
            {
                size_type ind = ft::distance(this->begin(), position);
                size_type end_dist = ft::distance(this->begin(),this->end());
                if (ind > end_dist)
                    ind = 0;
                size_type n = ft::distance(first, last);
                if (this->_size + n > this->_capacity) {
                    if (this->_capacity * 2 > this->_size + n)
                        reserve(this->_capacity * 2);
                    else
                        reserve(this->_size + n);
                }
                for (size_type i = n + _size - 1; i > ind + n - 1; i--) {
                    _alloc.construct(&_first[i], _first[i - n]);
                    _alloc.destroy(&_first[i - n]);
                }
                for (size_type i = ind; i < ind + n; i++) {
                    _alloc.construct(&_first[i], *(first++));
                    _size++;
                }
            }
            //single elem
            iterator insert (iterator position, const value_type& val)
            {
                size_type ind = 0;
                if (this->_size)
                    ind = ft::distance(this->begin(), position);
                insert(position, 1, val);
                return (this->begin() + ind);
            }

            //single elems
            iterator erase (iterator position)
            {
                size_type	pos = position - this->begin();
                _alloc.destroy(_first + pos);
                _size--;
                if (pos < _size) {
                    for (size_type i = pos; i < _size; i++) {
                        _alloc.construct(&_first[i], _first[i + 1]);
                        _alloc.destroy(&_first[i + 1]);
                    }
                }
                return iterator(&_first[pos]);
            }
            //range
            iterator erase (iterator first, iterator last)
            {
                size_type pos = last - first;

                while(pos--)
                    erase(first);
                return first;
            }

            void clear()
            {
                if(this->_first != NULL)
                {
                    for (size_type i = 0; i < this->_size; i++)
                        _alloc.destroy(this->_first + i);
                    this->_size = 0;
                }
            }

            void swap(vector &x)
            {
                size_type tmp_size = x._size;
                size_type tmp_cap = x._capacity;
                pointer tmp_first = x._first;

                x._size = this->_size;
                x._capacity = this->_capacity;
                x._first = this->_first;
                this->_size = tmp_size;
                this->_capacity = tmp_cap;
                this->_first = tmp_first;
            }

            /*-----------Allocator------------*/
            allocator_type get_allocator() const
            {
                return (this->_alloc);
            }


			/*-----------Iterators------------*/
			iterator begin() {
				return (iterator(_first));
			}
            iterator end() {
				return (iterator(_first + _size));
			}
            reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			}
            reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}


            const_iterator begin() const {
				return (const_iterator(_first));
			}
            const_iterator end() const {
				return (const_iterator(_first + _size));
			}
            const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			}
            const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			}
    };

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template<class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }
}


#endif
