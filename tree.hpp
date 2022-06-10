#pragma once

#include <iostream>
#include <cmath>
#include "utils.hpp"

namespace ft
{

#define RED true
#define BLACK false

template <typename T>
class treeIterator;

template <typename T,
			typename Comp = std::less<T>,
			typename Allocator = std::allocator<T> >
class Tree
{

public:

	struct Node{
		Tree *t_ptr;
		Node *p;
		Node *left;
		Node *right;
		T val;
		bool color;

		Node(Tree *tp, T val = T(), Node *ptr = 0): t_ptr(tp),
		p(ptr), left(ptr), right(ptr), val(val), color(RED) {}
	};

	typedef T key_type;
	typedef T value_type;
	typedef Comp key_compare;
	typedef Comp value_compare;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef Allocator allocator_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef treeIterator<T> iterator;
	typedef treeIterator<const T> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


protected:
	friend class ft::treeIterator<T>;
	typedef ft::pair<iterator, bool> pairib;
	typedef ft::pair<const_iterator, bool> paircb;

	Node * const nil;
	Node *root;
	int height;
	key_compare comp_obj;
	allocator_type alloc;

	Node *addNode(Node *head, T val, int depth);
	void insertFixup(Node *n);
	void deleteFixup(Node *n);
	void printNodes(Node *head);
	void printLevel(Node *head, int level, int depth);
	Node *treeMinimum(Node *head);
	Node *treeMaximum(Node *head);
	void transplant(Node *prev_n, Node * new_n);
	void updateHeight();
	void clearNodes(Node *head);

	template <typename U>
	bool isLess(U const & lhs, U const &rhs)
	{ return comp_obj(lhs, rhs); }

	template <typename U, typename V>
	bool isLess(ft::pair<U, V> const & lhs, ft::pair<U, V> const &rhs)
	{ return comp_obj(lhs.first, rhs.first); }

public:
	Tree() : nil(new Node(this)), root(nil), height(0), comp_obj(){
		nil->color = BLACK;
	}

	~Tree(){
		clearNodes(root);
		delete nil;
	}

	int maxHeight(Node *head, int depth);
	void addValue(T val);
	void removeValue(T val);
	Node *findValue(T val);
	void printTree();
	void graphicPrint();
	Node *successor(Node *x);
	Node *predecessor(Node *x);
	void rotateLeft(Node *x);
	void rotateRight(Node *x);
	size_t numElems(Node *head);

	int getHeight(){ return height; }
	Node *getRoot(){ return root; }
	Node *getMin(){ return treeMinimum(root); }
	Node *getMax(){ return treeMaximum(root); }
	void checkPars(Node *head);


	size_t size() { return numElems(root); }
	size_t max_size() { return alloc.max_size(); }
	bool empty() { return (numElems(root) == 0); }
	void clear() { clearNodes(root); }
	// iterator find( const Key& key );
	// const_iterator find( const Key& key ) const;

	iterator begin() { return iterator(treeMinimum(root)); }
	iterator end() { return iterator(nil); }
	reverse_iterator rbegin() { return reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }
};

template <typename T, typename Comp, typename Alloc>
size_t Tree<T, Comp, Alloc>::numElems(Node *head)
{
	if(head == nil)
		return 0;
	return 1 + numElems(head->left) + numElems(head->right);
}



template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::insertFixup(Node *x)
{
	Node *y;
	while(x->p->color == RED)
	{
		if(x->p == x->p->p->left)
		{
			y = x->p->p->right;
			if(y->color == RED)
			{
				y->color = BLACK;
				x->p->color = BLACK;
				y->p->color = RED;
				x = x->p->p;
			}
			else
			{
				if(x == x->p->right)
					rotateLeft(x = x->p);
				x->p->color = BLACK;
				x->p->p->color = RED;
				rotateRight(x->p->p);
			}
		}
		else
		{
			y = x->p->p->left;
			if(y->color == RED)
			{
				y->color = BLACK;
				x->p->color = BLACK;
				y->p->color = RED;
				x = x->p->p;
			}
			else
			{
				if(x == x->p->left)
					rotateRight(x = x->p);
				x->p->color = BLACK;
				x->p->p->color = RED;
				rotateLeft(x->p->p);
			}
		}
	}
	root->color = BLACK;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::rotateLeft(Node *x)
{
	Node *y = x->right;
	x->right = y->left;
	if(y->left != nil)
		y->left->p = x;

	y->p = x->p;
	if(y->p == nil)
		root = y;
	else if(x == x->p->left)
		y->p->left = y;
	else
		y->p->right = y;
	x->p = y;
	y->left = x;
	updateHeight();
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::rotateRight(Node *x)
{
	Node *y = x->left;
	x->left = y->right;
	if(y->right != nil)
		y->right->p = x;

	y->p = x->p;
	if(y->p == nil)
		root = y;
	else if(x == x->p->left)
		y->p->left = y;
	else
		y->p->right = y;
	x->p = y;
	y->right = x;
	updateHeight();
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::updateHeight()
{
	int h = maxHeight(root, 0);
	if(h != height)
		height = h;
}

template <typename T, typename Comp, typename Alloc>
int Tree<T, Comp, Alloc>::maxHeight(Node *head, int depth)
{
	if(head == nil)
		return depth - 1;
	if(head->right == nil)
		return maxHeight(head->left, depth + 1);
	if(head->left == nil)
		return maxHeight(head->right, depth + 1);

	int left = maxHeight(head->left, depth + 1);
	int right = maxHeight(head->right, depth + 1);
	return (left > right) ? left : right;
}

template <typename T, typename Comp, typename Alloc>
typename Tree<T, Comp, Alloc>::Node *Tree<T, Comp, Alloc>::addNode(Node *n, T val, int depth)
{
	if(isLess(val, n->val))
	{
		if(n->left == nil)
		{
			height = (++depth > height) ? depth : height;
			n->left = new Node(this, val, nil);
			n->left->p = n;
			return n->left;
		}
		return addNode(n->left, val, depth + 1);
	}
	else
	{
		if(n->right == nil)
		{
			height = (++depth > height) ? depth : height;
			n->right = new Node(this, val, nil);
			n->right->p = n;
			return n->right;
		}
		return addNode(n->right, val, depth + 1);
	}
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::addValue(T val)
{
	if(root == nil)
	{
		root = new Node(this, val, nil);
		root->color = BLACK;
	}
	else
		insertFixup(addNode(root, val, 0));
	nil->p = treeMaximum(root);
	root->p = nil;
}

template <typename T, typename Comp, typename Alloc>
typename Tree<T, Comp, Alloc>::Node *Tree<T, Comp, Alloc>::findValue(T val)
{
	if(root == nil)
		return root;

	Node *n = root;
	while (n != nil)
	{
		if(isLess(val, n->val))
			n = n->left;
		else if(!isLess(n->val, val))
			break;
		else
			n = n->right;
	}
	return n;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::transplant(Node *prev_n, Node * new_n)
{
	if(prev_n->p == nil)
		root = new_n;
	else if(prev_n == prev_n->p->left)
		prev_n->p->left = new_n;
	else
		prev_n->p->right = new_n;
	new_n->p = prev_n->p;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::removeValue(T val)
{
	Node *n = findValue(val);
	if(n == nil)
		return;
	Node *repl;
	bool orig_color = n->color;

	if(n->right == nil)
	{
		repl = n->left;
		transplant(n, n->left);
	}
	else if(n->left == nil)
	{
		repl = n->right;
		transplant(n, n->right);
	}
	else
	{
		Node *subs = treeMinimum(n->right);
		orig_color = subs->color;
		repl = subs->right;
		if(subs->p == n)
			repl->p = subs;
		else
		{
			transplant(subs, subs->right);
			subs->right = n->right;
			subs->right->p = subs;
		}
		transplant(n, subs);
		subs->left = n->left;
		subs->left->p = subs;
		subs->color = n->color;
	}

	delete n;
	if(orig_color == BLACK)
		deleteFixup(repl);
	updateHeight();
	nil->p = treeMaximum(root);
	root->p = nil;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::deleteFixup(Node *n)
{
	Node *s;
	while(n != root && n->color == BLACK)
	{
		if(n == n->p->left)
		{
			s = n->p->right;
			if(s->color == RED)
			{
				s->color = BLACK;
				s->p->color = RED;
				rotateLeft(s->p);
				s = n->p->right;
			}
			if(s->left->color == BLACK && s->right->color == BLACK)
			{
				s->color = RED;
				n = n->p;
			}
			else
			{
				if(s->right->color == BLACK)
				{
					s->left->color = BLACK;
					s->color = RED;
					rotateRight(s);
					s = n->p->right;
				}
				s->color = n->p->color;
				n->p->color = BLACK;
				s->right->color = BLACK;
				rotateLeft(n->p);
				n = root;
			}
		}
		else
		{
			s = n->p->left;
			if(s->color == RED)
			{
				s->color = BLACK;
				s->p->color = RED;
				rotateRight(s->p);
				s = n->p->left;
			}
			if(s->left->color == BLACK && s->right->color == BLACK)
			{
				s->color = RED;
				n = n->p;
			}
			else
			{
				if(s->left->color == BLACK)
				{
					s->right->color = BLACK;
					s->color = RED;
					rotateLeft(s);
					s = n->p->left;
				}
				s->color = n->p->color;
				n->p->color = BLACK;
				s->left->color = BLACK;
				rotateRight(n->p);
				n = root;
			}
		}
	}
	n->color = BLACK;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::printNodes(Node *head)
{
	if(head->left != nil)
		printNodes(head->left);
	std::cout << head->val << ' ';
	if(head->right != nil)
		printNodes(head->right);
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::printTree()
{
	printNodes(root);
	std::cout << "\n";
}

template <typename T, typename Comp, typename Alloc>
typename Tree<T, Comp, Alloc>::Node *Tree<T, Comp, Alloc>::treeMinimum(Node *head)
{
	if(head ==nil || head->left == nil)
		return head;
	
	return treeMinimum(head->left);
}

template <typename T, typename Comp, typename Alloc>
typename Tree<T, Comp, Alloc>::Node *Tree<T, Comp, Alloc>::treeMaximum(Node *head)
{
	if(head == nil || head->right == nil)
		return head;
	
	return treeMaximum(head->right);
}

int width(int num)
{
	if(!num)
		return 1;
	int count = 0;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while(num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::printLevel(typename Tree<T, Comp, Alloc>::Node *head, int level, int depth)
{
	if(depth != level)
	{
		if(head->left != nil)
			printLevel(head->left, level, depth + 1);
		else
			printLevel(0, depth + 1, depth + 1);
		if(head->right != nil)
			printLevel(head->right, level, depth + 1);
		else
			printLevel(0, depth + 1, depth + 1);
		return;
	}
	int pad = pow(2, height - depth + 1) - 1;
	int num_width = pad + 1 - (head ? width(head->val) : 1);
	for (size_t i = 0; i < num_width; i++)
		std::cout << ' ';
	if(head)
		std::cout << head->val << (head->color ? 'r' : 'b');
	else
		std::cout << ' ' << ' ';
	for (size_t i = 0; i < pad; i++)
		std::cout << ' ';
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::graphicPrint()
{
	for (int i = 0; i <= height; i++)
	{
		printLevel(root, i, 0);
		std::cout << '\n' << '\n';
	}
}

template <typename T, typename Comp, typename Alloc>
typename Tree<T, Comp, Alloc>::Node *Tree<T, Comp, Alloc>::successor(Node *x)
{
	if(x->right != nil)
		return treeMinimum(x->right);
	Node *y = x;
	while(y != nil && x != y->left)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template <typename T, typename Comp, typename Alloc>
typename Tree<T, Comp, Alloc>::Node *Tree<T, Comp, Alloc>::predecessor(Node *x)
{
	if(x == nil)
		return x->p;
	if(x->left != nil)
		return treeMaximum(x->left);
	Node *y = x;
	while(y != nil && x != y->right)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::checkPars(Node *head)
{
	if(head == nil)
		return;
	std::cout << "path to root for " << head->val << ": ";
	head = head->p;
	while(head != nil)
	{
		std::cout << head->val << ' ';
		head = head->p;
	}
	std::cout << "\nroot reached\n";
}

template <typename T, typename Comp, typename Alloc>
void Tree<T, Comp, Alloc>::clearNodes(Node *head)
{
	if(head == nil)
		return;
	if(head->left != nil)
		clearNodes(head->left);
	if(head->right != nil)
		clearNodes(head->right);
	delete head;
}

}

#include "treeIterator.hpp"