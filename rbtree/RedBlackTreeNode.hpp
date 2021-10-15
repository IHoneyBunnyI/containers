#ifndef RED_BLACK_TREE_NODE
#define RED_BLACK_TREE_NODE 

namespace ft
{

enum rb_tree_color { red = false, black = true };

template <class T>
class RedBlackTreeNode
{
	typedef RedBlackTreeNode* pointer;
	typedef const RedBlackTreeNode* const_pointer;

	public:
		T val;
		pointer parent;
		pointer left;
		pointer right;
		rb_tree_color color;

		static pointer minimum(pointer x);
		static const_pointer minimum(const_pointer x);
};


template <class T>
typename RedBlackTreeNode<T>::pointer RedBlackTreeNode<T>::minimum(pointer x)
{
	while (x->left)
		x = x->left;
	return (x);
}

template <class T>
typename RedBlackTreeNode<T>::const_pointer RedBlackTreeNode<T>::minimum(const_pointer x)
{
	while (x->left)
		x = x->left;
	return (x);
}

template <class T>
RedBlackTreeNode<T>* redBlackTree_increment(RedBlackTreeNode<T>* x);

template <class T>
const RedBlackTreeNode<T>* redBlackTree_increment(const RedBlackTreeNode<T>* x);

template <class T>
RedBlackTreeNode<T>* redBlackTree_decrement(RedBlackTreeNode<T>* x);

template <class T>
const RedBlackTreeNode<T>* redBlackTree_decrement(const RedBlackTreeNode<T>* x);

}

#endif
