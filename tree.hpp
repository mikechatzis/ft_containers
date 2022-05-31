/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/31 20:16:53 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TREE_H
# define TREE_H

#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <limits>
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "ft_vector.hpp"
#include <map>



namespace ft
{
	template <typename T> class map_iterator
	{
		public:
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T *pointer;
			typedef T &reference;
			typedef ft::bidirectional_iterator_tag iterator_category;
			
			map_iterator() : p(NULL), current_node(NULL) {}
			map_iterator(T *ptr) : p(ptr), current_node(p->get_root()) {}
			map_iterator(const map_iterator &other) : p(other.p), current_node(other.current_node) {}
			~map_iterator(){};
			
			map_iterator &operator=(const map_iterator &other){
				p = other.p;
				current_node = other.current_node;
				return *this;
			}
			reference operator*(void) const{
				return *p;
			}
			pointer operator->(void) const{
				return p;
			}
			map_iterator &operator++(){
				current_node = p->next(current_node);
				return this;
			}
			map_iterator &operator--(){
				current_node = p->prev(current_node);
				return this;
			}
			map_iterator operator++(int dummy){
				(void)dummy;
				map_iterator<T> copy = *this;
				current_node = p->next(current_node);
				return copy;
			}
			map_iterator operator--(int dummy){
				(void)dummy;
				map_iterator<T> copy = *this;
				current_node = p->prev(current_node);
				return copy;
			}

			// bool operator==(const map_iterator &rhs) const;
			// bool operator!=(const map_iterator &rhs) const;

			T *p;
			typename T::NODE current_node;
	};
	
	template<typename T1, typename T2> class pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;

			pair() : first(), second() {}
			pair( const T1& x, const T2& y ) :first(x), second(y) {}

			template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}
			pair (const pair& p) : first(p.first), second(p.second) {}

			pair &operator=(const pair &other){
				this->first = other.first;
				this->second = other.second;
				return *this;
			}

			void print(){
				std::cout << first << "|" << second << std::endl;
			}
			
			friend bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
				return lhs.first == rhs.first && lhs.second == rhs.second;
			}
			friend bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
				return lhs.first != rhs.first || lhs.second != rhs.second;
			}
			friend bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
				return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
			}
			friend bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
				return lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
			}
			friend bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
				return lhs.first <= rhs.first || (lhs.first == rhs.first && lhs.second <= rhs.second);
			}
			friend bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
				return lhs.first >= rhs.first || (lhs.first == rhs.first && lhs.second >= rhs.second);
			}
			
			T1 first;
			T2 second;
	};

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ){
		return pair<T1, T2>(t, u);
	}

}

template<typename Key, typename T> struct node{
	ft::pair<const Key, T> pair;
	node *left;
	node *right;
};

namespace ft
{	
	template<typename Key, typename T, class Allocator = std::allocator<ft::pair<const Key, T> > > class tree
	{
		public:

			typedef std::allocator<ft::pair<const Key, T> > allocator_type;
			typedef T value_type;
			typedef node<Key, T>* NODE;

			//CONSTRUCTORS & DESTRUCTOR//
			tree(const allocator_type &alloc = allocator_type()) : _node_count(0), _root(NULL) {
				_Alloc = allocator_type(alloc);
			}
			tree(const Key &k, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _node_count(1) {
				_Alloc = allocator_type(alloc);
				_arr_Alloc = std::allocator<node<Key, T>*>();
				_root = new node<Key, T>;
				_Alloc.construct(&(_root->pair), ft::pair<Key, T>(k, val));
				_root->left = NULL;
				_root->right = NULL;
				_acc = _arr_Alloc.allocate(_node_count * sizeof(NODE));
				_acc[0] = _root;
			}
			~tree(){

			};
			////
			
			node<Key, T> &get_root(){
				return *this->_root;
			}

			template<class InputIt> void insert(node<Key, T> *&n, InputIt map_elem){
				std::allocator<node<Key, T> > tmp_all;
				if (!n)
				{
					n = tmp_all.allocate(1);
					_Alloc.construct(&(n->pair), ft::pair<Key, T>(map_elem->first, map_elem->second));
					n->right = n->left = NULL;
					std::cout << "creation "<< n->pair.first << std::endl;
					this->_node_count += 1;
				}
				else if (map_elem->first > n->pair.first)
				{
					std::cout << "jump right" << std::endl;
					insert(n->right, map_elem);	
				}
				else if (map_elem->first < n->pair.first)
				{
					std::cout << "jump left" << std::endl;
					insert(n->left, map_elem);	
				}
			}

			void testf(){
				std::map<int, std::string> m;
				m[2] = "two";
				m[3] = "three";
				m[4] = "one";

				std::map<int, std::string>::iterator it = m.begin();
				insert(_root, it);
				insert(_root, ++it);
				std::cout << search(_root, 3)->pair.second << std::endl;
			}

			NODE search(NODE n, const Key &key){
				if (!n || n->pair.first == key)
					return n;
				else if (n->pair.first < key)
					n = search(n->right, key);
				else
					n = search(n->left, key);
				return n;
			}

			NODE next(const NODE n){
				NODE temp = _root;
				if (temp->pair.first == n->pair.first)
				{
					if (temp->right)
					{
						temp = temp->right;
						while (temp->left)
							temp = temp->left;
					}
					return temp;
				}	
				if (temp->pair.first > n->pair.first)
					temp = next(temp->left);
				else
					temp = next(temp->right);
				return temp;
			}

			NODE prev(const NODE n){
				NODE temp = _root;
				if (temp->pair.first == n->pair.first)
				{
					if (temp->left)
					{
						temp = temp->left;
						while (temp->right)
							temp = temp->right;
					}
					return temp;
				}	
				if (temp->pair.first > n->pair.first)
					temp = prev(temp->left);
				else
					temp = prev(temp->right);
				return temp;
			}
			
		private:
			size_t _node_count;
			NODE _root;
			NODE *_acc;
			std::allocator<node<Key, T>*> _arr_Alloc;
			allocator_type _Alloc;
	};
}

#endif