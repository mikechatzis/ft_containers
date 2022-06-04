/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/04 15:45:59 by mchatzip         ###   ########.fr       */
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
				mp[2] = 2;
				mp[3] = 3;
				mp[4] = 4;
	
	ft::map<int, int> m(mp.begin(), mp.end());
	ft::map<int,int>::iterator it = m.begin();
	while(it != m.end())
		std::cout << it++->first << " ";
	std::cout << std::endl;

	ft::map<int, int> m2(m.begin(), m.end());
	ft::map<int,int>::iterator it2 = m2.begin();
	while(it2 != m2.end())
		std::cout << it2++->first << " ";
	std::cout << std::endl;
	
	
}