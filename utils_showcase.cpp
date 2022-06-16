/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_showcase.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/16 16:11:59 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "map_iterators.hpp"
#include "utils.hpp"

#include <iostream>
#include <map>
#include<vector>
#include <array>
 
int main()
{
	typedef ft::iterator_traits<int*> traits_int;
	
	if (typeid(traits_int::iterator_category)==typeid(std::random_access_iterator_tag))
	std::cout << "using iterator_traits to assign traits to int*(pointer to int): " << "int* is a random-access iterator\n\n";
	
	ft::iterator_traits<std::vector<int>::iterator>::value_type i = 42;
	std::cout << "retrieving value type 'int', as the value_type of a vector<int> iterator, through iterator_traits: " << i << std::endl << std::endl;


	std::array<int, 12> nums1 = {1,2,3,4,5,6,7,8,9,10,11,12};
	std::array<int, 12> nums2 = {1,2,3,4,5,6,7,8,9,10,11,12};
	std::array<int,12>::iterator it = nums1.end(); it -=10;
	std::cout << "Using lexicographical compare on equal ranges: " << ft::lexicographical_compare(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
	std::cout << "\n\n";
	std::cout << "Using lexicographical compare on non-equal ranges with range1<range2: " << ft::lexicographical_compare(nums1.begin(), it, nums2.begin(), nums2.end());
	std::cout << "\n\n";
	it = nums2.begin(); it+=3;
	std::cout << "Using lexicographical compare on non-equal ranges with range1>range2: " << ft::lexicographical_compare(nums1.begin(), nums1.end(), nums2.begin(), it);
	std::cout << "\n\n";
	std::cout << "Using lexicographical compare on non-equal ranges with range1=prefix->range2: " << ft::lexicographical_compare(nums2.begin(), it, nums2.begin(), nums2.end());
	std::cout << "\n\n";

	ft::map<std::string, int> mp;
	mp["one"] = 1;
	mp["two"] = 2;
	mp["three"] = 3;
	ft::map<std::string, int> m(mp.begin(), mp.end());
	ft::map<std::string, int>::iterator itm;
	itm = m.begin();
	while(itm != m.end())
		std::cout << "(" << itm->first << ", " << itm++->second << ")" << " ";
		std::cout << std::endl << std::endl;
	std::cout << "Using lexicographical compare on equal ranges on maps: " << ft::lexicographical_compare(mp.begin(), mp.end(), m.begin(), m.end());
	std::cout << "\n\n";
	itm--;
	std::cout << "Using lexicographical compare on non equal ranges on maps range1>range2: " << ft::lexicographical_compare(mp.begin(), mp.end(), m.begin(), itm);
	std::cout << "\n\n";
	itm = mp.end();
	itm--;
	std::cout << "Using lexicographical compare on non equal ranges on maps range1<range2: " << ft::lexicographical_compare(mp.begin(), itm, m.begin(), m.end());
	std::cout << "\n\n";
	std::cout << "Using lexicographical compare on non equal ranges on maps range2=prefix->range1: " << ft::lexicographical_compare(mp.begin(), mp.end(), mp.begin(), itm);
	std::cout << "\n\n";
	std::cout << "Using lexicographical compare on non equal ranges on maps range1=prefix->range2: " << ft::lexicographical_compare(mp.begin(), itm, mp.begin(), mp.end());
	std::cout << "\n\n";
	m.clear();
	std::cout << "Using lexicographical compare on 1 empty container: " << ft::lexicographical_compare(mp.begin(), mp.end(), m.begin(), m.end());
	std::cout << "\n\n";
	std::cout << "Using lexicographical compare on 1 empty container, reverse order: " << ft::lexicographical_compare(m.begin(), m.end(), mp.begin(), mp.end());
	std::cout << "\n\n";
	mp.clear();
	std::cout << "Using lexicographical compare on 2 empty containers: " << ft::lexicographical_compare(m.begin(), m.end(), mp.begin(), mp.end());
	std::cout << "\n\n";

	return 0;
}
