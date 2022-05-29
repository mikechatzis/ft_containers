/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/29 13:22:53 by mchatzip         ###   ########.fr       */
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

template<typename Key, typename T> struct node{
	std::pair<const Key, T> pair;
	node *left;
	node *right;
};

namespace ft
{	
	template<typename Key, typename T, class Allocator = std::allocator<std::pair<const Key, T> > > class tree
	{
		public:

			typedef std::allocator<std::pair<const Key, T> > allocator_type;
			typedef T value_type;


			//CONSTRUCTORS & DESTRUCTOR//
			tree(const allocator_type &alloc = allocator_type()) : _node_count(0), _root(NULL) {
				_Alloc = allocator_type(alloc);
			}
			tree(const Key &k, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _node_count(1) {
				_Alloc = allocator_type(alloc);
				_arr_Alloc = std::allocator<node<Key, T>*>();
				_root = new node<Key, T>;
				_Alloc.construct(&(_root->pair), std::pair<Key, T>(k, val));
				_root->left = NULL;
				_root->right = NULL;
				_acc = _arr_Alloc.allocate(_node_count * sizeof(node<Key, T> *));
				_acc[0] = _root;
			}
			~tree(){
				
				for (size_t i = 0; i < _node_count; i++)
				{
					_Alloc.destroy(&(_acc[i]->pair));
					delete _acc[i];
					std::cout << i << std::endl;
				}
				_arr_Alloc.deallocate(_acc, _node_count);
			};
			////

			template<class InputIt> void insert(InputIt map_elem){
				node<Key, T> *tmp[_node_count + 1];
				for (size_t i = 0; i < _node_count; i++)
					tmp[i] = _acc[i];
					
				_arr_Alloc.deallocate(_acc, _node_count);
				_acc = _arr_Alloc.allocate((_node_count + 1) * sizeof(node<Key, T> *));
				for (size_t i = 0; i < _node_count; i++)
					_acc[i] = tmp[i];
				
				if (!_root)
				{
					_root = new node<Key, T>;
					_Alloc.construct(&(_root->pair), std::pair<Key, T>(map_elem->first, map_elem->second));
					_root->left = NULL;
					_root->right = NULL;
					_acc[0] = _root;
					std::cout << "test\n";
				}
				else
				{
					node<Key, T> *temp = _root;
					while (temp)
					{
						if (map_elem->first < temp->pair.first)
						{
							if (temp->left)
								temp = temp->left;
							else
								break;
						}
						else if (map_elem->first > temp->pair.first)
						{
							if (temp->right)
								temp = temp->right;
							else
								break;
						}
						else
						{
							temp->pair.second = map_elem->second;
							return;
						}
					}
					
					if (map_elem->first < temp->pair.first)
					{
						temp->left = new node<Key, T>;
						_Alloc.construct(&(temp->left->pair), std::pair<Key, T>(map_elem->first, map_elem->second));
						temp->left->left = NULL;
						temp->left->right = NULL;
						_acc[_node_count] = temp->left;
					}
					else
					{
						temp->right = new node<Key, T>;
						_Alloc.construct(&(temp->right->pair), std::pair<Key, T>(map_elem->first, map_elem->second));
						temp->right->left = NULL;
						temp->right->right = NULL;
						_acc[_node_count] = temp->right;
					}
				}
				this->_node_count++;
			}

		private:
			size_t _node_count;
			node<Key, T> *_root;
			node<Key, T> **_acc;
			std::allocator<node<Key, T>*> _arr_Alloc;
			allocator_type _Alloc;
	};
}

#endif