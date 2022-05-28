/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/05/28 16:28:03 by mchatzip         ###   ########.fr       */
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
	std::pair<const Key, T> *pair;
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

			tree(const allocator_type &alloc = allocator_type()) : _node_count(0), _root(NULL), _lv(0) {
				_Alloc = allocator_type(alloc);
			}
			tree(const Key &k, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _lv(1) {
				_Alloc = allocator_type(alloc);
				_root = new node<Key, T>;
				_Alloc.construct(_root->pair, (std::pair<Key, T>(k, val)));
				_root->left = NULL;
				_root->right = NULL;
				_node_count = 1;
			}
			~tree(){
				node<Key, T> *tmp_left = _root->left;
				node<Key, T> *tmp_right = _root->right;
				
				_Alloc.destroy(_root->pair);
				delete _root;
				
				
			};

		private:
			size_t _node_count;
			node<Key, T> *_root;
			size_t _lv;
			allocator_type _Alloc;
	};
}

#endif