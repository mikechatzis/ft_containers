/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_showcase.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/11 12:41:31 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "map_iterators.hpp"
#include "utils.hpp"

#include <iostream>
#include <vector>
 
int main()
{
	typedef ft::iterator_traits<int*> traits_int;
	
	if (typeid(traits_int::iterator_category)==typeid(std::random_access_iterator_tag))
	std::cout << "using iterator_traits to assign traits to int*(pointer to int): " << "int* is a random-access iterator\n\n";
	
	ft::iterator_traits<std::vector<int>::iterator>::value_type i = 42;
	std::cout << "retrieving value type 'int', as the value_type of a vector<int> iterator, through iterator_traits: " << i << std::endl << std::endl;

	return 0;
}