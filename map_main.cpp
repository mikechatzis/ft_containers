/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/03 21:58:48 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <array>


// template<typename Key, typename T> struct nod{
// 	ft::pair<Key, T> pair;
// 	nod *left;
// 	nod *right;
// };

// template<class InputIt> void insert(nod<int,std::string> *&n, InputIt map_elem){
// 	if (!n)
// 	{
// 		n = new nod<int,std::string>;
// 		n->pair.first = map_elem->first;
// 		n->pair.second = map_elem->second;
// 		n->right = n->left = NULL;
// 		std::cout << "creation "<< n->pair.first << std::endl;
// 	}
// 	else if (map_elem->first > n->pair.first)
// 	{
// 		std::cout << "jump right" << std::endl;
// 		insert(n->right, map_elem);	
// 	}
// 	else if (map_elem->first < n->pair.first)
// 	{
// 		std::cout << "jump left" << std::endl;
// 		insert(n->left, map_elem);	
// 	}
// }

int main()
{

	// ft::tree<int,std::string> tr(1, "hello");
	ft::tree<int,std::string> tr2;
	
	tr2.testf();

	// std::cout << "testing function 'next': " << tr2.next(&tr2.get_root())->pair.second << tr2.next(&tr2.get_root())->pair.second << std::endl;
	// std::cout << tr2.search(&tr2.get_root(), 3)->pair.first << std::endl;
	// std::cout << tr.next(tr.search(temp, 3))->pair.second << std::endl;
	// std::cout << tr.prev(tr.search(3))->pair.second << std::endl;

	ft::map_iterator<ft::tree<int, std::string> > n_it(&tr2);
	ft::map_iterator<ft::tree<int, std::string> > n_it2(&tr2);

	ft::map_iterator<ft::tree<int, std::string> > n_it3(&tr2);
	ft::map_iterator<ft::tree<int, std::string> > n_it4(&tr2);
	std::cout << "testing 'last': " << "last value: " << tr2.last()->pair.second << std::endl;
	std::cout << "map_iterator increment/decrement testing: " << (n_it).second << (++n_it).second;
	n_it++; n_it++;
	std::cout << ((--n_it)).second << (--n_it).second  <<  std::endl;
	--n_it;

	if (n_it2 == n_it)
		std::cout << "operator '==' test succesful\n";
	if (!(n_it2 != n_it))
		std::cout << "operator '!=' test succesful\n";
	if (n_it2 < ++n_it)
		std::cout << "operator '<' test succesful\n";
	if (++n_it2 > --n_it)
		std::cout << "operator '>' test succesful\n";
	if (n_it2 >= n_it && n_it3 >= n_it4)
		std::cout << "operator '>=' test succesful\n";


	// node<int, std::string> *s = tr2.search(&tr2.get_root(), 2);
	// std::cout << "node search ptr value: " << s << std::endl;

	// ft::pair<std::string, int> p("hello", 42); p.print();
	// ft::pair<std::string, int> pr("world", 42);
	// ft::pair<std::string, float> p2(p); p2.print();
	// ft::pair<std::string, int> p3 = p; p3.print();
	// if (p == p3)
	// 	std::cout << "'==' comparison success\n";
	// if (!(p != p3))
	// 	std::cout << "'!=' comparison success\n";
	// if (p < pr)
	// 	std::cout << "'<' comparison success\n";
	// if (!(p > pr))
	// 	std::cout << "'>' comparison success\n";
	// if (p <= pr && p <= p3)
	// 	std::cout << "'<=' comparison success\n";
	// if (!(p >= pr && p >= p3))
	// 	std::cout << "'>=' comparison success\n";
	// p3 = ft::make_pair("three", 3); p3.print();
	
	// nod<int, std::string> *l = new nod<int,std::string>;
	// l->pair.first = 1;
	// l->pair.second = "one";

	// insert(l, it);

	// std::cout << l->right->pair.second << std::endl;
}