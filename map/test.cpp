#include "tree.hpp"

int main()
{
	{
		// Tree<tree_traits> t;

		// t.insert(ft::make_pair(5, 'a'));
		// t.insert(ft::make_pair(1, 'a'));
		// t.insert(ft::make_pair(2, 'a'));
		// t.insert(ft::make_pair(3, 'a'));

		// t.erase(5);
		// t.erase(3);
		// t.erase(2);
		// t.erase(1);

		// t.insert(ft::make_pair(5, 'a'));
		// t.insert(ft::make_pair(1, 'a'));
		// t.insert(ft::make_pair(2, 'a'));
		// t.insert(ft::make_pair(3, 'a'));

		// // t.printNodes(t.root);
		// // std::cout << '\n';

		// Tree<tree_traits>::iterator it = t.begin();
		// while(it != t.end())
		// {
		// 	std::cout << (*it).first << ' ' << (*it).second << '\n';
		// 	++it;
		// }
	}

	{
		// Tree<tree_traits> t;

		// std::cout << std::boolalpha << (t.begin() == t.end()) << '\n'; 

		// t.insert(5);
		// t.insert(1);
		// t.insert(2);
		// t.insert(3);

		// std::cout << t.erase(8) << '\n';
		// std::cout << t.erase(3) << '\n';
		// std::cout << t.erase(1) << '\n';
		// std::cout << t.erase(5) << '\n';
		// std::cout << t.erase(2) << '\n';
		// std::cout << t.erase(2) << '\n';

		// // t.erase(t.begin());
		// // t.erase(t.begin());
		// // t.erase(t.begin());
		// // t.erase(t.begin());

		// // t.erase(t.begin(), t.end());

		// while(t.size())
		// {
		// 	t.erase(t.begin());
		// 	std::cout << "size " << t.size() << '\n';
		// }

		// std::cout << std::boolalpha << (t.begin() == t.end()) << '\n'; 

		// t.insert(5);
		// t.insert(1);
		// t.insert(2);
		// t.insert(3);
	
		// // t.printNodes(t.root);
		// // std::cout << '\n';
		// // std::cout << "min " << t.nil->right->value << " max " << t.nil->p->value << '\n';

		// Tree<tree_traits>::iterator it = t.begin();
		// while(it != t.end())
		// {
		// 	std::cout << *it << ' ';
		// 	++it;
		// }
		// std::cout << '\n';
	}

	{
		// Tree<tree_traits> t;

		// t.insert(t.end(), 3);
		// t.insert(3);
		// std::cout << "inserting " << 3
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(1);
		// std::cout << "inserting " << 1
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(2);
		// std::cout << "inserting " << 2
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// ft::pair<Tree<tree_traits>::iterator, bool> p = t.insert(4);
		// std::cout << "inserting " << 4
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(p.first, 5);
		// std::cout << "inserting " << 5
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(15);
		// std::cout << "inserting " << 15
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(-7);
		// std::cout << "inserting " << -7
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(10);
		// std::cout << "inserting " << 10
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.insert(300);
		// std::cout << "inserting " << 300
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';

		// std::cout << "\nsize " << t.size() << '\n';

		// t.removeValue(-7);
		// std::cout << "removing " << -7
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.removeValue(4);
		// std::cout << "removing " << 4
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';
		// t.removeValue(300);
		// std::cout << "removing " << 300
		// << " min " << t.nil->right->value << " max " << t.nil->p->value << '\n';

		// std::cout << "\nsize " << t.size() << '\n';

		// // t.addValue(3);
		// // t.addValue(1);
		// // t.addValue(2);
		// // t.addValue(4);
		// // t.addValue(5);
		// t.printNodes(t.root);
		// std::cout << '\n';


		// // Tree<tree_traits>::reverse_iterator it = t.rbegin();//doesn't work
		// Tree<tree_traits>::iterator it = t.begin();

		// while(it != t.end())
		// {
		// 	std::cout << *it << ' ';
		// 	++it;
		// }
		// std::cout << '\n';
	}

	{
		// Tree<tree_traits> t;
		// Tree<tree_traits> t2;

		// t2.insert(0);
		// t2.insert(5);
		// t2.insert(6);

		// // t2.printNodes(t2.root);
		// // std::cout << '\n';

		// t.insert(t.end(), 3);
		// t.insert(3);
		// t.insert(1);
		// t.insert(2);
		// ft::pair<Tree<tree_traits>::iterator, bool> p = t.insert(4);
		// t.insert(p.first, 5);

		// t.insert(t2.begin(), t2.end());

		// t.removeValue(0);

		// std::cout << "\nsize " << t.size() << "\n\n";

		// t.printNodes(t.root);
		// std::cout << '\n';
		// // Tree<tree_traits>::iterator it = t.begin();
		// // while(it != t.end())
		// // {
		// // 	std::cout << *it << '\n';
		// // 	++it;
		// // }
	}

	{
		// Tree<tree_traits> t1;
		// Tree<tree_traits> t2;

		// for (int i = 1; i < 6; i++)
		// {
		// 	if(i % 2)
		// 		t1.insert(i);
		// 	else
		// 		t2.insert(i);
		// }

		// std::cout << "t1 size " << t1.size() << " first " << *(t1.begin()) << '\n';
		// std::cout << "t2 size " << t2.size() << " first " << *(t2.begin()) << '\n';

		// t1.swap(t2);
		// std::cout << '\n';

		// std::cout << "t1 size " << t1.size() << " first " << *(t1.begin()) << '\n';
		// std::cout << "t2 size " << t2.size() << " first " << *(t2.begin()) << '\n';
	}

	{
		// Tree<tree_traits> t1;
		// Tree<tree_traits> t2;

		// for (int i = 1; i < 6; i++)
		// {
		// 	if(i % 2)
		// 		t1.insert(i);
		// 	else
		// 		t2.insert(i);
		// }

		// Tree<tree_traits>::iterator it1 = t1.begin();
		// Tree<tree_traits>::iterator it2 = t2.begin();

		// std::cout << "first " << *it1 << " size " << t1.size() << '\n';
		// std::cout << "second " << *it2 << " size " << t2.size() << '\n';

		// for(Tree<tree_traits>::iterator i = it1; i != t1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// for(Tree<tree_traits>::iterator i = it2; i != t2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';

		// t1.swap(t2);

		// t2.insert(6);
		// t1.insert(7);

		// std::cout << "first " << *it1 << " size " << t2.size() << '\n';
		// std::cout << "second " << *it2 << " size " << t1.size() << '\n';

		// // std::cout << '\n' << it1.base() << '\n' << t2.begin().base() << '\n';

		// for(Tree<tree_traits>::iterator i = it1; i != t2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// for(Tree<tree_traits>::iterator i = it2; i != t1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
	}

	{
		// Tree<tree_traits> t;

		// t.insert(3);
		// t.insert(1);
		// t.insert(2);
		// t.insert(4);
		// t.insert(5);
		// t.insert(15);
		// t.insert(-7);
		// t.insert(10);
		// t.insert(300);
	
		// std::cout << "lbound 4: " << *(t.lower_bound(4)) << '\n';
		// std::cout << "rbound 4: " << *(t.upper_bound(4)) << '\n';

		// std::cout << "lbound 7: " << *(t.lower_bound(7)) << '\n';
		// std::cout << "rbound 7: " << *(t.upper_bound(7)) << '\n';

		// std::cout << "lbound -7: " << *(t.lower_bound(-7)) << '\n';
		// std::cout << "rbound -7: " << *(t.upper_bound(-7)) << '\n';

		// std::cout << "lbound 300: " << *(t.lower_bound(300)) << '\n';
		// std::cout << "rbound 300: " << *(t.upper_bound(300)) << '\n';

		// std::cout << std::boolalpha << (t.upper_bound(300) == t.end()) << '\n';
	}

	{
		// Tree<tree_traits> t;

		// t.insert(3);
		// t.insert(1);
		// t.insert(2);
		// t.insert(4);
		// t.insert(5);
		// t.insert(15);
		// t.insert(-7);
		// t.insert(10);
		// t.insert(300);

		// Tree<tree_traits>::const_iterator it = t.begin();
		// while(it != t.end())
		// {
		// 	// (*it) += 1;
		// 	std::cout << *it << '\n';
		// 	++it;
		// }

		// std::cout << '\n';

		// Tree<tree_traits>::const_reverse_iterator rit = t.rbegin();
		// while(rit != t.rend())
		// {
		// 	// (*rit) += 1;
		// 	std::cout << *rit << '\n';
		// 	++rit;
		// }
	}

	{
		Tree<tree_traits> t;

		t.insert(ft::make_pair(3, 'a'));
		t.insert(ft::make_pair(1, 'a'));
		t.insert(ft::make_pair(2, 'a'));
		t.insert(ft::make_pair(4, 'a'));
		t.insert(ft::make_pair(5, 'a'));
		t.insert(ft::make_pair(15, 'a'));
		t.insert(ft::make_pair(-7, 'a'));
		t.insert(ft::make_pair(10, 'a'));
		t.insert(ft::make_pair(300, 'a'));

		Tree<tree_traits>::const_iterator it = t.begin();
		while(it != t.end())
		{
			// (*it).first += 1;
			// (*it).second += 1;
			std::cout << (*it).first << ' ' << (*it).second << '\n';
			++it;
		}

		std::cout << '\n';

		Tree<tree_traits>::const_reverse_iterator rit = t.rbegin();
		while(rit != t.rend())
		{
			// (*rit).first += 1;
			// (*rit).second += 1;
			std::cout << (*rit).first << ' ' << (*rit).second << '\n';
			++rit;
		}
	}
}
