#pragma once

#include <functional>
#include <memory>
#include "../reverse_iterator.hpp"
#include "../pair.hpp"
#include "../swaps.hpp"
#include "../template_meta.hpp"

#define RED true
#define BLACK false

// struct tree_traits
// {
// 	typedef int key_type;
// 	typedef int value_type;
// 	// typedef ft::pair<const int, char> value_type;
// 	typedef std::allocator<int> allocator_type;
// 	typedef std::less<key_type> key_compare;
// 	typedef std::less<value_type> value_compare;

// 	struct Kfn{
// 		const key_type& operator() (const value_type& v) const
// 		{ return v; }
// 		// { return v.first; }
// 	};

// 	key_compare comp;
// 	value_compare v_comp;
// 	tree_traits (key_compare const & comp) : comp(comp) {}
// };

template <typename Tr>
class Tree_node : public Tr
{
protected:
	typedef typename Tr::allocator_type allocator_type;
	typedef typename Tr::key_compare key_compare;
	typedef typename Tr::value_type value_type;
	typedef typename allocator_type::template
		rebind<void>::other::pointer Genptr;
	friend struct Node;
	struct Node{
		Node *left, *right, *p, *nil;
		value_type value;
		bool color;
	};
	typedef typename allocator_type::template
		rebind<Node>::other Alnode;

	Alnode alnode;

	Tree_node (key_compare const & comp, allocator_type const & al) :
		Tr(comp), alnode(al) {};
};

template <typename Tr>
class Tree_ptr : public Tree_node<Tr>
{
protected:
	typedef typename Tree_node<Tr>::Node Node;
	typedef typename Tr::allocator_type allocator_type;
	typedef typename Tr::key_compare key_compare;
	typedef typename allocator_type::template
		rebind<Node>::other::pointer Nodeptr;
	typedef typename allocator_type::template
		rebind<Node>::other Alptr;

	Alptr alptr;

	Tree_ptr (key_compare const & comp, allocator_type const & al) :
		Tree_node<Tr>(comp, al), alptr(al) {};
};

template <typename Tr>
class Tree_val : public Tree_ptr<Tr>
{
protected:
	typedef typename Tr::allocator_type allocator_type;
	typedef typename Tr::key_compare key_compare;

	allocator_type alval;

	Tree_val (key_compare const & comp, allocator_type const & al) :
		Tree_ptr<Tr>(comp, al), alval(al) {};
};

template <typename Tr>
class Tree : public Tree_val<Tr>
{
public:
	typedef Tree<Tr> Type;
	typedef Tree_val<Tr> Base;
	typedef typename Tr::key_type key_type;
	typedef typename Tr::key_compare key_compare;
	typedef typename Tr::value_type value_type;
	typedef typename Tr::value_compare value_compare;
	typedef typename Tr::allocator_type allocator_type;

protected:
	typedef typename Tree_node<Tr>::Genptr Genptr;
	typedef typename Tree_node<Tr>::Node Node;
	typedef typename Tr::Kfn Kfn;
	typedef typename allocator_type::template
		rebind<Node>::other::pointer Nodeptr;
	typedef typename allocator_type::template
		rebind<Nodeptr>::other::reference Nodepref;
	typedef typename allocator_type::template
		rebind<key_type>::other::const_reference Keyref;
	typedef typename allocator_type::template
		rebind<value_type>::other::reference Valref;
	typedef typename allocator_type::template
		rebind<bool>::other::reference Boolref;

	static Boolref color(Nodeptr P) { return ((Boolref) (*P).color); }
	static Valref value(Nodeptr P) { return ((Valref) (*P).value); }
	static Keyref key(Nodeptr P) { return (Kfn()(value(P))); }
	static Nodepref left(Nodeptr P) { return ((Nodepref) (*P).left); }
	static Nodepref right(Nodeptr P) { return ((Nodepref) (*P).right); }
	static Nodepref parent(Nodeptr P) { return ((Nodepref) (*P).p); }

public:
	typedef typename allocator_type::size_type size_type;
	typedef typename allocator_type::difference_type difference_type;
	typedef typename allocator_type::template
		rebind<value_type>::other::pointer pointer;
	typedef typename allocator_type::template
		rebind<value_type>::other::const_pointer const_pointer;
	typedef typename allocator_type::template
		rebind<value_type>::other::reference reference;
	typedef typename allocator_type::template
		rebind<value_type>::other::const_reference const_reference;

	template <bool Bool>
	class TreeIterator : public ft::iterator<ft::bidirectional_iterator_tag,
										value_type,
										difference_type,
										pointer,
										reference>
	{

	protected:
		friend class Tree;
		Nodeptr nptr;
		Nodeptr base() const { return nptr; }

	public:
		typedef typename ft::conditional<Type::value_type,
										const Type::value_type,
										Bool>::type v_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,
							Type::value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,
							Type::value_type>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,
							v_type>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,
								value_type>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag,
								value_type>::reference reference;

		explicit TreeIterator(Nodeptr ptr = 0) : nptr(ptr) {};

		TreeIterator& operator=(TreeIterator const &src) {
			nptr = src.nptr;
			return *this;
		}

		bool operator==(TreeIterator const &x) const { return (nptr == x.nptr); }
		bool operator!=(TreeIterator const &x) const { return (nptr != x.nptr); }

		TreeIterator& operator++() {
			nptr = successor(nptr);
			return *this;
		}
		
		TreeIterator operator++(int) {
			TreeIterator retval = *this;
			++(*this);
			return retval;
		}

		TreeIterator& operator--() {
			nptr = predecessor(nptr);
			return *this;
		}

		TreeIterator operator--(int) {
			TreeIterator retval = *this;
			--(*this);
			return retval;
		}


		operator TreeIterator<false> () const
		{ return (TreeIterator<false>(this->nptr)); }

		reference operator*() const { return value(nptr); }
		pointer operator->() const { return &(**this); }
	};

	typedef TreeIterator<true> iterator;
	typedef TreeIterator<false> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef ft::pair<iterator, bool> Pairib;
	typedef ft::pair<iterator, iterator> Pairii;
	typedef ft::pair<const_iterator, const_iterator> Paircc;
	typedef ft::pair<Nodeptr, bool> Pairnb;


	// Tree() : Base(key_compare(), allocator_type())
	// { init (); }

	explicit Tree (key_compare const &comp, allocator_type const &al) :
	Base(comp, al) { init(); }

	Tree(value_type const *f, value_type const *l,
		key_compare const &comp, allocator_type const &al) :
	Base(comp, al)
	{
		init();
		insert(f, l);
	}
	
	Tree(Type const &src) : Base(src.key_comp(), src.get_allocator())
	{
		init();
		copy(src);
	}

	~Tree() {
		clearNodes(root);
		this->alnode.deallocate(nil, 1);
	}

	Type &operator=(Type const &src) {
		if(this == &src)
			return *this;
		erase(begin(), end());
		copy(src);
		return *this;
	}

	
	// Type &operator= (Type const &other)
	// {
	// 	if(this == &other)
	// 		return *this;
	// 	clear();
	// 	copy(other);
	// }

	iterator begin() { return iterator(nil->right); }
	const_iterator begin() const { return const_terator(nil->right); }
	iterator end() { return iterator(nil); }
	const_iterator end() const { return const_terator(nil); }
	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	size_type size() const { return sz; }
	size_type max_size() const { return this->alval.max_size(); }
	bool empty() const { return (sz == 0); }
	allocator_type get_allocator() const { return this->alval; }
	key_compare key_comp() const { return this->comp; }
	value_compare value_comp() const { return this->v_comp; }

	Pairib insert(value_type const &val)
	{
		if(root == nil)
			return (ft::make_pair(iterator(addValue(val)), true));
		Pairnb p = findValue(Kfn()(val));
		if(p.second == true)
			return (ft::make_pair(iterator(p.first), false));
		Pairib ret = ft::make_pair(iterator(addNode(p.first, val)), true);
		return ret;
	}

	iterator insert(iterator hint, value_type const &val)
	{
		if (sz == 0)
			return (iterator(addValue(val)));
		Nodeptr p = hint.base();
		if(p == nil->right)
		{
			if(this->comp(Kfn()(val), key(p)))
				return (iterator(addNode(p, val)));
		}
		else if(p == nil || p == nil->p)
		{
			if(this->comp(key(nil->p), Kfn()(val)))
				return (iterator(addNode(nil->p, val)));
		}
		else
		{
			if(this->comp(Kfn()(p->value), Kfn()(val))
				&& this->comp(Kfn()(val), Kfn()(*(++hint)))
				&& (p = addNode(p, val)) != nil)
				return iterator(p);
		}
		return (insert(val).first);
	}

	template <typename Iter>
	void insert(Iter first, Iter last)
	{
		for(; first != last; ++first)
			insert(end(), *first);
	}

	void erase(iterator pos)
	{
		removeNode(pos.base());
	}
	
	void erase(iterator first, iterator last)
	{
		while(first != last)
			removeNode((first++).base());
	}

	size_type erase(key_type const &k)
	{
		Pairnb p = findValue(k);
		if(!p.second)
			return 0;
		removeNode(p.first);
		return 1;
	}

	void clear()
	{
		erase(begin(), end());
	}

	void swap (Type &x)
	{
		ft::swap(root, x.root);
		ft::swap(this->comp, x.comp);
		ft::swap(sz, x.sz);
		ft::swap(nil, x.nil);
	}

	iterator lower_bound(key_type const & key)
	{
		Pairnb p = findValue(key);
		if(p.second || !this->comp(Kfn()(p.first->value), key))
			return (iterator(p.first));
		return (iterator(successor(p.first)));
	}

	iterator upper_bound(key_type const & key)
	{
		Pairnb p = findValue(key);
		if(p.second || !this->comp(key, Kfn()(p.first->value)))
			return (iterator(successor(p.first)));
		return (iterator(p.first));
	}

	Pairii equal_range(key_type const & key)
	{
		return (ft::make_pair(lower_bound(key), upper_bound(key)));
	}

	iterator find(key_type const &k)
	{
		Pairnb p = findValue(k);
		if(p.second)
			return iterator(p.first);
		return end();
	}

	size_type count(key_type const &k)
	{
		Pairnb p = findValue(k);
		if(p.second)
			return 1;
		return 0;
	}

protected:
	Nodeptr root;
	size_type sz;
	Nodeptr nil;

	void copy(Type const & src)
	{
		root = copy(src.root);
		sz = src.sz;
		if(root != nil)
		{
			nil->p = treeMaximum(root);
			nil->right = treeMinimum(root);
		}
	}

	Nodeptr copy(Nodeptr head)
	{
		if(head == head->nil)
			return nil;
		Nodeptr ret = newNode(head->value);
		ret->color = head->color;
		ret->left = ret->right = nil;
		try
		{
			ret->left = copy(head->left);
			ret->right = copy(head->right);
		}
		catch(...)
		{
			if(ret->left != nil)
				deleteBranch(ret->left);
			deleteNode(ret);
			throw;
		}
		ret->left->p = ret;
		ret->right->p = ret;
		return ret;
	}

	void deleteBranch(Nodeptr head)
	{
		if(head == nil)
			return;
		Nodeptr l = head->left;
		Nodeptr r = head->right;
		deleteNode(head);
		deleteBranch(l);
		deleteBranch(r);
		return;
	}

	void init()
	{
		sz = 0;
		nil = this->alnode.allocate(1);
		nil->color = BLACK;
		nil->p = nil->right = nil->nil = nil;
		root = nil;
	}

	Nodeptr newNode(value_type const & val) {
		Nodeptr n = this->alnode.allocate(1);
		try { this->alval.construct(&(n->value), val); }
		catch (...) { deleteNode(n); throw; }
		n->color = RED;
		n->left = n->right = n->p = n->nil = nil;
		return n;
	}

	void deleteNode(Nodeptr n) {
		this->alnode.deallocate(n, 1);
		n = nil;
	}

	static Nodeptr successor(Nodeptr x)
	{
		Nodeptr tnil = x->nil;
		if(x == tnil->p)
			return tnil;
		if(x->right != tnil)
			return treeMinimum(x->right);
		Nodeptr y = x;
		while(y != tnil && x != y->left)
		{
			x = y;
			y = y->p;
		}
		return y;
	}

	static Nodeptr predecessor(Nodeptr x)
	{
		Nodeptr tnil = x->nil;
		if(x == tnil)
			return x->p;
		if(x == tnil->right)
			return tnil;
		if(x->left != tnil)
			return treeMaximum(x->left);
		Node *y = x;
		while(y != tnil && x != y->right)
		{
			x = y;
			y = y->p;
		}
		return y;
	}

	static Nodeptr treeMinimum (Nodeptr n)
	{
		Nodeptr tnil = n->nil;
		if(n == tnil || n->left == tnil)
			return n;
	
		return treeMinimum(n->left);
	}

	static Nodeptr treeMaximum (Nodeptr n)
	{
		Nodeptr tnil = n->nil;
		if(n == tnil || n->right == tnil)
			return n;
	
		return treeMaximum(n->right);
	}

	Pairnb findValue(key_type const &k)
	{
		if(root == nil)
			return ft::make_pair(root, false);

		Nodeptr n = root;
		Pairnb r;
		r.second = false;
		while (n != nil)
		{
			r.first = n;
			if(this->comp(k, Kfn()(n->value)))
				n = n->left;
			else if(this->comp(Kfn()(n->value), k))
				n = n->right;
			else
			{
				r.second = true;
				break;
			}
		}
		return r;
	}

	Nodeptr addValue(value_type const &val)
	{
		root = newNode(val);
		root->color = BLACK;
		nil->p = root;
		nil->right = root;
		++sz;
		root->p = nil;
		return root;
	}

	Nodeptr addNode(Nodeptr n, value_type const &val)
	{
		Nodeptr ret;
		if(this->comp(Kfn()(val), Kfn()(n->value))
			&& n->left == nil)
		{
			n->left = newNode(val);
			n->left->p = n;
			if(n == nil->right)
				nil->right = n->left;
			ret = n->left;
		}
		else if(n->right == nil)
		{
			n->right = newNode(val);
			n->right->p = n;
			if(n == nil->p)
				nil->p = n->right;
			ret = n->right;
		}
		else
			return nil;
		root->p = nil;
		++sz;
		return insertFixup(ret);
	}

	Nodeptr insertFixup(Nodeptr x)
	{
		Nodeptr ret = x, y;
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
		return ret;
	}

	void rotateLeft(Nodeptr x)
	{
		Nodeptr y = x->right;
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
	}

	void rotateRight(Nodeptr x)
	{
		Nodeptr y = x->left;
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
	}

	void transplant(Nodeptr prev_n, Nodeptr new_n)
	{
		if(prev_n->p == nil)
			root = new_n;
		else if(prev_n == prev_n->p->left)
			prev_n->p->left = new_n;
		else
			prev_n->p->right = new_n;
		new_n->p = prev_n->p;
	}

	void removeValue(key_type const &val)
	{
		Pairnb p = findValue(val);
		if(p.second == false)
			return;
		Nodeptr n = p.first;
		removeNode(n);
	}

	void removeNode(Nodeptr n)
	{
		Nodeptr repl;
		Pairnb p;
		p.first = 0;
		nil->left = nil->p;
		if(n == nil->right)
		{
			p.first = successor(n);
			p.second = true;
		}
		else if(n == nil->p)
		{
			p.first = predecessor(n);
			p.second = false;
		}
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
			Nodeptr subs = treeMinimum(n->right);
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

		this->alval.destroy(&(n->value));
		deleteNode(n);
		if(orig_color == BLACK)
			deleteFixup(repl);

		if(p.first && p.second)
			nil->right = p.first;
		if(p.first && !p.second)
			nil->p = p.first;
		else
			nil->p = nil->left;
		root->p = nil;
		--sz;
	}

	void deleteFixup(Nodeptr n)
	{
		Nodeptr s;
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

	void clearNodes(Nodeptr n)
	{
		if(n == nil)
		return;
		if(n->left != nil)
			clearNodes(n->left);
		if(n->right != nil)
			clearNodes(n->right);
		this->alval.destroy(&(n->value));
		this->alnode.deallocate(n, 1);
	}

	void printNodes(Nodeptr n)
	{
		if(n == nil)
			return;
		if(n->left != nil)
			printNodes(n->left);
		std::cout << (n->color == BLACK ? "b:" : "r:") << n->value << ' ';
		// std::cout << (n->color == BLACK ? "b: " : "r: ")
		// << n->value.first << ' ' << n->value.second << '\n';
		if(n->right != nil)
			printNodes(n->right);
	}
};

// #include "TreeIterator.hpp"