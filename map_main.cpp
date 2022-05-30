/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/30 20:11:08 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <array>
#include <map>

int main()
{
	ft::tree<int,std::string> tr(1, "hi");
	std::map<int, std::string> m;
	m[2] = "two";
	m[3] = "three";
	m[4] = "one";

	std::map<int, std::string>::iterator it = m.begin();
	tr.insert(++it);
	tr.insert(--it);
	std::cout << tr.next(tr.search(1))->pair.second << std::endl;
	std::cout << tr.prev(tr.search(2))->pair.second << std::endl;

	ft::map_iterator<ft::tree<int, std::string> > n_it(&tr);
	std::cout << "map_iterator testing " << n_it++.current_node->pair.second << " | " << n_it++.current_node->pair.second << n_it++.current_node->pair.second << std::endl;

	node<int, std::string> *s = tr.search(2);
	std::cout << "node search ptr value: " << s << std::endl;

	ft::pair<std::string, int> p("hello", 42); p.print();
	ft::pair<std::string, int> pr("world", 42);
	ft::pair<std::string, float> p2(p); p2.print();
	ft::pair<std::string, int> p3 = p; p3.print();
	if (p == p3)
		std::cout << "'==' comparison success\n";
	if (!(p != p3))
		std::cout << "'!=' comparison success\n";
	if (p < pr)
		std::cout << "'<' comparison success\n";
	if (!(p > pr))
		std::cout << "'>' comparison success\n";
	if (p <= pr && p <= p3)
		std::cout << "'<=' comparison success\n";
	if (!(p >= pr && p >= p3))
		std::cout << "'>=' comparison success\n";
	p3 = ft::make_pair("three", 3); p3.print();
	
}