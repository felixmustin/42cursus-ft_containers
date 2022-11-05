#ifndef AVLTREE_HPP
# define AVLTREE_HPP

#include <utility>

namespace ft
{
    template <class Pair>
    struct AVLNode 
    {
        AVLNode*        parent;
        AVLNode*        left;
        AVLNode*        right;
        Pair            value;
        int             height;

        AVLNode() : parent(NULL), left(NULL), right(NULL), value(), height(0) { };

        AVLNode (const Pair& val) : parent(NULL), left(NULL), right(NULL), value(val), height(0) { };
    
        ~AVLNode() { };

        AVLNode(const AVLNode& other) : parent(other.parent), left(other.left), right(other.right), value(other.value), height(other.height) { };

        AVLNode& operator=(const AVLNode& other) {
            if (this != &other) {
                parent = other.parent;
                left = other.left;
                right = other.right;
                value = other.value;
                height = other.height;
            }
            return *this;
        }

        AVLNode* findMin(AVLNode* node) const
        {
            if (!node)
                return NULL;
            while(node->left)
                node = node->left;
            return node;
        }

        AVLNode* findMax(AVLNode* node) const
        {
            if (!node)
                return NULL;
            while(node->right)
                node = node->right;
            return node;
        }

        AVLNode* next() const
        {
            const AVLNode* tmp = this;
            if (tmp->right)
            {
                return findMin(tmp->right);
            }
            AVLNode* parent_tmp = this->parent;
            while(parent_tmp && tmp == parent_tmp->right) {
                tmp = parent_tmp;
                parent_tmp = parent_tmp->parent;
            }
            return parent_tmp;
        }

        AVLNode* prev() const
        {
            const AVLNode* tmp = this;
            if (tmp->left)
                return findMax(tmp->left);
            AVLNode* parent_tmp = tmp->parent;
            while (parent_tmp && tmp == parent_tmp->left) {
                tmp = parent_tmp;
                parent_tmp = parent_tmp->parent;
            }
            return parent_tmp;
        }
    };
}

#endif
