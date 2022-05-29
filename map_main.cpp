/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/29 13:15:52 by mchatzip         ###   ########.fr       */
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

	std::map<int, std::string>::iterator it = m.begin();
	std::cout << it->first << " " << it->second << std::endl;
	tr.insert(it);
}