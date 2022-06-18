/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_stack_main.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/18 12:31:58 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

int main(){
	
	std::vector<int> a;
	for (int i = 0; i<42; i++)
		a.push_back(i + 1);
	std::vector<int> v(a.begin(), a.end());
	std::stack<int, std::vector<int> > s(v);
	std::stack<int, std::vector<int> > s2 = s;
	
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

	std::stack<int, std::vector<int> > stl(a);
	if (stl.empty())
		std::cout << "stack s is empty\n\n";
	else
		std::cout << "stack s is not empty\n\n";
	std::cout << "stack s size: " << stl.size();
	std::cout << std::endl << std::endl;

	std::cout << "stack s top element: " << stl.top();
	std::cout << std::endl << std::endl;

	s.pop();
	std::cout << "stack s top element after pop: " << stl.top();
	std::cout << std::endl << std::endl;

	s.push(42);
	std::cout << "stack s top element after pushing '42': " << stl.top();
	std::cout << std::endl << std::endl;

	std::list<int> lst(a.begin(), a.end());
	std::stack<int, std::list<int> > stl2(lst);
	if (stl2.empty())
		std::cout << "stack s is empty\n\n";
	else
		std::cout << "stack s is not empty\n\n";
	std::cout << "stack s size: " << stl2.size();
	std::cout << std::endl << std::endl;

	std::cout << "stack s top element: " << stl2.top();
	std::cout << std::endl << std::endl;

	s.pop();
	std::cout << "stack s top element after pop: " << stl2.top();
	std::cout << std::endl << std::endl;

	s.push(42);
	std::cout << "stack s top element after pushing '42': " << stl2.top();
	std::cout << std::endl << std::endl;

	std::deque<int> de(a.begin(), a.end());
	std::stack<int, std::deque<int> > stl3(de);
	if (stl3.empty())
		std::cout << "stack s is empty\n\n";
	else
		std::cout << "stack s is not empty\n\n";
	std::cout << "stack s size: " << stl3.size();
	std::cout << std::endl << std::endl;

	std::cout << "stack s top element: " << stl3.top();
	std::cout << std::endl << std::endl;

	s.pop();
	std::cout << "stack s top element after pop: " << stl3.top();
	std::cout << std::endl << std::endl;

	s.push(42);
	std::cout << "stack s top element after pushing '42': " << stl3.top();
	std::cout << std::endl << std::endl;
	
}
