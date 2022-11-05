#ifndef UTIL_HPP
# define UTIL_HPP

#include "iterator_traits.hpp"
#include <type_traits>

namespace ft {
	
	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type __distance(InputIterator first, InputIterator last, input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while(first++ != last)
			++n;
		return n;
	}

	template <class RandomAccessIterator>
	typename iterator_traits<RandomAccessIterator>::difference_type __distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
	{
		return last - first;
	}

	template <typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type 		distance(InputIterator first, InputIterator last)
	{
		return __distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
	}

	template< bool B, class T = void >
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<typename T, bool b>
	struct integral_constant
	{
		static const bool value = b;
		typedef T value_type;
		typedef integral_constant<T, b> type;
		operator value_type() const { return value; }

	};

	template<typename T>
	struct is_integral : public ft::integral_constant<T, false> {};

	template<>
	struct is_integral<bool> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<char> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<signed char> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<char32_t> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<short> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned short> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<int> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<long> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned long> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<long long> : public ft::integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned long long> : public ft::integral_constant<bool, true> {};


    template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

    template< class InputIterator1, class InputIterator2 >
    bool lexicographical_compare( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
    {
        while ((first1 != last1))
		{
			if ((first2 == last2) || (*first1 > *first2))
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
        return (first2 != last2);
    }


	template <class T1, class T2>
	struct pair {
		
		typedef T1 first_type;
		typedef T2 second_type;
		
		first_type first;
		second_type second;

		pair() : first(), second() {}
		
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		template <class A, class B>
		pair(const pair<A,B>& pair_) : first(pair_.first), second(pair_.second) {}

		template <class U, class V>
		pair& operator=( const pair& other ) {
            first = other.first;
            second = other.second;
			return *this;
		}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return pair<T1,T2>(x,y);
	}

	template <class T1, class T2>
	bool operator== (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return lhs.first < rhs.first
		|| (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return !(lhs < rhs);
	}


	template <class const_type, class normal_type, bool flag>
	struct choose_type;

	template <class const_type, class normal_type>
	struct choose_type<const_type, normal_type, true> {
		typedef const_type type;
	};

	template <class const_type, class normal_type>
	struct choose_type<const_type, normal_type, false> {
		typedef normal_type type;
	};
}

#endif
