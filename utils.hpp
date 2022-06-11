/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/11 12:42:17 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

#include <memory>
#include <exception>
#include <stdexcept>

namespace ft{

	
	//////ITERATOR TRAITS//////
	template<class Iterator>
	struct iterator_traits{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
	template<class T>
	struct iterator_traits<T *>{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<T* const>{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	//////ENABLE IF//////
	template< bool B, class T = void>
	struct enable_if {};
	
	template< class T>
	struct enable_if<true, T> {
		typedef T type;
	};


	//////IS INTEGRAL//////
	template<class T, T v>
	struct integral_constant {
		const static T value = v;
		typedef T value_type;
		typedef integral_constant	type ;
	};

	typedef integral_constant<bool, true>  true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T> struct is_integral : public false_type{};

	template <> struct is_integral<bool>               : public true_type {};
	template <> struct is_integral<char>               : public true_type {};
	template <> struct is_integral<signed char>        : public true_type {};
	template <> struct is_integral<unsigned char>      : public true_type {};
	template <> struct is_integral<wchar_t>            : public true_type {};
	template <> struct is_integral<short>              : public true_type {};
	template <> struct is_integral<unsigned short>     : public true_type {};
	template <> struct is_integral<int>                : public true_type {};
	template <> struct is_integral<unsigned int>       : public true_type {};
	template <> struct is_integral<long>               : public true_type {};
	template <> struct is_integral<unsigned long>      : public true_type {};
	template <> struct is_integral<long long>          : public true_type {};
	template <> struct is_integral<unsigned long long> : public true_type {};
}



#endif