/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/14 21:40:30 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <map>
#include <vector>
#include <array>

int main(){
	
	std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
	ft::vector<int> v(arr.begin(), arr.end());
	ft::stack<int> s(v);
	ft::stack<int> s2 = s;
	
	std::cout << "relational operators\n\n";
	if (s == s2)
		std::cout << "stacks s and v are equal\n\n";
	if (!(s < s2))
		std::cout << "stacks s and v are still equal\n\n";
	if (!(s > s2))
		std::cout << "stacks s and v remain equal\n\n";
	if (s <= s2)
		std::cout << "stacks s and v do are equal\n\n";
	if (s >= s2)
		std::cout << "stacks s and v = equal\n\n";
	if (!(s != s2))
		std::cout << "stacks s and v are the same\n\n";
	
	if (s.empty())
		std::cout << "stack s is empty\n\n";
	else
		std::cout << "stack s is not empty\n\n";
	std::cout << "stack s size: " << s.size();
	std::cout << std::endl << std::endl;

	std::cout << "stack s top element: " << s.top();
	std::cout << std::endl << std::endl;

	s.pop();
	std::cout << "stack s top element after pop: " << s.top();
	std::cout << std::endl << std::endl;

	s.push(42);
	std::cout << "stack s top element after pushing '42': " << s.top();
	std::cout << std::endl << std::endl;
	
	if (s > s2)
		std::cout << "s > s2\n\n";
	if (s >= s2)
		std::cout << "s >= s2\n\n";

	if (s < s2)
		std::cout << "s > s2\n\n";
	if (s <= s2)
		std::cout << "s >= s2\n\n";
}
