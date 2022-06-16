/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:13:38 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/16 09:43:22 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATORS_H
# define MAP_ITERATORS_H

#include <memory>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "map.hpp"


namespace ft
{
	template<typename T1, typename T2> class pair;
	template<typename Key, typename T, class allocator, class Compare > class tree;
	template<class Key,class T,class Compare,class Allocator>
	class map;

	class bidirectional_iterator_tag;
	class random_access_iterator_tag;

	template <typename T> class map_iterator
		public:
			T *p;
			typename T::NODE current_node;

			typedef T object_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename T::value_type value_type;
			typedef typename T::value_type& reference;
			typedef const typename T::value_type& const_reference;
			typedef typename std::allocator<value_type>::pointer pointer;
			typedef typename std::allocator<value_type>::const_pointer const_pointer;
			typedef ft::bidirectional_iterator_tag iterator_category;
			

			map_iterator() : p(NULL), current_node(NULL){}
			map_iterator(T *ptr) : p(ptr), current_node(&(p->get_root())) {	}
			map_iterator(T const *ptr) : p(ptr), current_node(&(p->get_root())) {}
			map_iterator(T *ptr, typename T::NODE n) : p(ptr), current_node(n){}
			map_iterator(T const *ptr, typename T::NODE n) : p(ptr), current_node(n){}
			map_iterator(const map_iterator &other) : p(other.p), current_node(other.current_node){}
			~map_iterator(){};
			
			map_iterator &operator=(const map_iterator &other){
				p = other.p;
				current_node = other.current_node;
				return *this;
			}
			
			ft::pair<const typename T::key_type, typename T::mapped_type> &operator*() const{
				if (!current_node)
					return *(p->dummy);
				return *(current_node->pair);
			}
			
			map_iterator &operator++(){
				typename T::NODE root = &p->get_root();
				typename T::NODE suc = NULL;
				p->next(root, suc, current_node);
				current_node = suc;
				return *this;
			}
			map_iterator &operator--(){
				if (!this->current_node)
					current_node = p->last();
				else
				{	typename T::NODE root = &p->get_root();
					typename T::NODE pre = NULL;
					p->prev(root, pre, current_node);
					current_node = pre;
				}
				return *this;
			}
			map_iterator operator++(int dummy){
				(void)dummy;
				map_iterator<T> copy = *this;
				typename T::NODE root = &p->get_root();
				typename T::NODE suc = NULL;
				p->next(root, suc, current_node);
				current_node = suc;
				return copy;
			}
			map_iterator operator--(int dummy){
				(void)dummy;
				map_iterator<T> copy = *this;
				if (!this->current_node)
					current_node = p->last();
				else
				{	typename T::NODE root = &p->get_root();
					typename T::NODE pre = NULL;
					p->prev(root, pre, current_node);
					current_node = pre;
				}
				return copy;
			}


			typename T::value_type *operator->(){
				if (!current_node)
					return p->dummy;
				return current_node->pair;
			}
			const typename T::value_type *operator->() const{
				if (!current_node)
					return p->dummy;
				return current_node->pair;
			}
			
			
			friend bool operator==(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
				return lhs.current_node == rhs.current_node;
			}
			friend bool operator!=(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
				return lhs.current_node != rhs.current_node;
			}
			friend bool operator<(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
				return lhs.current_node < rhs.current_node;
			}
			friend bool operator>(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
				return lhs.current_node > rhs.current_node;
			}
			friend bool operator>=(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
				return lhs.current_node >= rhs.current_node;
			}
			friend bool operator<=(const map_iterator<T> &lhs, const map_iterator<T> &rhs) {
				return lhs.current_node <= rhs.current_node;
			}
	};

	
	template<class InputIt> class reverse_map_iterator {
		private:
			InputIt it;
		public:

			typedef InputIt iterator_type;
			typedef typename InputIt::object_type object_type;
			typedef typename InputIt::iterator_category iterator_category;
			typedef typename InputIt::value_type value_type;
			typedef typename InputIt::difference_type difference_type;
			typedef typename InputIt::pointer pointer;
			typedef typename InputIt::reference reference;

			reverse_map_iterator() : it() {}
			reverse_map_iterator(object_type *ptr) : it(ptr) {}
			reverse_map_iterator(object_type const *ptr) : it(ptr) {}
			reverse_map_iterator(object_type *ptr, typename object_type::NODE n) : it(ptr, n) {}
			reverse_map_iterator(object_type const *ptr, typename object_type::NODE n) : it(ptr, n) {}
			reverse_map_iterator(const reverse_map_iterator &other) : it(other.it) {}
			~reverse_map_iterator(){};

			reverse_map_iterator &operator=(const reverse_map_iterator &other){
				this->it = other.it;
				return *this;
			}

			ft::pair<const typename object_type::key_type, typename object_type::mapped_type> &operator*(void) const{
				if (!it.current_node)
					return *(it.p->dummy);
				return *(it.current_node->pair);
			}

			reverse_map_iterator &operator++(){
				it--;
				return this;
			}

			reverse_map_iterator operator++(int dummy){
				(void)dummy;
				reverse_map_iterator copy = *this;
				it--;
				return copy;
			}

			reverse_map_iterator &operator--(){
				if (!this->it.current_node)
					it.current_node = it.p->first();
				else
					it++;
				return this;
			}

			reverse_map_iterator operator--(int dummy){
				(void)dummy;
				reverse_map_iterator copy = *this;
				if (!this->it.current_node)
					it.current_node = it.p->first();
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
			
			value_type *operator->(){
				if (!it.current_node)
					return it.p->dummy;
				return it.current_node->pair;
			}

			const value_type *operator->() const {
				if (!it.current_node)
					return it.p->dummy;
				return it.current_node->pair;
			}
	};
}

#endif
