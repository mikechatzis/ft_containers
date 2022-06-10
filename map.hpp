/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/10 17:55:53 by mchatzip         ###   ########.fr       */
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
#include <array>
#include <math.h>
#include "map_iterators.hpp"

namespace ft
{
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
			
			
			T1 first;
			T2 second;
	};
	template<typename T1, typename T2> bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template<typename T1, typename T2> bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return lhs.first != rhs.first || lhs.second != rhs.second;
	}
	template<typename T1, typename T2> bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
	}
	template<typename T1, typename T2> bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
	}
	template<typename T1, typename T2> bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return lhs.first <= rhs.first || (lhs.first == rhs.first && lhs.second <= rhs.second);
	}
	template<typename T1, typename T2> bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return lhs.first >= rhs.first || (lhs.first == rhs.first && lhs.second >= rhs.second);
	}

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ){
		return pair<T1, T2>(t, u);
	}

}

template<typename Key, typename T> struct node{
	ft::pair<const Key, T> *pair;
	node *left;
	node *right;
};

namespace ft
{	
	template<typename Key, typename T, class allocator > class tree
	{
		public:

			typedef allocator allocator_type;
			typedef T value_type;
			typedef Key key_type;
			typedef node<Key, T>* NODE;

			//CONSTRUCTORS & DESTRUCTOR//
			tree(const allocator_type &alloc = allocator_type()) : _root(NULL), _node_count(0) {
				_Alloc = allocator_type(alloc);
			}
			// tree(tree const &other, const allocator_type &alloc = allocator_type()) {
			// 	std::allocator< node<Key,T> > al;
			// 	_Alloc = allocator_type(alloc);
			// 	if (!_root && other._root)
			// 	{
			// 		_root = al.allocate(1);
			// 		_Alloc.construct(&(_root->pair), ft::pair< Key, T >(other._root->pair->first, other._root->pair->second));
			// 		other.clone_tree(_root);
			// 	}
			// 	_node_count = other._node_count;
			// }
			~tree(){
				while(_root)
					_root = delete_node(_root, _root->pair->first);
			}
			////

			tree &operator=(tree const &other){
				other.clone_tree(_root);
				return *this;
			}
			
			node<Key, T> &get_root(){
				return *this->_root;
			}

			size_t get_size() const {
				return _node_count;
			}

			const NODE clone_node_noLR(const NODE n) const {
				if (!n)
					return NULL;
				std::allocator<ft::pair<const Key, T> > newp;
				std::allocator<node<Key, T> > tmp_all;
				NODE ret = tmp_all.allocate(1);
				newp.construct(&(ret->pair), ft::pair<Key, T>(n->pair->first, n->pair->second));
				n->right = n->left = NULL;
				return ret;
			}

			void clone_tree(node<Key, T> *root) const {
				static NODE tmp = _root;
				if (root)
				{
					NODE newleft = clone_node_noLR(tmp->left);
					root->left = newleft;
					tmp = tmp->left;
					clone_tree(root->left);
					
					NODE newright = clone_node_noLR(tmp->right);
					root->right = newright;
					tmp = tmp->right;
					clone_tree(root->right);
				}
			}

			template<class InputIt> void insert(node<Key, T> *&n, InputIt map_elem){
				std::allocator<node<Key, T> > tmp_all;
				if (!n)
				{
					n = tmp_all.allocate(1);
					tmp_all.construct(n, node<Key, T>());
					n->pair = _Alloc.allocate(1);
					_Alloc.construct(n->pair, ft::pair<Key, T>(map_elem->first, map_elem->second));
					n->right = n->left = NULL;
					// std::cout << "creation "<< n->pair->first << std::endl;
					this->_node_count += 1;
					
				}
				else if (map_elem->first > n->pair->first)
				{
					// std::cout << "jump right" << std::endl;
					insert(n->right, map_elem);	
				}
				else if (map_elem->first < n->pair->first)
				{
					// std::cout << "jump left" << std::endl;
					insert(n->left, map_elem);
				}
			}

			void insert_pair(node<Key, T> *&n, ft::pair<Key, T> const &map_elem){
				std::allocator<node<Key, T> > tmp_all;
				if (!n)
				{
					n = tmp_all.allocate(1);
					tmp_all.construct(n, node<Key, T>());
					n->pair = _Alloc.allocate(1);
					_Alloc.construct(n->pair, map_elem);
					n->right = n->left = NULL;
					// std::cout << "creation "<< n->pair->first << std::endl;
					this->_node_count += 1;
				}
				else if (map_elem.first > n->pair->first)
				{
					// std::cout << "jump right" << std::endl;
					insert_pair(n->right, map_elem);	
				}
				else if (map_elem.first < n->pair->first)
				{
					// std::cout << "jump left" << std::endl;
					insert_pair(n->left, map_elem);
				}
			}

			NODE insert_toPos(ft::pair<Key, T> const &map_elem){
				std::allocator<node<Key, T> > tmp_all;
				NODE n;
				n = tmp_all.allocate(1);
				tmp_all.construct(n, node<Key, T>());
				n->pair = _Alloc.allocate(1);
				_Alloc.construct(n->pair, map_elem);
				n->right = n->left = NULL;
				// std::cout << "creation "<< n->pair->first << std::endl;
				this->_node_count += 1;
				return n;
			}

			// void testf(){
			// 	std::map<int, std::string> m;
			// 	m[2] = "two";
			// 	m[3] = "three";
			// 	m[4] = "four";

			// 	std::map<int, std::string>::iterator it = m.begin();
			// 	insert(_root, it);
			// 	insert(_root, ++it);
			// 	insert(_root, ++it);
			// 	// std::cout << search(_root, 3)->pair->second << std::endl;

			// }
			NODE delete_node(NODE root, const Key &key){
				std::allocator<node<Key, T> > tmp_all;
				if (!root)
					return root;
				if (key < root->pair->first)
					root->left = delete_node(root->left, key);
				else if (key > root->pair->first)
					root->right = delete_node(root->right, key);
				else
				{
					if (!root->left && !root->right)
					{
						_Alloc.destroy(root->pair);
						_Alloc.deallocate(root->pair, 1);
						tmp_all.deallocate(root, 1);
						_node_count -= 1;
						return NULL;
					}
					else if (!root->left)
					{
						NODE tmp = root->right;
						_Alloc.destroy(root->pair);
						_Alloc.deallocate(root->pair, 1);
						tmp_all.deallocate(root, 1);
						_node_count -= 1;
						return tmp;
					}
					else if (!root->right)
					{
						NODE tmp = root->left;
						_Alloc.destroy(root->pair);
						_Alloc.deallocate(root->pair, 1);
						tmp_all.deallocate(root, 1);
						_node_count -= 1;
						return tmp;
					}

					NODE suc = NULL; next(root, suc, root);
					_Alloc.destroy(root->pair);
					_Alloc.construct(root->pair, ft::pair<Key, T>(suc->pair->first, suc->pair->second));
					root->right = delete_node(root->right, key);
				}
				// _node_count -= 1;
				return root;
			}

			NODE delete_node_atPos(NODE n){
				std::allocator<node<Key, T> > tmp_all;
				_Alloc.destroy(n->pair);
				_Alloc.deallocate(n->pair, 1);
				tmp_all.deallocate(n, 1);
				_node_count -= 1;
				return NULL;
			}

			NODE search(NODE n, const Key &key){
				if (!n || n->pair->first == key)
					return n;
				else if (n->pair->first < key)
					n = search(n->right, key);
				else
					n = search(n->left, key);
				return n;
			}

			void next(node<Key, T> *&root, node<Key, T> *&suc, const NODE n){
				if (!root)
					return;
				if (root->pair->first == n->pair->first)
				{
					
					if (root->right)
					{
						NODE tmp = root->right;
						while (tmp->left)
							tmp = tmp->left;
						suc = tmp;
					}
					return;
				}	
				if (root->pair->first > n->pair->first)
				{
					suc = root;
					next(root->left, suc, n);
				}
				else
					next(root->right, suc, n);
			}

			void prev(node<Key, T> *&root, node<Key, T> *&pre, const NODE n){
				if (!root)
					return;
				if (root->pair->first == n->pair->first)
				{
					if (root->left)
					{
						NODE tmp = root->left;
						while (tmp->right)
							tmp = tmp->right;
						pre = tmp;
					}
					return;
				}	
				if (root->pair->first > n->pair->first)
					prev(root->left, pre, n);
				else
				{
					pre = root;
					prev(root->right, pre, n);	
				}
			}

			NODE lower_bound(NODE root, const Key &key){
				if (!(root->left) && !(root->right) && root->pair->first < key)
					return NULL;
				if (root->pair->first >= key && (!(root->left) || root->left->pair->first < key))
					return root;
				if (root->pair->first <= key)
        			return lower_bound(root->right, key);
 				else
					return lower_bound(root->left, key);
			}

			NODE upper_bound(NODE root, const Key &key){
				if (!root || (!(root->left) && !(root->right) && root->pair->first < key))
					return NULL;
				if (root->pair->first > key && (!(root->left) || root->left->pair->first < key))
					return root;
				if (root->pair->first <= key)
        			return upper_bound(root->right, key);
 				else
					return upper_bound(root->left, key);
			}

			NODE last(){
				NODE n = _root;
				while (n->right)
					n = n->right;
				return n;
			}

			NODE first(){
				NODE first = _root;
				NODE tmp_root = _root;
				while(first)
				{
					prev(_root, first, tmp_root);
					if (first == _root || first == tmp_root)
						break;
					tmp_root = first;
				}
				return first;
			}
			
			// template<
			// 	class D_Key,
			// 	class U,
			// 	class Compare ,
			// 	class Allocator >
			// 	friend class map;

			NODE _root;
			size_t _node_count;
			allocator_type _Alloc;
	};


//////MAP///////
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map{
		
		public:
			typedef ft::pair<const Key, T> value_type;
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::tree<Key, T, Allocator> BST;
			typedef size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::map_iterator<map> iterator;
			typedef const ft::map_iterator<map> const_iterator;
			typedef ft::reverse_map_iterator<iterator, map> reverse_iterator;
			typedef const ft::reverse_map_iterator<iterator, map> const_reverse_iterator;

			map(const key_compare& comp = key_compare()) : comp(comp){
				std::allocator<BST> tree_maker;
				_tree = &tree_maker.allocate(1);
				tree_maker.construct(_tree, BST());
			};
			template< class InputIt > map(InputIt first, InputIt last, const Compare& comp = Compare()) : comp(comp){
				std::allocator<BST> tree_maker;
				_tree = tree_maker.allocate(1);
				tree_maker.construct(_tree, BST());
				InputIt next;
				while (first != last)
				{
					next = first;
					while (next != last)
					{
						if (!comp(first->first, next->first) && !comp(next->first, first->first) && first != next)
							break;
						else
							_tree->insert(_tree->_root, first);
						next++;
					}
					first++;
				}
			}
			map(map const &other, const key_compare& comp = key_compare()) : comp(comp) {
				std::allocator<BST> tree_maker;
				_tree = tree_maker.allocate(1);
				tree_maker.construct(_tree, BST());
				insert(other.begin(), other.end());
			}
			
			~map(){
				std::allocator<BST> tree_maker;
				tree_maker.destroy(_tree);
				tree_maker.deallocate(_tree, 1);
			}

			map &operator=(map const & other){
				clear();
				insert(other.begin(), other.end());
			}

			BST &get_tree() const {
				return *_tree;
			}

			//////ITERATORS////
			iterator begin(){
				return iterator(this, _tree->first());
			}
			iterator end(){
				iterator it(this, _tree->last());
				it.current_node = NULL;
				return it;
			}

			const_iterator end() const {
				iterator it(this, _tree->last());
				it.current_node = NULL;
				return it;
			}

			const_iterator begin() const {
				return const_iterator(this, _tree->first());
			}

			reverse_iterator rbegin(){
				return reverse_iterator(this, _tree->last());
			}
			reverse_iterator rend(){
				reverse_iterator rev_it(this, _tree->first());
				rev_it.it.current_node = NULL;
				return  rev_it;
			}

			const_reverse_iterator rend() const {
				reverse_iterator rev_it(this, _tree->first());
				rev_it.it.current_node = NULL;
				return  rev_it;
			}

			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(this, _tree->last());
			}
			
			//////Capacity///////
			bool empty() const {
				return !_tree->_root;
			}

			size_type size() const {
				return _tree->get_size();
			}

			size_type max_size() const {
				std::allocator<BST> tmp;
				return tmp.max_size();
			}

			//////MODIFIERS//////
			void clear(){
				while (_tree->_root)
					_tree->_root = _tree->delete_node(_tree->_root, _tree->_root->pair->first);
			}

			void erase( iterator pos ){
				_tree->_root = _tree->delete_node(_tree->_root, pos->first);
			}

			void erase( iterator first, iterator last ){
				while (first != last)
				{
					key_type tmp = first.first;
					first++;
					_tree->_root = _tree->delete_node(_tree->_root, tmp);
				}
			}
			size_type erase( const Key& key ){
				size_type i = 0;
				if (_tree->search(_tree->_root, key))
					i = 1;
				_tree->_root = _tree->delete_node(_tree->_root, key);
				return i;
			}

			ft::pair<iterator, bool> insert( const value_type& value ){
				bool i = 1;
				iterator it;
				if ((it = find(value.first)) != end())
				{
					i = 0;
					return ft::pair<iterator, bool>(it, i);
				}
				_tree->insert_pair(_tree->_root, value);
				it = find(value.first);
				return ft::pair<iterator, bool>(it, i);
			}

			iterator insert( iterator hint, const value_type& value ){
				iterator it;
				if ((it = find(value.first)) != end())
					return it;
				if (!((hint.current_node)->left) && value.first < hint->first)
				{
					hint.current_node->left = _tree->insert_toPos(value);
					if ((it = find(value.first)) != end())
						return it;
					else
						hint.current_node->left = _tree->delete_node_atPos(hint.current_node->left);
				}
				else if (!((hint.current_node)->right) && value.first > hint->first)
				{
					hint.current_node->right = _tree->insert_toPos(value);
					if ((it = find(value.first)) != end())
						return it;
					else
						hint.current_node->right = _tree->delete_node_atPos(hint.current_node->right);
				}
				_tree->insert_pair(_tree->_root, value);	
				it = find(value.first);
				return it;
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				InputIt next;
				while (first != last)
				{
					next = first;
					while (next != last)
					{
						if (!comp(first->first, next->first) && !comp(next->first, first->first) && first != next)
							break;
						else
							_tree->insert(_tree->_root, first);
						next++;
					}
					first++;
				}
			}

			void swap( map& other ){
				BST *tmp = other._tree;
				other._tree = _tree;
				_tree = tmp;
			}
			
			
			//////LOOKUP//////
			iterator find( const Key& key ){
				typename BST::NODE n = _tree->search(_tree->_root, key);
				if (!n)
					return end();
				else
					return iterator(this, n);
			}

			const_iterator find( const Key& key ) const {
				typename BST::NODE n = _tree->search(_tree->_root, key);
				if (!n)
					return end();
				else
					return const_iterator(this, n);
			}

			size_type count( const Key& key ) const {
				iterator i = find(key);
				if (!comp(i->first, key) && !comp(key, i->first))
					return 1;
				return 0;
			}

			iterator lower_bound( const Key& key ){
				typename BST::NODE n = _tree->lower_bound(_tree->_root, key);
				if (n)
					return iterator(this, n);
				else
					return iterator();
				
			}

			const_iterator lower_bound( const Key& key ) const {
				typename BST::NODE n = _tree->lower_bound(_tree->_root, key);
				if (n)
					return const_iterator(this, n);
				else
					return const_iterator();
				
			}

			iterator upper_bound( const Key& key ){
				typename BST::NODE n = _tree->upper_bound(_tree->_root, key);
				if (n)
					return iterator(this, n);
				else
					return iterator();
			}

			const_iterator upper_bound( const Key& key ) const {
				typename BST::NODE n = _tree->upper_bound(_tree->_root, key);
				if (n)
					return const_iterator(this, n);
				else
					return const_iterator();
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ){
				return ft::pair<iterator,iterator>(lower_bound(key), upper_bound(key));
			}

			//////OBSERVERS//////
			key_compare key_comp() const {
				return key_compare();
			}
			
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Allocator>;
				public:
					bool operator()( const value_type& lhs, const value_type& rhs ) const {
						return comp(lhs.first, rhs.first);
					}

				protected:
					value_compare(Compare c) : comp(c) {}
					Compare comp;
			};
			
			value_compare value_comp() const {
				return ft::map<Key, T, Compare, Allocator>::value_compare(key_compare());
			}

			//////ELEMENT ACCESS//////
			T& at( const Key& key ){
				iterator it = find(key);
				if (it == end())
					throw std::out_of_range("ft::map:at: key not found");
				return it->second;
			}
			
			const T& at( const Key& key ) const {
				iterator it = find(key);
				if (it == end())
					throw std::out_of_range("ft::map:at: key not found");
				return it->second;
			}

			mapped_type& operator[] (const key_type& key)
			{
				iterator tmp = this->find(key);

				if (tmp == this->end())
					_tree->insert_pair(_tree->_root, value_type(key, mapped_type()));
				tmp = this->find(key);
				return (tmp.current_node->pair->second);
			}

		private:
			BST *_tree;
			std::less<key_type> comp;
};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
	}
}

#endif