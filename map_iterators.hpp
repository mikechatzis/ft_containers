/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:13:38 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/11 16:43:01 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATORS_H
# define MAP_ITERATORS_H

#include <memory>
#include <exception>
#include <stdexcept>
#include <iostream>
// #include <string>
// #include <limits>
// #include <iterator>
// #include <array>
// #include <math.h>
#include "map.hpp"


namespace ft
{
	template<typename T1, typename T2> class pair;
	template<typename Key, typename T, class allocator, class Compare > class tree;

	class bidirectional_iterator_tag;
	class random_access_iterator_tag;

	template <typename T> class map_iterator
	{
		public:
			typename T::BST *p;
			
			typedef typename T::BST BST;
			typedef std::ptrdiff_t difference_type;
			typedef typename T::value_type value_type;
			typedef T *pointer;
			typedef T &reference;
			typedef ft::bidirectional_iterator_tag iterator_category;
			
			typename T::BST::NODE current_node;

			map_iterator() : p(NULL), current_node(NULL), map(NULL){
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// dummy = al.allocate(1);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>());
			}
			map_iterator(T *ptr) : p(&(ptr->get_tree())), current_node(&(p->get_root())), map(ptr) {
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// dummy = al.allocate(1);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>());
				if (current_node)
				{
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
			}
			map_iterator(T const *ptr) : p(&(ptr->get_tree())), current_node(&(p->get_root())), map(ptr) {
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// dummy = al.allocate(1);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>());
				if (current_node)
				{
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
			}
			map_iterator(T *ptr, typename T::BST::NODE n) : p(&(ptr->get_tree())), current_node(n), map(ptr){
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// dummy = al.allocate(1);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>());
				if (current_node)
				{
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
			}
			map_iterator(T const *ptr, typename T::BST::NODE n) : p(&(ptr->get_tree())), current_node(n), map(ptr){
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// dummy = al.allocate(1);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>());
				if (current_node)
				{
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
			}
			map_iterator(const map_iterator &other) : p(other.p), current_node(other.current_node), first(other.first), second(other.second), map(other.map){
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// dummy = al.allocate(1);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>(other.first, other.second));
			}
			~map_iterator(){
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// al.destroy(dummy);
				// al.deallocate(dummy, 1);
			};
			
			map_iterator &operator=(const map_iterator &other){
				p = other.p;
				current_node = other.current_node;
				first = other.first;
				second = other.second;
				// std::allocator<ft::pair<typename T::key_type const, typename T::mapped_type> > al;
				// al.destroy(dummy);
				// al.construct(dummy, ft::pair<typename T::key_type, typename T::mapped_type>(other.first, other.second));
				return *this;
			}
			ft::pair<const typename T::key_type, typename T::mapped_type> &operator*() const{
				if (!current_node)
					return *(map->dummy);
				return *(current_node->pair);
			}
			
			map_iterator &operator++(){
				typename T::BST::NODE root = &p->get_root();
				typename T::BST::NODE suc = NULL;
				p->next(root, suc, current_node);
				current_node = suc;
				if (current_node)
				{
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
				return *this;
			}
			map_iterator &operator--(){
				if (!this->current_node)
				{
					current_node = p->last();
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
				else
				{	typename T::BST::NODE root = &p->get_root();
					typename T::BST::NODE pre = NULL;
					p->prev(root, pre, current_node);
					current_node = pre;
					if (current_node)
					{
						first = current_node->pair->first;
						second = current_node->pair->second;
					}
				}
				return *this;
			}
			map_iterator operator++(int dummy){
				(void)dummy;
				map_iterator<T> copy(*this);
				typename T::BST::NODE root = &p->get_root();
				typename T::BST::NODE suc = NULL;
				p->next(root, suc, current_node);
				current_node = suc;
				if (current_node)
				{
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
				return copy;
			}
			map_iterator operator--(int dummy){
				(void)dummy;
				map_iterator<T> copy(*this);
				if (!this->current_node)
				{
					current_node = p->last();
					first = current_node->pair->first;
					second = current_node->pair->second;
				}
				else
				{	typename T::BST::NODE root = &p->get_root();
					typename T::BST::NODE pre = NULL;
					p->prev(root, pre, current_node);
					current_node = pre;
					if (current_node)
					{
						first = current_node->pair->first;
						second = current_node->pair->second;
					}
				}
				return copy;
			}


			map_iterator<T> *operator->(){
				return this;
			}
			
			// template<
			// 	class Key,
			// 	class U,
			// 	class Compare ,
			// 	class Allocator >
			// 	friend class map;

			// template<class InputIt, class K> friend class reverse_map_iterator;
			
			typename BST::key_type first;
			typename BST::value_type second;
			private:
				T const *map;
			// 	ft::pair<typename T::key_type const, typename T::mapped_type> *dummy;
	};

	template <typename T> bool operator==(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
		return lhs.current_node == rhs.current_node;
	}
	template <typename T> bool operator!=(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
		return lhs.current_node != rhs.current_node;
	}
	template <typename T> bool operator<(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
		return lhs.current_node < rhs.current_node;
	}
	template <typename T> bool operator>(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
		return lhs.current_node > rhs.current_node;
	}
	template <typename T> bool operator>=(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
		return lhs.current_node >= rhs.current_node;
	}
	template <typename T> bool operator<=(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
		return lhs.current_node <= rhs.current_node;
	}
	
	template<class InputIt, class T> class reverse_map_iterator {
		public:
			InputIt it;

			typedef InputIt iterator_type;
			typedef typename InputIt::iterator_category iterator_category;
			typedef typename InputIt::value_type value_type;
			typedef typename InputIt::difference_type difference_type;
			typedef typename InputIt::pointer pointer;
			typedef typename InputIt::reference reference;

			typename T::BST::key_type first;
			typename T::BST::value_type second;
					
			reverse_map_iterator() : it() {}
			reverse_map_iterator(T *ptr) : it(ptr), first(it->first), second(it->second) {}
			reverse_map_iterator(T const *ptr) : it(ptr), first(it->first), second(it->second) {}
			reverse_map_iterator(T *ptr, typename T::BST::NODE n) : it(ptr, n), first(it->first), second(it->second) {}
			reverse_map_iterator(T const *ptr, typename T::BST::NODE n) : it(ptr, n), first(it->first), second(it->second) {}
			reverse_map_iterator(const reverse_map_iterator &other) : it(other.it), first(it->first), second(it->second) {}
			~reverse_map_iterator(){};

			reverse_map_iterator &operator=(const reverse_map_iterator &other){
				this->it = other.it;
				return *this;
			}

			ft::pair<const typename T::key_type, typename T::mapped_type> &operator*(void) const{
				return *(it.current_node->pair);
			}

			// template<
			// 	class Key,
			// 	class U,
			// 	class Compare ,
			// 	class Allocator >
			// 	friend class map;
				
			reverse_map_iterator &operator++(){
				it--;
				first = it.current_node->pair->first;
				second = it.current_node->pair->second;
				return this;
			}

			reverse_map_iterator operator++(int dummy){
				(void)dummy;
				reverse_map_iterator copy = *this;
				it--;
				if (it.current_node){
					first = it.current_node->pair->first;
					second = it.current_node->pair->second;
				}
				return copy;
			}

			reverse_map_iterator &operator--(){
				if (!this->it.current_node)
				{
					it.current_node = it.p->first();
					first = it.current_node->pair->first;
					second = it.current_node->pair->second;
				}
				else
					it++;
				return this;
			}

			reverse_map_iterator operator--(int dummy){
				(void)dummy;
				reverse_map_iterator copy = *this;
				if (!this->it.current_node)
				{
					it.current_node = it.p->first();
					first = it.current_node->pair->first;
					second = it.current_node->pair->second;
				}
				else
					it++;
				return copy;
			}

			friend bool operator==(const reverse_map_iterator &lhs, const reverse_map_iterator &rhs) {
				return lhs.it.current_node == rhs.it.current_node;
			}
			friend bool operator!=(const reverse_map_iterator &lhs, const reverse_map_iterator &rhs) {
				return lhs.it.current_node != rhs.it.current_node;
			}
			friend bool operator<(const reverse_map_iterator &lhs, const reverse_map_iterator &rhs) {
				return lhs.it.current_node < rhs.it.current_node;
			}
			friend bool operator>(const reverse_map_iterator &lhs, const reverse_map_iterator &rhs) {
				return lhs.it.current_node > rhs.it.current_node;
			}
			friend bool operator>=(const reverse_map_iterator &lhs, const reverse_map_iterator &rhs) {
				return lhs.it.current_node >= rhs.it.current_node;
			}
			friend bool operator<=(const reverse_map_iterator &lhs, const reverse_map_iterator &rhs) {
				return lhs.it.current_node <= rhs.it.current_node;
			}
			
			reverse_map_iterator<InputIt, T> *operator->(){
				return this;
			}
	};
}

#endif