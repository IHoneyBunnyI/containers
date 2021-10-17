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
		static pointer maximum(pointer x);
		static const_pointer maximum(const_pointer x);
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
typename RedBlackTreeNode<T>::pointer RedBlackTreeNode<T>::maximum(pointer x)
{
	while (x->right)
		x = x->right;
	return (x);
}

template <class T>
typename RedBlackTreeNode<T>::const_pointer RedBlackTreeNode<T>::maximum(const_pointer x)
{
	while (x->right)
		x = x->right;
	return (x);
}

template <class T>
static RedBlackTreeNode<T>* redBlackTree_increment_l(RedBlackTreeNode<T>* x)
{
	if (x->right)
	{
		x = x->right;
		while (x->left)
			x = x->left;
	}
	else
	{
		RedBlackTreeNode<T>* p = x->parent;
		while (x == p->right)
		{
			x = p;
			p = p->parent;
		}
		if (x->right != p)
			x = p;
	}
	return x;
}

template <class T>
RedBlackTreeNode<T>* redBlackTree_increment(RedBlackTreeNode<T>* x)
{
	return redBlackTree_increment_l(x);
}

template <class T>
const RedBlackTreeNode<T>* redBlackTree_increment(const RedBlackTreeNode<T>* x)
{
	return redBlackTree_increment_l(const_cast<RedBlackTreeNode<T>*>(x));
}

template <class T>
RedBlackTreeNode<T>* redBlackTree_decrement_l(RedBlackTreeNode<T>* x)
{
	if (x->color == red && x->parent->parent == x)
		x = x->right;
	else if (x->left)
	{
		RedBlackTreeNode<T>* y = x->parent;
		while (y->right)
			y = y->right;
		x = y;
	}
	else
	{
		RedBlackTreeNode<T>* y = x->parent;
		while (x == y->left)
		{
			x = y;
			y = y->parent;
		}
		x = y;
	}
	return x;
}

template <class T>
RedBlackTreeNode<T>* redBlackTree_decrement(RedBlackTreeNode<T>* x)
{
	return redBlackTree_decrement_l(x);
}

template <class T>
const RedBlackTreeNode<T>* redBlackTree_decrement(const RedBlackTreeNode<T>* x)
{
	return redBlackTree_decrement_l(const_cast<RedBlackTreeNode<T>*>(x));
}

}

#endif
