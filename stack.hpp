/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/14 21:40:21 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_H
# define STACK_H

#include <memory>
#include <exception>
#include <stdexcept>
#include "vector.hpp"
#include "map.hpp"

namespace ft{
	template< class T,class Container = ft::vector<T> > class stack{
		public:
			typedef	Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			explicit stack( const Container& cont = Container() ) : c(cont){}
			stack( const stack& other ) : c(other.c) {}
			virtual ~stack(){}

			stack &operator=(stack const &other) {
				this->container = other.container;
				return (*this);
			}

			bool empty(void) const {
				return (this->c.empty());
			}
			size_t size(void) const {
				return (this->c.size());
			}

			reference top(void) {
				return (this->c.back());
			}
			const_reference top(void) const {
				return (this->c.back());
			}

			void push(const_reference val) {
				this->c.push_back(val);
			}
			void pop(void) {
				this->c.pop_back();
			}

			template<typename stack_type, typename container_type>
			friend bool operator==(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.c == rhs.c);
			}

			template<typename stack_type, typename container_type>
			friend bool operator!=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.c != rhs.c);
			}

			template<typename stack_type, typename container_type>
			friend bool operator<(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.c < rhs.c);
			}

			template<typename stack_type, typename container_type>
			friend bool operator<=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.c <= rhs.c);
			}

			template<typename stack_type, typename container_type>
			friend bool operator>(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.c > rhs.c);
			}

			template<typename stack_type, typename container_type>
			friend bool operator>=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.c >= rhs.c);
			}

		protected:
			Container c;
	};
}

#endif
