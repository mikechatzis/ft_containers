/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/12 17:16:04 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_H
# define STACK_H

#include <memory>
#include <exception>
#include <stdexcept>
#include "ft_vector.hpp"
#include "map.hpp"

namespace ft{
	template< class T,class Container = ft::vector<T> > class stack{
		public:
			typedef	Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			explicit stack( const Container& cont = Container() ) : cont(cont){}
			stack( const stack& other ) : cont(other.cont) {}
			virtual ~stack(){}

			stack &operator=(stack const &other) {
				this->container = other.container;
				return (*this);
			}

			bool empty(void) const {
				return (this->cont.empty());
			}
			size_t size(void) const {
				return (this->cont.size());
			}

			reference top(void) {
				return (this->cont.back());
			}
			const_reference top(void) const {
				return (this->cont.back());
			}

			void push(const_reference val) {
				this->cont.push_back(val);
			}
			void pop(void) {
				this->cont.pop_back();
			}

			template<typename stack_type, typename container_type>
			friend bool operator==(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.cont == rhs.cont);
			}

			template<typename stack_type, typename container_type>
			friend bool operator!=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.cont != rhs.cont);
			}

			template<typename stack_type, typename container_type>
			friend bool operator<(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.cont < rhs.cont);
			}

			template<typename stack_type, typename container_type>
			friend bool operator<=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.container <= rhs.container);
			}

			template<typename stack_type, typename container_type>
			friend bool operator>(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.cont > rhs.cont);
			}

			template<typename stack_type, typename container_type>
			friend bool operator>=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
				return (lhs.cont >= rhs.cont);
			}

		protected:
			Container cont;
	};
}


#endif