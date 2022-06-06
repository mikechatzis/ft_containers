/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/06 15:34:37 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <array>

int main()
{

	// ft::tree<int,std::string> tr(1, "hello");
	// ft::tree<int,std::string> tr2;
	
	// tr2.testf();

	// ft::map_iterator<ft::tree<int, std::string> > n_it(&tr2);
	// ft::map_iterator<ft::tree<int, std::string> > n_it2(&tr2);

	// ft::map_iterator<ft::tree<int, std::string> > n_it3(&tr2);
	// ft::map_iterator<ft::tree<int, std::string> > n_it4(&tr2);
	// std::cout << "testing 'last': " << "last value: " << tr2.last()->pair.second << std::endl;
	// std::cout << "map_iterator increment/decrement testing: " << (n_it).second << (++n_it).second;
	// n_it++; n_it++;
	// std::cout << ((--n_it)).second << (--n_it).second  <<  std::endl;
	// --n_it;

	// if (n_it2 == n_it)
	// 	std::cout << "operator '==' test succesful\n";
	// if (!(n_it2 != n_it))
	// 	std::cout << "operator '!=' test succesful\n";
	// if (n_it2 < ++n_it)
	// 	std::cout << "operator '<' test succesful\n";
	// if (++n_it2 > --n_it)
	// 	std::cout << "operator '>' test succesful\n";
	// if (n_it2 >= n_it && n_it3 >= n_it4)
	// 	std::cout << "operator '>=' test succesful\n";

	std::map<int, int> mp;
				mp[1] = 1;
				mp[2] = 2;
				mp[3] = 3;
				mp[4] = 4;
				mp[5] = 5;
				mp[6] = 6;
	
	ft::map<int, int> m(mp.begin(), mp.end());
	ft::map<int,int>::iterator it = m.begin();

	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl;

	ft::map<int, int> m2(m.begin(), m.end());
	ft::map<int,int>::iterator it2 = m2.begin();
	while(it2 != m2.end())
		std::cout << it2++->first << " ";
	std::cout << std::endl;

	if (m2.empty())
		std::cout << "m2 is empty\n";
	else
		std::cout << "m2 is not empty\n";
	std::cout << "m2 size: " << m2.size() << std::endl << std::endl;

	m2.clear();
	std::cout << "after 'clear':\n\n";
	if (m2.empty())
		std::cout << "m2 is empty\n";
	else
		std::cout << "m2 is not empty\n";
	std::cout << "m2 size: " << m2.size() << std::endl << std::endl;
	std::cout << "m2 max size: " << m2.max_size() << std::endl;
	std::cout << "std::map max size: " << m.max_size() << std::endl << std::endl;

	it = m.begin();
	m.erase(++it);
	--it;
	std::cout<<"m, after erasing second element: ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl;

	it = m.begin(); it++; it++;
	m.erase(it, m.end());
	it = m.begin();
	std::cout<<"m, after erasing range: ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl;

	std::cout<< "Key specific erase return value: "<<m.erase(3)<<std::endl;
	it = m.begin();
	std::cout<<"m, after erasing key '3': ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl;
	std::cout<< "key specific erase return value: "<<m.erase(3)<<std::endl<<std::endl;

	ft::pair<int, int> p(7,7);
	ft::pair<ft::map<int,int>::iterator, bool> con = m.insert(p);
	it = m.begin();
	std::cout<<"m, after inserting pair: ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout<< "\ninsert success factor: "<< con.second << std::endl;
	con = m.insert(p);
	it = m.begin();
	std::cout<<"m, after inserting pair with already existing key: ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout<< "\ninsert success factor after attemted insertion of existing key: "<< con.second << std::endl << std::endl;

	it = m.begin();
	ft::map<int,int>::iterator ins = m.insert(++it, ft::pair<int,int>(-2,-2));
	std::cout << "inserting new value at improper hint position #1: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-2, -2), using hint: ";
	it = m.begin();
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
		std::cout << std::endl << std::endl;
	
	it = m.begin();
	ins = m.insert(it, ft::pair<int,int>(-1,-1));
	std::cout << "inserting new value at proper hint position: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-1, -1), using hint: ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	ins = m.insert(--it, ft::pair<int,int>(10,10));
	std::cout << "inserting new value at proper hint position: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-1, -1), using hint: ";
	it = m.begin();
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	ins = m.insert(--it, ft::pair<int,int>(0,0));
	std::cout << "inserting new value at improper hint position #2: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-1, -1), using hint: ";
	it = m.begin();
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	m.insert(mp.begin(), mp.end());
	std::cout<<"m, after inserting range from std::map: ";
	it = m.begin();
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	
	
	// ft::tree<int, std::string> tree; tree.testf();
	// tree._root = tree.delete_node(tree._root, 2);
	// std::cout << tree._root->pair.first << std::endl;
	
	
	
	
}