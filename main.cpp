/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/23 18:34:50 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <array>
#include <vector>

int main()
{
	ft::vector<int> v;
	ft::vector<std::string> *v2 = new ft::vector<std::string>(15, "hello");
	ft::vector<std::string> v2_copy(*v2);
	v2->print();
	delete v2;
	v2_copy.print();

	std::array<std::string, 42> a;
	for (int i = 0; i<42; i++)
		a[i] = "hi";

	ft::vector<std::string> v3(a.begin(), a.end());
	v3.print();

	ft::vector<std::string> v3_copy = v3;
	v3_copy.print();

	v3.resize(50, "2");
	v3.print();
	
	std::cout << v3.empty() << std::endl;
	
	std::vector<std::string> libv;
	std::cout << "max size of v3(vector<string>) = " << v3.max_size() << std::endl << "max size of v(vector<int>) = " << v.max_size() << std::endl
		<< "max size of original vector<string> = " << libv.max_size() << std::endl;

	v.reserve(100);
	std::cout << "v capacity = " << v.capacity() << std::endl << "v3 old capacity is = " << v3.capacity() << std::endl;
	v3. reserve(60);
	v3. reserve(30);
	std::cout << "v3 new capacity = " << v3.capacity() << std::endl;
	std::cout << "v3 content: "; v3.print();

	std::cout << "the 3rd value of v3 is: " << v3[2] << "::" << v3.at(2) << std::endl;
	std::cout << "the first value of v3 is: " << v3.front() << "\nand the last one is" << v3.back() << std::endl;
}