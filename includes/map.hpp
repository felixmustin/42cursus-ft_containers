#ifndef MAP_HPP
# define MAP_HPP

#include "AVL_tree.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "util.hpp"

#include <memory>


namespace ft {

    template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > >
    
    class map {

        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef Compare                                     key_compare;
            typedef	ft::pair<const key_type, mapped_type>	    value_type;
            typedef Allocator                                   allocator_type;
                       
            typedef AVLNode<value_type>                                             map_node;
            typedef typename Allocator::template rebind<map_node>::other            allocator_node;

	        typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
		    typedef typename allocator_type::pointer            pointer;
		    typedef typename allocator_type::const_pointer      const_pointer;
            typedef	typename allocator_type::difference_type 	difference_type;
			typedef	typename allocator_type::size_type 			size_type;

            typedef	ft::map_iterator<key_type, mapped_type>		                        iterator;
			typedef	ft::map_iterator<key_type, mapped_type, true>	                            const_iterator;
			typedef	ft::reverse_iterator<iterator>						                        reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>						                const_reverse_iterator;


        private:
            map_node*       _root;
            map_node*       _begin;
            map_node*       _end;
            size_type       _size;
            key_compare     _comp;
            allocator_node  _alloc;

        public:
            /*-----------Value compare------------*/
            class value_compare {
                friend class map;
                protected:
                    Compare comp;
                    value_compare( Compare c ) : comp(c) {}
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;

                    bool operator()( const value_type& lhs, const value_type& rhs ) const {
                        return (comp(lhs.first, rhs.first));
                    }
            };


            //Empty constructor
            explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) :  _root(), _begin(), _end(), _size(0), _comp(comp), _alloc(alloc)
            {
                _root = _alloc.allocate(1);
                _alloc.construct(_root, value_type());

                _begin = _alloc.allocate(1);
                _alloc.construct(_begin, value_type());

                _end = _alloc.allocate(1);
                _alloc.construct(_end, value_type());

                _begin->parent = _root;
                _end->parent = _root;
                _root->left = _begin;
                _root->right = _end;
            }
            //Range constructor
            template< class InputIt >
            map( InputIt first, InputIt last, const key_compare& comp = key_compare(), const Allocator& alloc = Allocator() ) : _root(), _begin(), _end(), _size(0), _comp(comp), _alloc(alloc)
            {
                _root = _alloc.allocate(1);
                _alloc.construct(_root, value_type());

                _begin = _alloc.allocate(1);
                _alloc.construct(_begin, value_type());

                _end = _alloc.allocate(1);
                _alloc.construct(_end, value_type());

                _begin->parent = _root;
                _end->parent = _root;
                _root->left = _begin;
                _root->right = _end;

                insert(first, last);
            }
            //Copy constructor
            map( const map& other ) : _root(), _begin(), _end(), _size(0), _comp(other._comp), _alloc(other._alloc) 
            {
                 _root = _alloc.allocate(1);
                _alloc.construct(_root, value_type());

                _begin = _alloc.allocate(1);
                _alloc.construct(_begin, value_type());

                _end = _alloc.allocate(1);
                _alloc.construct(_end, value_type());

                _begin->parent = _root;
                _end->parent = _root;
                _root->left = _begin;
                _root->right = _end;

                insert(other.begin(), other.end());
            }
            //Destructor
	        ~map() 
            {
                if ((!size())) {
                    _alloc.destroy(_begin);
                    _alloc.deallocate(_begin, 1);
                    _alloc.destroy(_end);
                    _alloc.deallocate(_end, 1);
                    if (_root) {
                        _alloc.destroy(_root);
                        _alloc.deallocate(_root, 1);
                    }
                }
                else
                    destroy_tree(_root);
            }
            //Operator =
            map& operator=(const map& other) 
            {
                if (this != &other) {
                    map tmp(other);
                    swap_content(_root, tmp._root);
                    swap_content(_begin, tmp._begin);
                    swap_content(_end, tmp._end);
                    swap_content(_size, tmp._size);
                    swap_content(_comp, tmp._comp);
                    swap_content(_alloc, tmp._alloc);
                }
                return (*this);
            }
            /*-----------Allocator------------*/
            allocator_type get_allocator() const
            {
                return (this->_alloc);
            }

            /*-----------Element access------------*/
            
            mapped_type& operator[](const Key& key) {

                return insert(ft::make_pair(key, mapped_type())).first->second;
             }

            mapped_type& at(const Key& key) 
            {
                if (find(key) == this->end())
                    throw std::out_of_range("map::at:  key not found");
                return (find(key)->second);
            }

            mapped_type& at(const Key& key) const 
            {
                if (find(key) == this->end())
                    throw std::out_of_range("map::at:  key not found");
                return ( const_cast <mapped_type&>(find(key)->second));
            }

            /*-----------Iterators------------*/
            iterator begin() {
                if (!size())
                    return end();
                else
                    return iterator(_begin->parent);
            }
            const_iterator begin() const {
                if (!size())
                    return end();
                else
                    return const_iterator(_begin->parent);
	        }
            iterator end() {
                    return iterator(_end);
            }
            const_iterator end() const {
                    return const_iterator(_end);
	        }

            reverse_iterator rbegin() { 
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const {
                return const_reverse_iterator(end());
            }
            reverse_iterator rend() {
                    return reverse_iterator(begin());
            }
            const_reverse_iterator rend() const {
                    return const_reverse_iterator(begin());
	        }


            /*-----------Capacity------------*/
            bool empty() const { 
                return (_size == 0);
            }

            size_type size() const { 
                return (_size);
            }

	        size_type max_size() const { 
                return (_alloc.max_size());
            }

            /*-----------Modifiers------------*/
            //Insert value
            ft::pair<iterator, bool> insert( const value_type& value )
            {
                bool found = false;
                map_node* return_node = NULL;

                _root = insert_node(_root, NULL, value, found, return_node);
                setup_begin_end();

                if (found)
                    return ft::make_pair(iterator(return_node), false);
                else
                    return ft::make_pair(iterator(return_node), true);
            }
            //Insert iterator
            iterator insert(iterator pos, const value_type& value )
            {
                (void) pos;
                return ((insert(value)).first);
            }
            //Insert range
            template< class InputIterator > 
            void insert( InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral <InputIterator>::value, InputIterator>::type * = nullptr)
            {
                while (first != last) {
                    insert(*first);
                    ++first;
                }
            }

            //Erase
            size_type erase( const Key& key )
            {
                bool found = false;

                _root = delete_node(_root, key, found);
                setup_begin_end();

                if (found)
                    return (1);
                else
                    return (0);
            }
            void erase( iterator pos )
            {
                erase(pos->first);
            }
            void erase( iterator first, iterator last )
            {          
                key_type save;    
                while (first != last) {
                    iterator tmp(first);
                    ++first;
                    if (first != last)
                        save = first->first;
                    erase(tmp);
                    if (first != last)
                        first = find(save);
                }
            }

            void swap(map& other)
            {
                swap_content(_root, other._root);
                swap_content(_begin, other._begin);
                swap_content(_end, other._end);
                swap_content(_size, other._size);
                swap_content(_comp, other._comp);
                swap_content(_alloc, other._alloc);
            }

            void clear() 
            {
                erase(begin(), end());
            }

            /*-----------Lookup------------*/
            iterator find( const Key& key ) 
            {
                iterator e = end();
                for (iterator begin_it = begin(); begin_it != e; ++begin_it)
                {
                    if (begin_it->first == key)
                        return begin_it;
                }
                return e;
            }
            const_iterator find( const Key& key ) const
            {
                const_iterator e = end();
                for (const_iterator begin_it = begin(); begin_it != e; begin_it++)
                {
                    if (begin_it->first == key)
                        return begin_it;
                }
                return e;
            }
            size_type count( const Key& key ) const
            {
                if (find(key) != end())
			        return 1;
		        else
			        return 0;
            }

            iterator lower_bound( const Key& key )
            {
                iterator itr = begin();
                while (itr != end()) {
                    if (!_comp(itr->first, key))
				        break;
			        ++itr;
                }
                return (itr);
            }
            const_iterator lower_bound( const Key& key ) const
            {
                const_iterator itr = begin();
                while (itr != end()) {
                    if (!_comp(itr->first, key))
				        break;
			        ++itr;
                }
                return (itr);
            }

            iterator upper_bound( const Key& key )
            {
                iterator itr = begin();
                while (itr != end()) {
                    if (_comp(key, itr->first))
				        break;
			        ++itr;
                }
                return (itr);
            }
            const_iterator upper_bound( const Key& key ) const
            {
                const_iterator itr = begin();
                while (itr != end()) {
                    if (_comp(key, itr->first))
				        break;
			        ++itr;
                }
                return (itr);
            }

            ft::pair<iterator,iterator> equal_range( const Key& key )
            {
                iterator low = lower_bound(key);
                iterator up = upper_bound(key);
                return (ft::make_pair(low, up));
            }	

            ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
            {
                const_iterator low = lower_bound(key);
                const_iterator up = upper_bound(key);
                return (ft::make_pair(low, up));
            }


            /*-----------Observers------------*/
            key_compare key_comp() const {
                return _comp;
            }

            value_compare value_comp() const {
                return value_compare(_comp);
            }



        /*-----------Private helper------------*/
        private:
            template<class Type>
            void swap_content(Type& a, Type& b) {
                Type tmp(a);
                a = b;
                b = tmp;
            }

            void destroy_tree(map_node *node) {
                if (node) {
                    destroy_tree(node->left);
                    destroy_tree(node->right);
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                }
	        }

            map_node *find_leftest_node(map_node *node) {
                map_node *current = node;
                while(current && current->left && current->left != _begin)
                    current = current->left;
                return current;
            }
            map_node *find_rightest_node(map_node *node) {
                map_node *current = node;
                while(current && current->right && current->right != _end)
                    current = current->right;
                return current;
            }
            void setup_begin_end() {

                map_node *leftest = find_leftest_node(_root);
                map_node *rightest = find_rightest_node(_root);

                _begin->parent = leftest;
                if (leftest)
                    leftest->left = _begin;

                _end->parent = rightest;
                if (rightest)
                    rightest->right = _end;
            }

            int max(int a, int b) {
                if (a > b)
                    return a;
                else
                    return b;
            }

            int height(map_node* node) {
                if (!node || node == _begin || node == _end || size() == 0)
                    return 0;
                return (node->height);
            }

            int getBalance(map_node *node) {
                if (!node || node == _begin || node == _end || size() == 0)
                    return 0;
                return (height(node->left) - height(node->right));
            }

            map_node* right_rotate(map_node* node) {
                key_compare compare = key_compare();

                map_node* tmp = node->left;
                if (tmp && tmp != _begin) {
                    node->left = tmp->right;
                    if (tmp->right && tmp->right != _end)
                        tmp->right->parent = node;
                    tmp->right = node;
                    tmp->parent = node->parent;
                    node->parent = tmp;
                    if (tmp->parent && compare(node->value.first, tmp->parent->value.first))
                        tmp->parent->left = tmp;
                    else if (tmp->parent && compare(tmp->parent->value.first, node->value.first))
                        tmp->parent->right = tmp;
                    node = tmp;
                    if (node->left && node->left != _begin)
                        node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
                    if (node->right && node->right != _end)
                        node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
                    if (node != _end && node != _begin)
                        node->height = max(height(node->left), height(node->right)) + 1;
                    if (node->parent)
                        node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
                }
                return node;
            }

            map_node* left_rotate(map_node* node)
            {
                key_compare compare = key_compare();

                map_node* tmp = node->right;
                if (tmp && tmp != _end) {
                    node->right = tmp->left;
                    if (tmp->left && tmp->left != _begin)
                        tmp->left->parent = node;
                    tmp->left = node;
                    tmp->parent = node->parent;
                    node->parent = tmp;
                    if (tmp->parent && compare(node->value.first, tmp->parent->value.first))
                        tmp->parent->left = tmp;
                    else if (tmp->parent && compare(tmp->parent->value.first, node->value.first))
                        tmp->parent->right = tmp;
                    node = tmp;

                    if (node->left && node->left != _begin)
                        node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
                    if (node->right && node->right != _end)
                        node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
                    if (node != _end && node != _begin)
                        node->height = max(height(node->left), height(node->right)) + 1;
                    if (node->parent)
                        node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
                }
                return node;
            }

            //********** FOR INSERT ***********//
            map_node* balance_insert(map_node* node, const value_type &val) {
                key_compare compare = key_compare();
                int balance = getBalance(node);

                //left-left case
                if (balance > 1 && node->left && node->left != _begin && compare(val.first, node->left->value.first))
                    return right_rotate(node);
                //left-right case
                else if (balance > 1 && node->left && node->left != _begin && compare(node->left->value.first, val.first)) {
                    node->left = left_rotate(node->left);
                    return right_rotate(node);
                }
                //right-right case
                if (balance < -1 && node->right && node->right != _end && compare(node->right->value.first, val.first))
                    return left_rotate(node);
                //right-left case
                else if (balance < -1 && node->right && node->right != _end && compare(val.first, node->right->value.first)) {
                    node->right = right_rotate(node->right);
                    return left_rotate(node);
                }
                return node;
            }

            map_node* create_new_node(const value_type& val, map_node* parent, bool &found, map_node*& return_node)
            {
                map_node *new_node = _alloc.allocate(1);
                _alloc.construct(new_node, val);
                new_node->height = 1;
                new_node->parent = parent;
                found = false;
                return_node = new_node;
                _size++;
                return new_node;
            }

            map_node* insert_node(map_node *node, map_node* parent, const value_type &val, bool &found, map_node*& return_node)
            {
                key_compare compare = key_compare();
                if (size() == 0)
                {
                    if (_root) {
                        _alloc.destroy(_root);
                        _alloc.deallocate(_root, 1);
                    }
                    return create_new_node(val, parent, found, return_node);
                }
                else if (!node || node == _begin || node == _end)
                    return create_new_node(val, parent, found, return_node);
                //BST
                if (compare(val.first, node->value.first))
                    node->left = insert_node(node->left, node, val, found, return_node);
                else if (compare(node->value.first, val.first))
                    node->right = insert_node(node->right, node, val, found, return_node);
                else
                {
                    found = true;
                    return_node = node;
                    return node;
                }
                //height
                node->height = 1 + max(height(node->left), height(node->right));
                //balance
                return balance_insert(node, val);
            }


            //********** FOR ERASE ***********//
            map_node* balance_erase(map_node* root)
            {
                int firstheight = 0;
                int secondheight = 0;

                if (root->left && root->left != _begin)
                    firstheight = root->left->height;
                if (root->right && root->right != _end)
                    secondheight = root->right->height;

                // If current node is not balanced
                if (abs(firstheight - secondheight) > 1) {
                    if (firstheight < secondheight) {
                        int rightheight1 = 0;
                        int rightheight2 = 0;
                        if (root->right->right && root->right->right != _end)
                            rightheight2 = root->right->right->height;
                        if (root->right->left && root->right->left != _begin)
                            rightheight1 = root->right->left->height;
                        // RLR
                        if (rightheight1 > rightheight2) {
                            root->right = right_rotate(root->right);
                            return left_rotate(root);
                        }
                        // LLR
                        else
                            root = left_rotate(root);
                    }
                    else {
                        int leftheight1 = 0;
                        int leftheight2 = 0;
                        if (root->left->right && root->left->right != _end)
                            leftheight2 = root->left->right->height;
                        if (root->left->left && root->left->left != _begin)
                            leftheight1 = root->left->left->height;
                        // RRR
                        if (leftheight1 > leftheight2) {
                            root = right_rotate(root);
                        }
                        // LRR
                        else {
                            root->left = left_rotate(root->left);
                            return right_rotate(root);
                        }
                    }
                }
                return root;
            }

            map_node* delete_node_left_child(map_node* node) {
                if (node->parent) {
                    if (_comp(node->parent->value.first, node->value.first))
                        node->parent->right = node->left;
                    else
                        node->parent->left = node->left;
                    node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
                }
                map_node* tmp = node->left;
                node->left->parent = node->parent;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
                tmp = balance_erase(tmp);
                return tmp;
            }

            map_node* delete_node_right_child(map_node* node) {
                if (node->parent) {
                    if (_comp(node->parent->value.first, node->value.first))
                        node->parent->right = node->right;
                    else
                        node->parent->left = node->right;
                    node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
                }
                map_node* tmp = node->right;
                tmp->parent = node->parent;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
                tmp = balance_erase(tmp);

                return tmp;
            }

            map_node* delete_leaf_node(map_node* node) {
                if (node->parent) {
                    if (_comp(node->parent->value.first, node->value.first))
                        node->parent->right = NULL;
                    else
                        node->parent->left = NULL;
                    node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
                }
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
                return NULL;
            }

            map_node* delete_node_two_children(map_node* node, bool& found) {
                map_node* tmp = node;
                tmp = tmp->right;
                while (tmp && tmp->left)
                    tmp = tmp->left;
                value_type value = tmp->value;
                node->right = delete_node(node->right, tmp->value.first, found);

                map_node *toAdd = _alloc.allocate(1);
                _alloc.construct(toAdd, value);

                toAdd->parent = node->parent;
                toAdd->right = node->right;
                toAdd->left= node->left;
                toAdd->height = node->height;

                if (node->parent && node->parent->left == node)
                    node->parent->left = toAdd;
                if (node->parent && node->parent->right == node)
                    node->parent->right = toAdd;
                if (node->left && node->left != _begin && node->left->parent == node)
                    node->left->parent = toAdd;
                if (node->right && node->right != _end && node->right->parent == node)
                    node->right->parent = toAdd;

                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                toAdd = balance_erase(toAdd);
                return toAdd;
            }

            map_node* delete_node(map_node* node, const key_type& key, bool& found) {
                if (node && node != _begin && node != _end && size()) {
                    // found the node -> delete operations
                    if (!_comp(node->value.first, key) && !_comp(key, node->value.first)) {
                        found = true;
                        if ((!node->right || node->right == _end) && (node->left && node->left != _begin))
                            return delete_node_left_child(node);
                        else if ((!node->left || node->left == _begin) && (node->right && node->right != _end))
                            return delete_node_right_child(node);
                        else if ((!node->left || node->left == _begin) && (!node->right || node->right == _end))
                            return delete_leaf_node(node);
                        else
                            return delete_node_two_children(node, found);
                    }
                    // node value smaller than key value -> move right
                    else if (_comp(node->value.first, key)) {
                        node->right = delete_node(node->right, key, found);
                        node = balance_erase(node);
                    }
                    // node value bigger than key value -> move left
                    else if (_comp(key, node->value.first)) {
                        node->left = delete_node(node->left, key, found);
                        node = balance_erase(node);
                    }
                    // update node height
                    if (node)
                        node->height = max(height(node->left), height(node->right)) + 1;
                }
                else
                    found = false;
                return node;
            }
    };

    template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
            return false;
        typename map<Key,T>::const_iterator lhs_begin = lhs.begin();
	    typename map<Key,T>::const_iterator rhs_begin = rhs.begin();
        while (lhs_begin != lhs.end() && rhs_begin != rhs.end())
        {
            if (lhs_begin->first != rhs_begin->first || lhs_begin->second != rhs_begin->second)
			    return false;
            ++lhs_begin;
            ++rhs_begin;
        }
        return true;
	}

    template< class Key, class T, class Compare, class Alloc >
    bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
        return (!(lhs == rhs));
    }

    template< class Key, class T, class Compare, class Alloc >
    bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
        return (!(rhs < lhs));
    }

    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
        return (rhs < lhs);
    }

    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
        return (!(lhs < rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
}


#endif
