#include <iostream>
#include <list>

#if STD_OPTION
	#include <vector>
	#include <stack>
	#include <map>
	namespace ft = std;
#else
	#include "includes/vector.hpp"
	#include "includes/map.hpp"
	#include "includes/stack.hpp"
#endif

    void vector_constructor()
    {
        std::cout << "\nConstructors : " << std::endl;
        ft::vector<int> first1;
        ft::vector<int> second(4, 100);
        ft::vector<int> third(second.begin(), second.end());
        ft::vector<int> fourth(third);
        int myints[] = {16, 2, 77, 29};
        ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

		std::cout << "The contents of second are:";
        for (ft::vector<int>::iterator it2 = second.begin(); it2 != second.end(); ++it2)
            std::cout << ' ' << *it2;
        std::cout << std::endl;

		std::cout << "The contents of fourth are:";
        for (ft::vector<int>::iterator it4 = fourth.begin(); it4 != fourth.end(); ++it4)
            std::cout << ' ' << *it4;
        std::cout << std::endl;

		std::cout << "The contents of fifth are:";
        for (ft::vector<int>::iterator it5 = fifth.begin(); it5 != fifth.end(); ++it5)
            std::cout << ' ' << *it5;
        std::cout << std::endl;
    }

    void vector_equal_operator()
	{
        std::cout << "\n0perator= : " << std::endl;
        ft::vector<int> foo1(3, 0);
        ft::vector<int> bar1(5, 0);
        bar1 = foo1;
        foo1 = ft::vector<int>();
        std::cout << "Size of bar1: " << int(bar1.size()) << '\n';
        std::cout << "Size of foo1: " << int(foo1.size()) << '\n';
        std::cout << "Contents of bar1:";
        for (ft::vector<int>::iterator it = bar1.begin(); it != bar1.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
	    std::cout << "Contents of foo1:";
        for (ft::vector<int>::iterator it1 = foo1.begin(); it1 != foo1.end(); ++it1)
            std::cout << ' ' << *it1;
        std::cout << std::endl;
    }

    void vector_constructors()
    {
        vector_constructor();
        vector_equal_operator();
    }

    void vector_begin()
	{
        std::cout << "\nBegin() : " << std::endl;
        ft::vector<int> myvector;
        for (int i = 1; i <= 10; i++)
            myvector.push_back(i);
        std::cout << "Vector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    void vector_end_1()
    {
        std::cout << "\nEnd() (1) : " << std::endl;
        ft::vector<int> test;
        for (int i = 1; i <= 10; i++)
            test.push_back(i);
        std::cout << "Vector contains:";
        for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    void vector_end_2()
    {
        std::cout << "\nEnd() (2) : " << std::endl;
        ft::vector<int> test;
        for (int i = 1; i <= 10; i++)
            test.push_back(i);
        ft::vector<int>::iterator it = test.end();
        it--;
        std::cout << "Vector contains:";
        for (; it != test.begin(); it--)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    void vector_c_begin_end()
    {
        std::cout << "\nConst Begin()/End()" << std::endl;
        ft::vector<int> myvector;
        for (int i = 1; i <= 10; i++)
            myvector.push_back(i);
        std::cout << "Vector contains:";
        for (ft::vector<int>::const_iterator c_it = myvector.begin(); c_it != myvector.end(); ++c_it)
            std::cout << ' ' << *c_it;
        std::cout << std::endl;
        ft::vector<int>::iterator it = myvector.begin() - 1;
        ft::vector<int>::const_iterator it_c = myvector.begin() - 1;
        while(it++ == it_c++ && it != myvector.end() && it_c != myvector.end())
            std::cout << " Iterator : " << *it << " Const iterator : " << *it_c << std::endl;

    }

    void vector_rbegin_1()
    {
        std::cout << "\nReverse Begin() : " << std::endl;
        ft::vector<int> test;
        for (int i = 1; i <= 10; i++)
            test.push_back(i);
        std::cout << "Vector contains:";
        for (ft::vector<int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    void vector_rend_1()
    {
        std::cout << "\nReverse End() : " << std::endl;
        ft::vector<int> test;
        for (int i = 1; i <= 10; i++)
            test.push_back(i);
        ft::vector<int>::reverse_iterator it = test.rend();
        it--;
        std::cout << "Vector contains:";
        for (; it != test.rbegin(); it--)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    void vector_c_rbegin_rend()
    {
        std::cout << "\nConst Reverse Begin()/End()" << std::endl;
        ft::vector<int> myvector;
        for (int i = 1; i <= 10; i++)
            myvector.push_back(i);
        std::cout << "Vector contains:";
        for (ft::vector<int>::const_reverse_iterator c_it = myvector.rbegin(); c_it != myvector.rend(); c_it++)
            std::cout << ' ' << *c_it;
        std::cout << std::endl;
        ft::vector<int>::reverse_iterator it = myvector.rbegin();
        ft::vector<int>::const_reverse_iterator it_c = myvector.rbegin();
        while(it++ == it_c++ && it != myvector.rend() && it_c != myvector.rend())
            std::cout << "Reverse Iterator : " << *it << " Const Reverse iterator : " << *it_c << std::endl;

    }

    void vector_iterators()
    {
        vector_begin();
        vector_end_1();
        vector_end_2();
        vector_c_begin_end();
        vector_rbegin_1();
        vector_rend_1();
        vector_c_rbegin_rend();
    }

    void vector_size()
    {
        std::cout << "\nSize() : " << std::endl;
        ft::vector<int> myints1;
        std::cout << "0. size: " << myints1.size() << std::endl;
        for (int i = 0; i < 10; i++)
            myints1.push_back(i);
        std::cout << "1. size: " << myints1.size() << std::endl;
        myints1.insert(myints1.end(), 10, 100);
        std::cout << "2. size: " << myints1.size() << std::endl;
        myints1.pop_back();
        std::cout << "3. size: " << myints1.size() << std::endl;
    }

    void vector_empty()
    {
        std::cout << "\nEmpty() : " << std::endl;
        ft::vector<int> myvector1;
        int sum1(0);
        for (int i = 1; i <= 10; i++)
            myvector1.push_back(i);
        std::cout << "Size before : " << myvector1.size() << std::endl;
        while (!myvector1.empty())
        {
            sum1 += myvector1.back();
            myvector1.pop_back();
        }
        std::cout << "Total: " << sum1 << std::endl;
        std::cout << "Size after : " << myvector1.size() << std::endl;
    }

    void vector_max_size()
    {
        std::cout << "\nMax_size() : " << std::endl;
        ft::vector<int> myvector1;
        for (int i = 0; i < 100; i++)
            myvector1.push_back(i);
        std::cout << "size: " << myvector1.size() << std::endl;
        std::cout << "capacity: " << myvector1.capacity() << std::endl;
        std::cout << "max_size: " << myvector1.max_size() << std::endl;
    }

    void vector_capacity()
	{
        std::cout << "\nCapacity() : " << std::endl;
        ft::vector<int> myvector1;
        std::cout << "size before : " << (int)myvector1.size() << '\n';
        std::cout << "capacity before : " << (int)myvector1.capacity() << '\n';
        for (int i = 0; i < 100; i++)
            myvector1.push_back(i);
        std::cout << "size after : " << (int)myvector1.size() << '\n';
        std::cout << "capacity after: " << (int)myvector1.capacity() << '\n';
    }

    void vector_reserve()
	{
        std::cout << "\nReserve() : " << std::endl;
        ft::vector<int>::size_type sz1;
        ft::vector<int> foo1;
        sz1 = foo1.capacity();
        std::cout << "making foo grow:\n";
        for (int i = 0; i < 10; ++i)
        {
            foo1.push_back(i);
            if (sz1 != foo1.capacity())
            {
                sz1 = foo1.capacity();
                std::cout << "capacity changed: " << sz1 << '\n';
            }
        }
        ft::vector<int> bar1;
        sz1 = bar1.capacity();
        bar1.reserve(10); // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i = 0; i < 10; ++i)
        {
            bar1.push_back(i);
            if (sz1 != bar1.capacity())
            {
                sz1 = bar1.capacity();
                std::cout << "capacity changed: " << sz1 << '\n';
            }
        }
    }

    void vector_capacitys()
    {
        vector_size();
        vector_empty();
        vector_max_size();
        vector_capacity();
        vector_reserve();
    }

    void vector_access_operator()
	{
    	std::cout << "\nOperator[]" << std::endl;
        ft::vector<int> myvector1(10);
        ft::vector<int>::size_type sz1 = myvector1.size();
        for (unsigned i = 0; i < sz1; i++)
            myvector1[i] = i;
        for (unsigned i = 0; i < sz1 / 2; i++)
        {
            int temp1;
            temp1 = myvector1[sz1 - 1 - i];
            myvector1[sz1 - 1 - i] = myvector1[i];
            myvector1[i] = temp1;
        }
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < sz1; i++)
            std::cout << ' ' << myvector1[i];
        std::cout << std::endl;
    }

    void vector_access_at()
    {
        std::cout << "\nAt() : " << std::endl;
        ft::vector<int> myvector1(10);
        for (unsigned i = 0; i < myvector1.size(); i++)
            myvector1.at(i) = i;
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1.at(i);
        std::cout << std::endl;
    }

    void vector_front()
	{
        std::cout << "\nFront() : " << std::endl;
        ft::vector<int> myvector1;
        myvector1.push_back(78);
        myvector1.push_back(16);
        std::cout << "myvector.front() : " << myvector1.front() << std::endl;
        myvector1.front() -= myvector1.back();
        std::cout << "myvector.front() : " << myvector1.front() << std::endl;
    }

    void vector_back()
    {
        std::cout << "\nBack() : " << std::endl;
        ft::vector<int> myvector1;
        myvector1.push_back(10);
        while (myvector1.back() != 0)
        {
            myvector1.push_back(myvector1.back() - 1);
        }
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    }

    void vector_elem_access()
    {
        vector_access_operator();
        vector_access_at();
        vector_front();
        vector_back();
    }

    void vector_clear()
	{
        std::cout << "\nClear() : " << std::endl;
        ft::vector<int> myvector1;
        myvector1.push_back(100);
        myvector1.push_back(200);
        myvector1.push_back(300);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.clear();
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.push_back(1101);
        myvector1.push_back(2202);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    }

    void vector_insert()
    {
        std::cout << "\nInsert() : " << std::endl;
        ft::vector<int> myvector1(3, 100);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        ft::vector<int>::iterator it1;
        it1 = myvector1.begin();
        it1 = myvector1.insert(it1, 200);
        myvector1.insert(it1, 2, 300);
        it1 = myvector1.begin();
        ft::vector<int> anothervector1(2, 400);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.insert(it1 + 2, anothervector1.begin(), anothervector1.end());
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        int myarray1[] = {501, 502, 503};
        myvector1.insert(myvector1.begin(), myarray1, myarray1 + 3);
        std::cout << "myvector contains:";
        for (it1 = myvector1.begin(); it1 < myvector1.end(); it1++)
            std::cout << ' ' << *it1 << std::endl;
    }

    void vector_insert_2()
    {
        ft::vector<int> vec1;
        vec1.push_back(10);
        vec1.push_back(20);
        vec1.push_back(30);
        vec1.push_back(40);
        ft::vector<int>::iterator it1 = vec1.insert(vec1.begin(), 3);
        vec1.insert(it1, 2);
        int i1 = 2;
        it1 = vec1.insert(vec1.begin() + i1, 7);
        std::cout << "The vector elements are: ";
        for (ft::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
            std::cout << *it1 << " " << std::endl;
    }

    void vector_erase()
    {
        std::cout << "\nErase() : " << std::endl;
        ft::vector<int> myvector;
        for (int i = 1; i <= 10; i++)
            myvector.push_back(i);
        ft::vector<int>::iterator it = myvector.erase(myvector.begin() + 5);
        ft::vector<int>::iterator it2 = myvector.erase(it, it + 2);
        myvector.erase(it2, it2 + 1);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }

    void vector_push_back()
	{
        std::cout << "\nPush_back() : " << std::endl;
        ft::vector<int> myvector1;
        ft::vector<int> myvector;
        for (int i = 1; i <= 100; i++)
            myvector.push_back(i);
        std::cout << "myvector stores " << int(myvector1.size()) << " numbers.\n";
    }

    void vector_pop_back()
    {
        std::cout << "\nPop_back() : " << std::endl;
        ft::vector<int> myvector1;
        int sum1(0);
        myvector1.push_back(100);
        myvector1.push_back(200);
        myvector1.push_back(300);
        std::cout << "Size before : " << myvector1.size() << std::endl;
        while (!myvector1.empty())
        {
            sum1 += myvector1.back();
            myvector1.pop_back();
        }
        std::cout << "Total " << sum1 << '\n';
        std::cout << "Size after : " << myvector1.size() << std::endl;
    }

    void vector_resize()
    {
        std::cout << "\nResize() : " << std::endl;
        ft::vector<int> myvector1;
        for (int i = 1; i < 10; i++)
            myvector1.push_back(i);
        myvector1.resize(5);
        std::cout << "myvector contains:";
        for (size_t i1 = 0; i1 < myvector1.size(); i1++)
            std::cout << ' ' << myvector1[i1];
        myvector1.resize(8, 100);
        std::cout << "\nmyvector contains:";
        for (size_t i2 = 0; i2 < myvector1.size(); i2++)
            std::cout << ' ' << myvector1[i2];
		myvector1.resize(4);
        std::cout << "\nmyvector contains:";
        for (size_t i3 = 0; i3 < myvector1.size(); i3++)
            std::cout << ' ' << myvector1[i3];
        std::cout << std::endl;
    }

    void vector_swap()
	{
        std::cout << "\nSwap() : " << std::endl;
        ft::vector<int> foo1(3, 100); // three ints with a value of 100
        ft::vector<int> bar1(5, 100); // five ints with a value of 200
        ft::vector<int>::iterator it_foo = foo1.begin();
        ft::vector<int>::iterator it_bar = bar1.begin();
        (++(++(it_bar)));
        std::cout << "Size foo1 before " << foo1.size() << std::endl;
        std::cout << "Capa foo1 before " << foo1.capacity() << std::endl;
        std::cout << "Size bar1 before " << bar1.size() << std::endl;
        std::cout << "Capa bar1 before " << bar1.capacity() << std::endl;
        foo1.swap(bar1);
        std::cout << "Size foo1 after " << foo1.size() << std::endl;
        std::cout << "Capa foo1 after " << foo1.capacity() << std::endl;
        std::cout << "Size bar1 after " << bar1.size() << std::endl;
        std::cout << "Capa bar1 after " << bar1.capacity() << std::endl;
        std::cout << "foo contains:";
        for (unsigned i = 0; i < foo1.size(); i++)
            std::cout << ' ' << foo1[i];
        std::cout << std::endl;
        std::cout << "bar contains:";
        for (unsigned i = 0; i < bar1.size(); i++)
            std::cout << ' ' << bar1[i];
        std::cout << std::endl;

        std::cout << "Iterators swapped" << std::endl;
        for (; it_foo != bar1.end(); it_foo++)
            std::cout << *it_foo << " ";
        std::cout << std::endl;
        for (; it_bar != foo1.end(); it_bar++)
            std::cout << *it_bar << " ";
        std::cout << std::endl;
    }

    void vector_modifiers()
    {
        vector_clear();
        vector_insert();
        vector_insert_2();
        vector_erase();
        vector_push_back();
        vector_pop_back();
        vector_resize();
        vector_swap();
    }

    void vector_assign()
    {
        std::cout << "\nAssign() : " << std::endl;
        ft::vector<int> first1;
        ft::vector<int> second1;
        ft::vector<int> third1;
        first1.assign(7, 100);
        ft::vector<int>::iterator it1;
        it1 = first1.begin() + 1;
        second1.assign(it1, first1.end() - 1);
        int myints1[] = {1776, 7, 4};
        third1.assign(myints1, myints1 + 3);
        std::cout << "Size of first: " << int(first1.size()) << '\n';
        std::cout << "Size of second: " << int(second1.size()) << '\n';
        std::cout << "Size of third: " << int(third1.size()) << '\n';
	}

    void vector_get_allocator()
    {
        std::cout << "\nGet_allocator() : " << std::endl;
        ft::vector<int> myvector;
        int *p;
        unsigned int i;
        p = myvector.get_allocator().allocate(5);
        for (i = 0; i < 5; i++)
            myvector.get_allocator().construct(&p[i], i);
        std::cout << "The allocated array contains:";
        for (i = 0; i < 5; i++)
            std::cout << ' ' << p[i];
        std::cout << '\n';
        for (i = 0; i < 5; i++)
            myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p, 5);
    }

    void vector_operators()
	{
        std::cout << "\nRelational operators() : " << std::endl;
        ft::vector<int> foo(2, 200);
        ft::vector<int> bar;
        bar.push_back(200);
        bar.push_back(200);
        bar.push_back(300);
        bar.push_back(400);
        if (foo == bar)
            std::cout << "foo and bar are equal\n";
        if (foo != bar)
            std::cout << "foo and bar are not equal\n";
        if (foo < bar)
            std::cout << "foo is less than bar\n";
        if (foo > bar)
            std::cout << "foo is greater than bar\n";
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar\n";
    }


    void map_constructor_1()
    {
        std::cout << "Constructor (1)\n";
        ft::map<int, char> test_one;

        for (int i = 0; i < 10; i++) {
            test_one.insert(ft::pair<int, char>(i, 'a'));
        }

        ft::map<int, char> test_two(test_one);
        for (ft::map<int, char>::iterator it = test_one.begin(); it != test_one.end(); it++)
            std::cout << it->first << " -> " << it->second << "  " << std::endl;
        for (ft::map<int, char>::iterator it = test_two.begin(); it != test_two.end(); it++)
            std::cout << it->first << " -> " << it->second << "  " << std::endl;
    }

    void map_constructor_2()
    {
        std::cout << "\nConstructor (2)\n";
        ft::map<int, char> test_one;

        for (int i = 0; i < 10; i++)
            test_one.insert(ft::pair<int, char>(i, 'a'));

        ft::map<int, char> test_two(test_one.begin(), test_one.end());
        for (ft::map<int, char>::iterator it = test_one.begin(); it != test_one.end(); it++)
            std::cout << it->first << " -> " << it->second << "  " << std::endl;
        for (ft::map<int, char>::iterator it = test_two.begin(); it != test_two.end(); it++)
            std::cout << it->first << " -> " << it->second << "  " << std::endl;
    }

    void map_equals_overload_1()
    {
        std::cout << "\n0perator=\n";
        ft::map<int, char> test_one;

        for (int i = 0; i < 10; i++)
            test_one.insert(ft::pair<int, char>(i, 'a'));

        ft::map<int, char> test_two = test_one;
        for (ft::map<int, char>::iterator it = test_one.begin(); it != test_one.end(); it++)
            std::cout << it->first << " -> " << it->second << "  "  << std::endl;
        for (ft::map<int, char>::iterator it = test_two.begin(); it != test_two.end(); it++)
            std::cout << it->first << " -> " << it->second << "  "  << std::endl;
    }

    void map_constructors()
    {
        map_constructor_1();
        map_constructor_2();
        map_equals_overload_1();
    }

    void map_begin_1()
    {
        std::cout << "\nBegin()\n";
        ft::map<int, char> test;

        test.insert(ft::pair<int, char>(100, 'a'));
        ft::map<int, char>::iterator it = test.begin();
        std::cout << it->first << " -> " << it->second << "  ";
        std::cout << std::endl;
    }

    void map_end_1()
    {
        std::cout << "\nEnd()\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10; i++)
            test.insert(ft::pair<int, int>(i, i + 100));
        for (ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << it->first << " -> " << it->second << " " << std::endl;
    }

    void map_c_begin_end()
    {
        std::cout << "\nConst Begin()/End()\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10; i++)
            test.insert(ft::pair<int, int>(i, i + 100));
        for (ft::map<int, int>::const_iterator c_it = test.begin(); c_it != test.end(); c_it++)
            std::cout << c_it->first << " -> " << c_it->second << " " << std::endl;
        std::cout << std::endl;

        ft::map<int, int>::iterator it = test.begin();
        ft::map<int, int>::const_iterator it_c = test.begin();
        while(it++ == it_c++ && it != test.end() && it_c != test.end())
            std::cout << " Iterator : " << it->first << " -> " << it->second << " " << " Const iterator : " << it_c->first << " -> " << it_c->second << std::endl;
    }

    void map_end_2()
    {
        std::cout << "\nEnd() (2)\n";
        ft::map<int, int> test;
        for (int i = 0; i < 10; i++)
            test.insert(ft::pair<int, int>(i, i + 100));
        ft::map<int, int>::iterator it = test.end();
        it--;
        for (; it != test.begin(); it--)
            std::cout << it->first << " -> " << it->second << " " << std::endl;
    }

    void map_rbegin_1()
    {
        std::cout << "\nReverse Begin()\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10; i++)
            test.insert(ft::pair<int, int>(i, i + 100));
        for (ft::map<int, int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
            std::cout << it->first << " -> " << it->second << " " << std::endl;
    }

    void map_rend_1()
    {
        std::cout << "\nReverse End()\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10; i++)
            test.insert(ft::pair<int, int>(i, i + 100));
        ft::map<int, int>::reverse_iterator it = test.rend();
        it--;
        for (; it != test.rbegin(); it--)
            std::cout << it->first << " -> " << it->second << " " << std::endl;
    }

    void map_c_rbegin_rend()
    {
        std::cout << "\nConst Reverse Begin()/End()\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10; i++)
            test.insert(ft::pair<int, int>(i, i + 100));
        for (ft::map<int, int>::const_reverse_iterator c_it = test.rbegin(); c_it != test.rend(); c_it++)
            std::cout << c_it->first << " -> " << c_it->second << " " << std::endl;
        std::cout << std::endl;

        ft::map<int, int>::reverse_iterator it = test.rbegin();
        ft::map<int, int>::const_reverse_iterator it_c = test.rbegin();
        while(it++ == it_c++ && it != test.rend() && it_c != test.rend())
            std::cout << " Iterator : " << it->first << " -> " << it->second << " " << " Const iterator : " << it_c->first << " -> " << it_c->second << std::endl;
    }

    void map_iterators()
    {
        map_begin_1();
        map_end_1();
        map_end_2();
        map_c_begin_end();
        map_rbegin_1();
        map_rend_1();
        map_c_rbegin_rend();
    }

    void map_empty_1()
    {
        std::cout << "\nEmpty()\n";
        ft::map<int, int> test;

        std::cout << "test.empty() = " << test.empty() << std::endl;
        test.insert(ft::pair<int, int>(100, 100));
        std::cout << "test.empty() = " << test.empty() << std::endl;
    }

    void map_size_1()
    {
        std::cout << "\nSize()\n";
        ft::map<int, int> test;

        std::cout << "test.size() = " << test.size() << std::endl;
        for (int i = 0; i < 1000; i++)
            test.insert(ft::pair<int, int>(i, 100));
        std::cout << "test.size() = " << test.size() << std::endl;
    }

    void map_max_size_1()
    {
        std::cout << "\nMax size\n";
        ft::map<int, int>		test_one;
        ft::map<int, char>	    test_two;

        std::cout << "test_one.max_size() = " << test_one.max_size() << std::endl;
        std::cout << "test_two.max_size() = " << test_two.max_size() << std::endl;
    }

    void map_capacity()
    {
        map_empty_1();
        map_size_1();
        map_max_size_1();
    }

    void map_brackets_1()
    {
        std::cout << "\nOperator[]\n";
        ft::map<int, char> test;

        for (int i = 0 ; i < 100; i++) {
            if (i % 2 == 0)
                test.insert(ft::pair<int, char>(i, 'a'));
            else
                test.insert(ft::pair<int, char>(i, 'b'));
        }
        std::cout << "test.size() = " << test.size() << std::endl;
        std::cout << "test[5] = " << test[5] << std::endl;
        std::cout << "test[50] = " << test[50] << std::endl;
        std::cout << "test[200] = " << test[200] << std::endl;
        std::cout << "test.size() = " << test.size() << std::endl;
    }

    void map_access_at()
    {
        std::cout << "\nAt\n";
        ft::map<int, int> test;

        for (int i = 0 ; i < 3; i++) {
            test.insert(ft::pair<int, int>(i, i + 1));
        }
        std::cout << "Map contains : " << std::endl;
        for (unsigned i = 0; i < test.size(); i++)
            std::cout << ' ' << test.at(i);
        // try {
        //     std::cout << ' ' << test.at(3);
        // }
        // catch(const std::exception& e) {
		//     std::cerr << e.what() << '\n';
	    // }
        std::cout << std::endl;
    }

    void map_element_access()
    {
        map_brackets_1();
        map_access_at();
    }

    void map_insert_1()
    {
        std::cout << "Insert (1)\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100000; i++) {
            test.insert(ft::pair<int, int>(i, i + 1));
        }
        ft::pair<ft::map<int, int>::iterator, bool> pair = test.insert(ft::pair<int, int>(10, 0));
        std::cout << pair.first->first << " = " << pair.second << std::endl;
        pair = test.insert(ft::pair<int, int>(123456789, 0));
        std::cout << pair.first->first << " = " << pair.second << std::endl;
        std::cout << "map.size() = " << test.size() << std::endl;
        std::cout << "test[1] = " << test[1] << std::endl;
        std::cout << "test[10] = " << test[10] << std::endl;
        std::cout << "test[100] = " << test[100] << std::endl;
    }

    void map_insert_2()
    {
        std::cout << "\nInsert (2)\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10000; i++) {
            test.insert(ft::pair<int, int>(10000 - i, i));
        }
        std::cout << "map.size() = " << test.size() << std::endl;
        std::cout << "test[1] = " << test[1] << std::endl;
        std::cout << "test[10] = " << test[10] << std::endl;
        std::cout << "test[100] = " << test[100] << std::endl;
    }

    void map_insert_3()
    {
        std::cout << "\nInsert (3)\n";
        ft::map<int, int> test;
        ft::map<int, int> test_two;
        ft::map<int, int> test_three;

        for (int i = 0; i < 1000; i++) {
            int x = rand() % 1000;
            test.insert(ft::pair<int, int>(x, i));
        }
        std::cout << "test.size() = " << test.size() << std::endl;
        std::cout << "test[1] = " << test[1] << std::endl;
        std::cout << "test[10] = " << test[10] << std::endl;
        std::cout << "test[100] = " << test[100] << std::endl;
        test_two.insert(test.begin(), test.end());
        std::cout << "test_two.size() = " << test_two.size() << std::endl;
        std::cout << "test[1] = " << test_two[1] << std::endl;
        std::cout << "test[10] = " << test_two[10] << std::endl;
        std::cout << "test[100] = " << test_two[100] << std::endl;
    }

    void map_erase_1()
    {
        std::cout << "\nErase (1)\n";
        ft::map<int, int> test;
        int i = 0;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 1));
        }
        std::cout << "size() = " << test.size() << std::endl;
        std::cout << "test[1] = " << test[1] << std::endl;
        std::cout << "test[50] = " << test[50] << std::endl;
        i += test.erase(1);
        i += test.erase(50);
        i += test.erase(101);
        std::cout << "size() = " << test.size() << std::endl;
        std::cout << "test[1] = " << test[1] << std::endl;
        std::cout << "test[50] = " << test[50] << std::endl;
        std::cout << "Elements erased : " << i << std::endl;
    }

    void map_erase_2()
    {
        std::cout << "\nErase (2)\n";
        ft::map<int, int> test;

        for (int i = 0; i < 10; i++) {
            test.insert(ft::pair<int, int>(i, i + 1));
        }

        std::cout << "size() = " << test.size() << std::endl;
        test.erase(test.begin(), test.end());
        std::cout << "size() = " << test.size() << std::endl;
    }

    void map_erase_3()
    {
        std::cout << "\nErase (3)\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 1));
        }
        std::cout << "size() = " << test.size() << std::endl;
        std::cout << "test[0] = " << test[0] << std::endl;
        test.erase(test.begin());
        std::cout << "size() = " << test.size() << std::endl;
        std::cout << "test[0] = " << test[0] << std::endl;
    }

    void map_swap_1()
    {
        std::cout << "\nSwap\n";
        ft::map<int, int> test;
        ft::map<int, int> test_two;

        for (int i = 0; i < 10; i++) {
            test.insert(ft::pair<int, int>(i, i + 1));
        }
        for (int i = 0; i < 10; i++) {
            test_two.insert(ft::pair<int, int>(i + 1, i + 1));
        }

        for (ft::map<int, int>::iterator it_one = test.begin(); it_one != test.end(); it_one++) {
            std::cout << it_one->first;
        }
        std::cout << std::endl;
        for (ft::map<int, int>::iterator it_two = test_two.begin(); it_two != test_two.end(); it_two++) {
            std::cout << it_two->first;
        }
        std::cout << std::endl;

        test.swap(test_two);

        for (ft::map<int, int>::iterator it_one2 = test.begin(); it_one2 != test.end(); it_one2++) {
            std::cout << it_one2->first;
        }
        std::cout << std::endl;
        for (ft::map<int, int>::iterator it_two2 = test_two.begin(); it_two2 != test_two.end(); it_two2++) {
            std::cout << it_two2->first;
        }
        std::cout << std::endl;
    }

    void map_modifiers()
    {
        map_insert_1();
        map_insert_2();
        map_insert_3();
        map_erase_1();
        map_erase_2();
        map_erase_3();
        map_swap_1();
    }

    void map_find_1()
    {
        std::cout << "\nFind\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 100));
        }
        ft::map<int, int>::iterator it = test.find(50);
        std::cout << it->first << "->" << it->second << std::endl;
        it = test.find(700);
        if (it == test.end())
            std::cout << "it == test.end()" << std::endl;
    }

    void map_count_1()
    {
        std::cout << "\nCount\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 100));
        }
        size_t c = test.count(50);
        std::cout << c << std::endl;
        c = test.count(1000);
        std::cout << c << std::endl;
    }

    void map_lower_bound_1()
    {
        std::cout << "\nLower bound\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 100));
        }
        ft::map<int, int>::iterator it = test.lower_bound(40);
        std::cout << it->first << "->" << it->second << std::endl;
        it = test.lower_bound(500);
        if (it == test.end())
            std::cout << "it == test.end()" << std::endl;
    }

    void map_upper_bound_1()
    {
        std::cout << "\nUpper bound\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 100));
        }
        ft::map<int, int>::iterator it = test.upper_bound(40);
        std::cout << it->first << "->" << it->second << std::endl;
        it = test.upper_bound(500);
        if (it == test.end())
            std::cout << "it == test.end()" << std::endl;
    }

    void map_equal_range_1()
    {
        std::cout << "\nEqual range\n";
        ft::map<int, int> test;

        for (int i = 0; i < 100; i++) {
            test.insert(ft::pair<int, int>(i, i + 100));
        }
        ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> it_pair = test.equal_range(5);
        std::cout << it_pair.first->first << "->" << it_pair.first->second << std::endl;
        std::cout << it_pair.second->first << "->" << it_pair.second->second << std::endl;
        it_pair = test.equal_range(1000);
        if (it_pair.first == test.end())
            std::cout << "it_pair.first == test.end()" << std::endl;
        if (it_pair.second == test.end())
            std::cout << "it_pair.second == test.second()" << std::endl;
    }

    void map_operations()
    {
        map_find_1();
        map_count_1();
        map_lower_bound_1();
        map_upper_bound_1();
        map_equal_range_1();
    }

    void stack_test_int()
    {
        ft::stack<int> a;
		std::cout << "EMPTY : ";
		std::cout << a.empty() << std::endl;
		std::cout << "SIZE : ";
		std::cout << a.size() << std::endl;
		std::cout << "-> PUSH" << std::endl;
		for (int i = 0; i < 30; i++)
			a.push(i * 3);
		std::cout << "EMPTY : ";
		std::cout << a.empty() << std::endl;
		std::cout << "SIZE : ";
		std::cout << a.size() << std::endl;
		std::cout << "TOP : ";
		std::cout << a.top() << std::endl;
		std::cout << "-> POP" << std::endl;
		for (int i = 0; i < 5; i++)
			a.pop();
		std::cout << "SIZE : ";
		std::cout << a.size() << std::endl;
		std::cout << "TOP : ";
		std::cout << a.top() << std::endl;
    }

    void stack_test_float()
    {
		ft::stack<float> b;
		std::cout << std::endl;
		std::cout << "EMPTY : ";
		std::cout << b.empty() << std::endl;
		std::cout << "SIZE : ";
		std::cout << b.size() << std::endl;
		std::cout << "-> PUSH " << std::endl;
		float f = -0.5f;
		for (int i = 0; i < 30; i++)
		{
			b.push(f);
			f += 0.6f;
		}
		std::cout << "EMPTY : ";
		std::cout << b.empty() << std::endl;
		std::cout << "SIZE : ";
		std::cout << b.size() << std::endl;
		std::cout << "TOP : ";
		std::cout << b.top() << std::endl;
		std::cout << "-> POP" << std::endl;
		for (int i = 0; i < 5; i++)
			b.pop();
		std::cout << "SIZE : ";
		std::cout << b.size() << std::endl;
		std::cout << "TOP : ";
		std::cout << b.top() << std::endl;
	}

    void stack_test_list()
    { 
        std::list<int>	ctnr;

	    ft::stack<int, std::list<int> > b(ctnr);

		std::cout << std::endl;
		std::cout << "EMPTY : ";
		std::cout << b.empty() << std::endl;
		std::cout << "SIZE : ";
		std::cout << b.size() << std::endl;
		std::cout << "-> PUSH" << std::endl;
		
		for (int i = 0; i < 30; i++)
			b.push(i * 3);
        
		std::cout << "EMPTY : ";
		std::cout << b.empty() << std::endl;
		std::cout << "SIZE : ";
		std::cout << b.size() << std::endl;
		std::cout << "TOP : ";
		std::cout << b.top() << std::endl;
		std::cout << "-> POP" << std::endl;
		for (int i = 0; i < 5; i++)
			b.pop();
		std::cout << "SIZE : ";
		std::cout << b.size() << std::endl;
		std::cout << "TOP : ";
		std::cout << b.top() << std::endl;
	}

int main(void)
{
    std::cout << "\033[1;31m------------- Vector Constructors -------------\033[0m" << std::endl;
    vector_constructors();
    std::cout << "\n\033[1;31m------------- Vector Iterators -------------\033[0m" << std::endl;
    vector_iterators();
    std::cout << "\n\033[1;31m------------- Vector Capacity -------------\033[0m" << std::endl;
    vector_capacitys();
    std::cout << "\n\033[1;31m------------- Vector Elem Access -------------\033[0m" << std::endl;
    vector_elem_access();
    std::cout << "\n\033[1;31m------------- Vector Modifiers -------------\033[0m" << std::endl;
    vector_modifiers();
    std::cout << "\n\033[1;31m------------- Vector Assign -------------\033[0m" << std::endl;
    vector_assign();
    std::cout << "\n\033[1;31m------------- Vector Get Allocator -------------\033[0m" << std::endl;
    vector_get_allocator();
    std::cout << "\n\033[1;31m------------- Vector Operators -------------\033[0m" << std::endl;
    vector_operators();


    std::cout << "\n\033[1;31m------------- Map Constructors -------------\033[0m" << std::endl;
    map_constructors();
    std::cout << "\n\033[1;31m------------- Map Iterators -------------\033[0m" << std::endl;
    map_iterators();
    std::cout << "\n\033[1;31m------------- Map Capacity -------------\033[0m" << std::endl;
    map_capacity();
    std::cout << "\n\033[1;31m------------- Map Elem Access -------------\033[0m" << std::endl;
    map_element_access();
    std::cout << "\n\033[1;31m------------- Map Modifiers -------------\033[0m" << std::endl;
    map_modifiers();
    std::cout << "\n\033[1;31m------------- Map Operations -------------\033[0m" << std::endl;
    map_operations();


    std::cout << "\n\033[1;31m------------- Stack Test Int -------------\033[0m" << std::endl;
    stack_test_int();
    std::cout << "\n\033[1;31m------------- Stack Test Float -------------\033[0m" << std::endl;
    stack_test_float();
    std::cout << "\n\033[1;31m------------- Stack Test List -------------\033[0m" << std::endl;
    stack_test_list();

	return (0);
}