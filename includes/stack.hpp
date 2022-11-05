#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {

    template < class T, class Container = ft::vector<T> >
    class stack {
        public:
            typedef Container                           container_type;
            typedef typename Container::value_type      value_type;
            typedef typename Container::size_type       size_type;
            typedef typename Container::reference       reference;
            typedef typename Container::const_reference const_reference;

        protected:
            container_type c;
        
        public:
            //Constructor
            explicit stack( const Container& cont = Container() ) : c(cont) { }
            //Destructor
            ~stack() { }
            //Operator =
            stack& operator=( const stack& other ) 
            {
                this->c = other.c;
                return (*this);
            }

            //Element access
            reference top() { return (this->c.back()); }
            const_reference top() const { return (this->c.back()); }

            //Capacity
            bool empty() const { return (this->c.empty()); }
            size_type size() const { return (this->c.size()); }

            //Modifiers
            void push( const value_type& value ) { return (this->c.push_back(value)); }
            void pop( ) { return (this->c.pop_back()); }

            //Operators
    		template <class T1, class Container1>
			friend	bool operator== (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator!= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator<  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator<=  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator>  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator>=  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
	};

	//NON MEMBER FUNCTION OVERLOADS
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class T, class Container>
	bool operator<=  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class T, class Container>
	bool operator>=  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif
