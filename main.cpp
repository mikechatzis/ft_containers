/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/25 19:10:18 by mchatzip         ###   ########.fr       */
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

	std::array<int, 42> a;
	for (int i = 0; i<42; i++)
		a[i] = i + 1;

	ft::vector<int> v3(a.begin(), a.end());
	v3.print(); std::cout << "v3 size is: " << v3.size() << std::endl;

	ft::vector<int> v3_copy = v3;
	v3_copy.print();

	v3.resize(50, 2);
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
	std::cout << "the first value of v3 is: " << v3.front() << "\nand the last one is " << v3.back() << std::endl;

	libv.resize(2, "hello");

	ft::vector<int>::iterator b = v3.begin();
	std::cout << "test \"begin\": ft::vector v3: " << *b << std::endl;
	std::cout << "test \"begin\": std::vector libv: " << *libv.begin() << std::endl;


	std::cout << "test \"end\": ft::vector v3: " << *v3.end() << std::endl;
	std::cout << "test \"end\": std::vector libv: " << *libv.end() << std::endl;

	std::cout << "test \"rbegin\": ft::vector v3: " << *v3.rbegin() << std::endl;
	std::cout << "test \"rbegin\": std::vector libv: " << *libv.rbegin() << std::endl;


	std::cout << "test \"rend\": ft::vector v3: " << *v3.rend() << std::endl;
	std::cout << "test \"rend\": std::vector libv: " << *libv.rend() << std::endl;

	ft::vector<int> v3_reverse(v3.rbegin(), v3.rend());
	std::cout << "v3 reversed is: "; v3_reverse.print(); std::cout << "with size = " << v3_reverse.size() << std::endl;

	ft::vector<int> v5(a.begin(), a.end()); ft::vector<int>::iterator e = v5.erase(v5.end() - 2);
	std::cout << "erase(position) used on v5. v5 size: " << v5.size()<< "| iterator returned by erase points to: " << *e << " | "; v5.print();
	e = v5.erase(v5.begin() + 1, v5.end() -2);
	std::cout << "erase(range) used on v5. v5 size: " << v5.size()<< "| iterator returned by erase points to: " << *e << " | "; v5.print();

	ft::vector<float> v4(2, (long)2); //v4.clear();
 	v4.print();
	std::cout << "v4 is clear if a new line follows: " << v4.at(0)<< " v4 size: " << v4.size() << std::endl;

	v5.swap(v3);
	std::cout << "v5 swapped with v3. New v5 size: " << v5.size() <<", " << v5.capacity() << " | "; v5.print(); std::cout << " New v3 size: " << v3.size() <<", " << v3.capacity() << " | "; v3.print();

	v5.assign(3, (size_t)31);
	std::cout << "v5 reassigned to smaller size. New v5 size: " << v5.size() << " | "; v5.print();
	v5.assign(65, (size_t)42);
	std::cout << "v5 reassigned to bigger size. New v5 size: " << v5.size() << " | "; v5.print();
	v5.assign(v3_reverse.begin(), v3_reverse.end());
	std::cout << "v5 reassigned from range to smaller size. New v5 size: " << v5.size() << " | "; v5.print();
	v5.clear();
	v5.assign(1, (size_t)42);
	v5.assign(v3_reverse.begin() + 1, v3_reverse.end() - 1);
	std::cout << "v5 reassigned from range to bigger size. New v5 size: " << v5.capacity() << " | "; v5.print();


	e = v5.insert(v5.begin() + 12, 128);
	std::cout << "inserted new value '128' to v5. v5 not enough capacity. New v5 size: " << v5.size() << ", insert iterator points to: " << *e << " | "; v5.print();
	v5 = v3;
	v5.reserve(10);
	v5.print();
	std::cout << "v5 capacity before insertion: " << v5.capacity() << std::endl;
	e = v5.insert(v5.end(), 128);
	std::cout << "inserted new value '128' to v5. v5 enough capacity. New v5 size: " << v5.capacity() << ", insert iterator points to: " << *e << " | "; v5.print();
}