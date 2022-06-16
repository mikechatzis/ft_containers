/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_map_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:31:29 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/16 16:36:07 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>

int main()
{

	// ft::tree<int,std::string> tr(1, "hello");
	// ft::tree<int,std::string> tr2;
	
	// tr2.testf();

	// std::map_iterator<ft::tree<int, std::string> > n_it(&tr2);
	// std::map_iterator<ft::tree<int, std::string> > n_it2(&tr2);

	// std::map_iterator<ft::tree<int, std::string> > n_it3(&tr2);
	// std::map_iterator<ft::tree<int, std::string> > n_it4(&tr2);
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
				mp[5] = 42;
				mp[6] = 6;
	
	std::map<int, int> dum;
	std::map<int, int> m(mp.begin(), mp.end());
	std::map<int, int> mc(m);
	std::map<int,int>::iterator itc = mc.begin();
	std::cout << "testing copy constructor\n";
	while(itc != mc.end())
		std::cout << "(" << itc->first << ", " << itc++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	std::map<int,int>::iterator it = m.begin();
	it++;

	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl;

	std::map<int, int> m2(m.begin(), m.end());
	std::map<int,int>::iterator it2 = m2.begin();
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

	it = m2.begin();
	if (it == m2.end())
		std::cout << "begin iterator of empty map is same as end iterator";
	std::cout << std::endl << std::endl;

	m2.insert(std::make_pair<int,int>(1, 1));
	it = m2.begin();
	std::cout<<"m2, inserting at empty map. m2: ";
	while(it != m2.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
		
	std::cout << "m2 size: " << m2.size() << std::endl << std::endl;
	std::cout << "m2 max size: " << m2.max_size() << std::endl;
	std::cout << "std::map max size: " << m.max_size() << std::endl << std::endl;

	it = m.begin();
	m.erase(++it);
	it = m.begin();
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

	std::pair<int, int> p(7,7);
	std::pair<std::map<int,int>::iterator, bool> con = m.insert(p);
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
	std::map<int,int>::iterator ins = m.insert(++it, std::pair<int,int>(-2,-2));
	std::cout << "inserting new value at improper hint position #1: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-2, -2), using hint: ";
	it = m.begin();
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
		std::cout << std::endl << std::endl;
	
	it = m.begin();
	ins = m.insert(it, std::pair<int,int>(-1,-1));
	std::cout << "inserting new value at proper hint position: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-1, -1), using hint: ";
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	ins = m.insert(--it, std::pair<int,int>(10,10));
	std::cout << "inserting new value at proper hint position: " << ins->first << std::endl;
	std::cout<<"m, after inserting element (-1, -1), using hint: ";
	it = m.begin();
	while(it != m.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	ins = m.insert(--it, std::pair<int,int>(0,0));
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
	
	std::map<int,int> m_swap(mp.begin(), mp.end());
	std::map<int,int>::iterator new_it = m_swap.begin();
	it = m.begin();

	std::cout << "new map 'm_swap' before swap: ";
	while(new_it != m_swap.end())
		std::cout << "(" << new_it->first << ", " << new_it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	std::cout << "iterators before swap in order: it, new_it: " << it->first << "....." << new_it->first << std::endl;
	m_swap.swap(m);
	std::cout << "iterators after swap in order: it, new_it: " << it->first << "....." << new_it->first << std::endl;
	
	std::cout<<"m, after swap with m_swap: ";
	new_it = m.begin();
	while(new_it != m.end())
		std::cout << "(" << new_it->first << ", " << new_it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << "new map 'm_swap' after swap: ";
	it = m_swap.begin();
	while(it != m_swap.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::swap(m_swap, m);
	std::cout<<"m, after ft::swap with m_swap: ";
	new_it = m.begin();
	while(new_it != m.end())
		std::cout << "(" << new_it->first << ", " << new_it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << "new map 'm_swap' after ft::swap: ";
	it = m_swap.begin();
	while(it != m_swap.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::cout << "using 'count': map 'm' has " << m.count(4) << " elements with a key of value '4'\n";
	std::cout << "using 'count': map 'm' has " << m.count(42) << " elements with a key of value '42'";
	std::cout << std::endl << std::endl;

	std::cout << "lower_bound(3): " << m_swap.lower_bound(3)->first << std::endl;
	std::cout << "std lower_bound(3): " << mp.lower_bound(3)->first << std::endl;
	std::cout << "lower_bound(-1): " << m_swap.lower_bound(-1)->first << std::endl;
	std::cout << "std lower_bound(-1): " << mp.lower_bound(-1)->first << std::endl;
	std::cout << "lower_bound(42): "; it = m_swap.lower_bound(42);
	if (it == m_swap.end())
		std::cout << "end iterator";
	std::cout << std::endl << std::endl;

	std::cout << "upper_bound(3): " << m_swap.upper_bound(3)->first << std::endl;
	std::cout << "std upper_bound(3): " << mp.upper_bound(3)->first << std::endl;
	std::cout << "upper_bound(-1): " << m_swap.upper_bound(-1)->first << std::endl;
	std::cout << "std upper_bound(-1): " << mp.upper_bound(-1)->first << std::endl;
	std::cout << "upper_bound(42): "; it = m_swap.upper_bound(42);
	if (it == m_swap.end())
		std::cout << "end iterator";
	std::cout << std::endl << std::endl;

	std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> pair = m_swap.equal_range(4);
	std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> std_pair = mp.equal_range(4);
	std::cout << "equal range first, second: " << pair.first->first << ", " <<  pair.second->first << std::endl;
	std::cout << "std equal range first, second: " << std_pair.first->first << ", " <<  std_pair.second->first;
	std::cout << std::endl << std::endl;

	pair = m_swap.equal_range(1);
	std_pair = mp.equal_range(1);
	std::cout << "equal range first, second: " << pair.first->first << ", " <<  pair.second->first << std::endl;
	std::cout << "std equal range first, second: " << std_pair.first->first << ", " <<  std_pair.second->first;
	std::cout << std::endl << std::endl;

	pair = m_swap.equal_range(6);
	std_pair = mp.equal_range(6);
	if (pair.second == m_swap.end() && std_pair.second == mp.end())
		std::cout << "upper end: both 'second' iterators are 'end'" << std::endl;
	std::cout << std::endl;

	pair = m_swap.equal_range(42);
	std_pair = mp.equal_range(42);
	if (pair.second == m_swap.end() && std_pair.second == mp.end() && pair.first == m_swap.end() && std_pair.first == mp.end())
		std::cout << "invalid value: all 4 iterators are 'end'" << std::endl;
	std::cout << std::endl;

	std::less<int> cmp = m_swap.key_comp();
	std::cout << "compare object results: " << cmp(0,1) << std::endl << std::endl;

	std::map<int,int>::value_compare comp2 = m_swap.value_comp();
	std::pair<int,int> pa(1, 42), pb(-1, 42);
	std::cout << "compare pairs using 'value compare' object results: " << comp2(pa, pb) << std::endl << std::endl;

	std::cout << "testing 'at':\n";
	std::cout << "valid input: " << m_swap.at(5) << std::endl;

	try{
		m_swap.at(42);
	}
	catch( const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		mp.at(42);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	m_swap[7] = 77;
	std::cout << "testing [] operator overload, asigning new value. new m_swap: ";
	it = m_swap.begin();
	while(it != m_swap.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	std::cout << "testing [] operator overload for random existing and non existing keys: ";
	std::cout << m_swap[2] << " " << m_swap[12] << " " << m_swap[5];
	std::cout << std::endl << std::endl;

	std::map<int,int> copy(m_swap);
	std::cout << "testing copy constructor, creating a copy. new map 'copy':\n";
	it = copy.begin();
	while(it != copy.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::map<int,int> copy2 = m_swap;
	std::cout << "testing '=' operator overload, creating a copy. new map 'copy2':\n";
	it = copy2.begin();
	while(it != copy2.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::cout << "testing reverse iterator operations. m_swap reversed is:\n";
	std::map<int,int>::reverse_iterator rev_it = m_swap.rbegin();
	while(rev_it != m_swap.rend())
		std::cout << "(" << rev_it->first << ", " << rev_it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::cout << "testing end iterator --. m_swap last pair is:\n";
	it = m_swap.end(); it--;
	std::cout << "(" << it->first << ", " << it->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::cout << "testing end reverse iterator --. m_swap first pair is:\n";
	rev_it = m_swap.rend(); rev_it--;
	std::cout << "(" << rev_it->first << ", " << rev_it->second << ")" << " ";
	std::cout << std::endl << std::endl;

	it = m_swap.begin();
	std::cout << "testing '*' operator of iterator:\n";
	std::pair<int, int> star_p = *it;
	std::cout << "(" << star_p.first << ", " << star_p.second << ")" << " ";
	std::cout << std::endl << std::endl;

	rev_it = m_swap.rbegin();
	std::cout << "testing '*' operator of rev_iterator:\n";
	std::pair<int, int> starr_p = *rev_it;
	std::cout << "(" << starr_p.first << ", " << starr_p.second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::map<int, std::string> strm;
	strm[1] = "hello";
	strm[2] = "world";
	strm[3] = "how";
	strm[4] = "ya doin?";
	
	std::map<int, std::string> f_strm(strm.begin(), strm.end());
	std::map<int, std::string>::iterator sit = f_strm.begin();
	std::cout << "testing data types int, string:\n";
	while(sit != f_strm.end())
		std::cout << "(" << sit->first << ", " << sit++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::cout << "testing data types int, string:\ninserting new element\n";
	f_strm.insert(std::pair<int, std::string>(-2, "off text"));
	sit = f_strm.begin();
	while(sit != f_strm.end())
		std::cout << "(" << sit->first << ", " << sit++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::map<std::string, std::string> strstrm;
	strstrm["one"] = "hello";
	strstrm["two"] = "world";
	strstrm["three"] = "how";
	strstrm["four"] = "ya doin?";
	
	std::map<std::string, std::string> f_strstrm(strstrm.begin(), strstrm.end());
	std::map<std::string, std::string>::iterator ssit = f_strstrm.begin();
	std::cout << "testing data types std::string, string:\n";
	while(ssit != f_strstrm.end())
		std::cout << "(" << ssit->first << ", " << ssit++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::cout << "testing data types std::string, std::string:\ninserting new element\n";
	f_strstrm.insert(std::pair<std::string, std::string>("minus one", "off text"));
	ssit = f_strstrm.begin();
	while(ssit != f_strstrm.end())
		std::cout << "(" << ssit->first << ", " << ssit++->second << ")" << " ";
	std::cout << std::endl << std::endl;
	
	const std::map<int,int>::iterator con_it = m.begin();
	it = m.begin();
	if (con_it == it)
		std::cout << "iterator to const iterator comparison successful\n";

	mc = m;
	it = mc.begin();
	std::cout << "testing '=' operator, copied m:\n";
	while(it != mc.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;

	std::map<int,int>::const_iterator con_it2 = m.begin();
	con_it2++;
	// con_it2->second = 13;
	it->second = 13;
	it = mc.begin();
	std::cout << "testing reassigning, m:\n";
	while(it != mc.end())
		std::cout << "(" << it->first << ", " << it++->second << ")" << " ";
	std::cout << std::endl << std::endl;
}
