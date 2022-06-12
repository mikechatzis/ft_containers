/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/12 19:22:40 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_H
# define VECTOR_H

#include <memory>
#include <exception>
#include <stdexcept>
#include "utils.hpp"
#include <iostream>
// #include <string>
// #include <limits>
// #include <iterator>
// #include <stdio.h>
// #include <unistd.h>

namespace ft
{
	class bidirectional_iterator_tag;
	class random_access_iterator_tag;
}

template <typename T> class vector_iterator
{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
		
		vector_iterator();
		vector_iterator(T *ptr);
		vector_iterator(const vector_iterator &other);
		~vector_iterator(){};
		
		vector_iterator &operator=(const vector_iterator &other);
		reference operator*(void) const;
		pointer operator->(void) const;
		vector_iterator &operator++();
		vector_iterator &operator--();
		vector_iterator operator++(int dummy);
		vector_iterator operator--(int dummy);
		vector_iterator &operator+=(const difference_type &offset);
		vector_iterator &operator-=(const difference_type &offset);
		vector_iterator operator+(difference_type offset) const;
		vector_iterator operator-(difference_type offset) const;

		bool operator==(const vector_iterator &rhs) const;
		bool operator!=(const vector_iterator &rhs) const;

		pointer p;
};

template <typename T> vector_iterator<T>::vector_iterator() : p(NULL) {}

template <typename T> vector_iterator<T>::vector_iterator(T *ptr) : p(ptr) {}

template <typename T> vector_iterator<T>::vector_iterator(const vector_iterator &other)
{
	*this = other;
}

template <typename T> vector_iterator<T> &vector_iterator<T>::operator=(const vector_iterator &other)
{
	this->p = other.p;
	return *this;
}

template <typename T>
typename vector_iterator<T>::reference vector_iterator<T>::operator*(void) const
{
    return *(this->p);
}

template <typename T>
typename vector_iterator<T>::pointer vector_iterator<T>::operator->(void) const
{
    return this->p;
}

template <typename T>
vector_iterator<T> &vector_iterator<T>::operator++()
{
    p++;
    return (*this);
}

template <typename T>
vector_iterator<T> &vector_iterator<T>::operator--()
{
    p--;
    return (*this);
}

template <typename T>
vector_iterator<T> vector_iterator<T>::operator++(int dummy)
{
    (void)dummy;
    vector_iterator<T> copy = *this;
    this->p++;
    return (copy);
}

template <typename T>
vector_iterator<T> vector_iterator<T>::operator--(int dummy)
{
    (void)dummy;
    vector_iterator<T> copy = *this;
    this->p--;
    return (copy);
}

template <typename T>
bool vector_iterator<T>::operator==(const vector_iterator &rhs) const
{
    return this->p == rhs.p;
}

template <typename T>
bool vector_iterator<T>::operator!=(const vector_iterator &rhs) const
{
    return this->p != rhs.p;
}

template <typename T>
vector_iterator<T> &vector_iterator<T>::operator+=(const difference_type &offset)
{
    this->p += offset;
    return (*this);
}

template <typename T>
vector_iterator<T> &vector_iterator<T>::operator-=(const difference_type &offset)
{
    this->p -= offset;
    return (*this);
}

template <typename T>
vector_iterator<T> vector_iterator<T>::operator+(difference_type offset) const
{
    vector_iterator copy(*this);

    copy.p += offset;

    return (copy);
}

template <typename T>
vector_iterator<T> vector_iterator<T>::operator-(difference_type offset) const
{
    vector_iterator copy(*this);

    copy.p -= offset;

    return (copy);
}

template <typename T>
typename vector_iterator<T>::difference_type operator-(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p - rhs.p;
}

template <typename T>
bool operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p < rhs.p;
}

template <typename T>
bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p <= rhs.p;
}

template <typename T>
bool operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p > rhs.p;
}
template <typename T>
bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p >= rhs.p;
}

template <typename T>
bool operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p == rhs.p;
}

template <typename T>
bool operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p != rhs.p;
}

//REVERSE ITERATOR TEMPLATE

template <class Iterator>
class reverse_vector_iterator
{
public:
    typedef Iterator iterator_type;
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;

    explicit reverse_vector_iterator(iterator_type it);
    template <class Iter>
    reverse_vector_iterator(const reverse_vector_iterator<Iter> &rev_it);
    reverse_vector_iterator();
    ~reverse_vector_iterator();

    reverse_vector_iterator &operator=(const reverse_vector_iterator &rhs);

    iterator_type base() const;

    reference operator*() const;
    reverse_vector_iterator &operator++();
    reverse_vector_iterator operator++(int);
    reverse_vector_iterator &operator--();
    reverse_vector_iterator operator--(int);
    reverse_vector_iterator operator+(difference_type n) const;
    reverse_vector_iterator &operator+=(difference_type n);
    reverse_vector_iterator operator-(difference_type n) const;
    reverse_vector_iterator &operator-=(difference_type n);
    reference operator[](difference_type n) const;

    pointer operator->() const;

private:
    iterator_type it;
};

template <class Iterator>
reverse_vector_iterator<Iterator>::reverse_vector_iterator() : it()
{
}

template <class Iterator>
reverse_vector_iterator<Iterator>::reverse_vector_iterator(iterator_type it) : it(it)
{
}

template <class Iterator>
template <class Iter>
reverse_vector_iterator<Iterator>::reverse_vector_iterator(const reverse_vector_iterator<Iter> &rev_it) : it(rev_it.it)
{
}

template <class Iterator>
reverse_vector_iterator<Iterator>::~reverse_vector_iterator()
{
}

template <class Iterator>
typename reverse_vector_iterator<Iterator>::iterator_type reverse_vector_iterator<Iterator>::base() const
{
    return it;
}

template <class Iterator>
reverse_vector_iterator<Iterator>	&reverse_vector_iterator<Iterator>::operator=(const reverse_vector_iterator &rhs)
{
    if (this != &rhs)
    {
        this->it = rhs.it;
    }
    return (*this);
};

template <class Iterator>
typename reverse_vector_iterator<Iterator>::reference reverse_vector_iterator<Iterator>::operator*() const
{
    Iterator itCopy(this->it);

    itCopy--;
    return (*itCopy);
}

template <class Iterator>
typename reverse_vector_iterator<Iterator>::pointer reverse_vector_iterator<Iterator>::operator->() const
{
    Iterator itCopy(this->it);

    itCopy--;
    return (itCopy.operator->());
}

template <class Iterator>
reverse_vector_iterator<Iterator>	&reverse_vector_iterator<Iterator>::operator++()
{
    it--;
    return (*this);
}

template <class Iterator>
reverse_vector_iterator<Iterator>	reverse_vector_iterator<Iterator>::operator++(int)
{
    reverse_vector_iterator tmp(*this);

    ++(*this);
    return (tmp);
}

template <class Iterator>
reverse_vector_iterator<Iterator>	&reverse_vector_iterator<Iterator>::operator--()
{
    it++;
    return (*this);
}

template <class Iterator>
reverse_vector_iterator<Iterator>	reverse_vector_iterator<Iterator>::operator--(int)
{
    reverse_vector_iterator tmp(*this);

    --(*this);
    return (tmp);
}

template <class Iterator>
reverse_vector_iterator<Iterator>	reverse_vector_iterator<Iterator>::operator+(difference_type n) const
{
    return (reverse_vector_iterator<Iterator>(it - n));
}

template <class Iterator>
reverse_vector_iterator<Iterator>	&reverse_vector_iterator<Iterator>::operator+=(difference_type n)
{
    it -= n;
    return (*this);
}

template <class Iterator>
reverse_vector_iterator<Iterator>	reverse_vector_iterator<Iterator>::operator-(difference_type n) const
{
    return (reverse_vector_iterator<Iterator>(it + n));
}

template <class Iterator>
reverse_vector_iterator<Iterator>	&reverse_vector_iterator<Iterator>::operator-=(difference_type n)
{
    it += n;
    return (*this);
}

template <class Iterator>
typename reverse_vector_iterator<Iterator>::reference reverse_vector_iterator<Iterator>::operator[](difference_type n) const
{
    return *((*this) + n);
}

template <class Iterator>
bool operator==(const reverse_vector_iterator<Iterator> &lhs,
                const reverse_vector_iterator<Iterator> &rhs)
{
    return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator!=(const reverse_vector_iterator<Iterator> &lhs,
                const reverse_vector_iterator<Iterator> &rhs)
{
    return lhs.base() != rhs.base();
}

template <class Iterator>
bool operator<(const reverse_vector_iterator<Iterator> &lhs,
               const reverse_vector_iterator<Iterator> &rhs)
{
    return lhs.base() > rhs.base();
}

template <class Iterator>
bool operator<=(const reverse_vector_iterator<Iterator> &lhs,
                const reverse_vector_iterator<Iterator> &rhs)
{
    return lhs.base() >= rhs.base();
}

template <class Iterator>
bool operator>(const reverse_vector_iterator<Iterator> &lhs,
               const reverse_vector_iterator<Iterator> &rhs)
{
    return lhs.base() < rhs.base();
}

template <class Iterator>
bool operator>=(const reverse_vector_iterator<Iterator> &lhs,
                const reverse_vector_iterator<Iterator> &rhs)
{
    return lhs.base() <= rhs.base();
}

template <class Iterator>
typename reverse_vector_iterator<Iterator>::reverse_vector_iterator operator+(
    typename reverse_vector_iterator<Iterator>::difference_type n,
    const reverse_vector_iterator<Iterator> &rev_it)
{
    return (rev_it + n);
}

template <class Iterator>
typename reverse_vector_iterator<Iterator>::difference_type operator-(
    const reverse_vector_iterator<Iterator> &lhs,
    const reverse_vector_iterator<Iterator> &rhs)
{
    return (rhs.base() - lhs.base());
}

/**/
namespace ft
{
	template < typename T, class Allocator = std::allocator<T> > class vector
	{
		public:
			typedef T value_type;
			typedef vector_iterator<T> iterator;
			typedef vector_iterator<const T> const_iterator;
			typedef reverse_vector_iterator<iterator> reverse_iterator;
			typedef reverse_vector_iterator<const_iterator> const_reverse_iterator;
			typedef T &reference;
			typedef std::allocator<T> allocator_type;
			typedef const T &const_reference;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;

			//CONSTRUCTORS
			explicit vector (const allocator_type& alloc = allocator_type()) : arr_(NULL), size_(0), capacity_(0) {
				this->Alloc_ = std::allocator<T>(alloc);
			}
			
			explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : size_(n), capacity_(0) {
				this->Alloc_ = std::allocator<T>(alloc);
				this->arr_ = this->Alloc_.allocate(n);
				for (size_t i = 0; i < n; i++)
					this->Alloc_.construct(&arr_[i], val);
			}
			
			vector (const vector &other) : size_(other.size_), capacity_(other.capacity_) {
				this->Alloc_ = std::allocator<T>(other.Alloc_);
				this->arr_ = this->Alloc_.allocate(this->size_ + this->capacity_);
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.construct(&arr_[i], other.arr_[i]);
			}
			
			template <typename InputIterator>
			explicit vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			: size_(0), capacity_(0) {
				this->Alloc_ = std::allocator<T>(alloc);
				InputIterator tmp1 = first;
				while(tmp1++ != last)
					this->size_++;
				this->arr_ = this->Alloc_.allocate(this->size_);
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.construct(&arr_[i], *first++);
			}
			
			//DESTRUCTOR
			~vector(){
				if (this->arr_)
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
			}
			

			//////DEBUG//////
			void print(){
				if (!this->arr_)
				{
					std::cout << "vector empty";
				}
				for (size_t i = 0; i < this->size_; i++)
					std::cout << this->arr_[i] << " ";
				std::cout << std::endl;
			}
			/////

			//OPERATORS
			vector &operator=(vector const &other){
				this->Alloc_ = std::allocator<T>(other.Alloc_);
				this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
				this->size_ = other.size_;
				this->capacity_ = other.capacity_;
				this->arr_ = this->Alloc_.allocate(this->size_ + this->capacity_);
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.construct(&arr_[i], other.arr_[i]);
				return *this;
			}

			reference operator[] (size_type n){
				return this->arr_[n];
			}

			const_reference operator[] (size_type n) const {
				return this->arr_[n];
			}

			///////////

			//CAPACITY
			size_type size() const {
				return this->size_;
			}

			size_type capacity() const {
				return this->size_ + this->capacity_;
			}

			void resize (size_type n, value_type val = value_type()){
				if (n < this->size_)
				{
					T tmp[n];
					for (size_t i = 0; i < n; i++)
						tmp[i] = this->arr_[i];
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&arr_[i], tmp[i]);
				}
				else if (n > this->size_)
				{
					T tmp[n];
					for (size_t i = 0; i < this->size_; i++)
						tmp[i] = this->arr_[i];
					for (size_t i = this->size_; i < n; i++)
						tmp[i] = val;
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&arr_[i], tmp[i]);
				}
				this->size_ = n;
			}

			bool empty() const {
				return !this->arr_ && !this->size_;
			}

			size_type max_size() const {
				return this->Alloc_.max_size();
			}
			
			void reserve (size_type n) {
				if (n > this->max_size())
					throw std::out_of_range("ft::vector");

				if (this->capacity() >= n)
					return;

				T tmp[this->size_];
				for (size_t i = 0; i < this->size_; i++)
					tmp[i] = this->arr_[i];
				this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
				this->arr_ = this->Alloc_.allocate(n);
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.construct(&arr_[i], tmp[i]);
				this->capacity_ = n - this->size_;
			}

			////////////

			reference at (size_type n){
				if (n > this->capacity() - 1 || !this->arr_)
					throw std::out_of_range("ft::vector");
				
				return this->arr_[n];
			}

			const_reference at (size_type n) const{
				if (n > this->capacity() - 1 || !this->arr_)
					throw std::out_of_range("ft::vector");
				
				return this->arr_[n];
			}

			reference front(){
				return this->arr_[0];
			}
			const_reference front() const{
				return this->arr_[0];
			}

			reference back(){
				return this->arr_[this->size_ - 1];
			}
			const_reference back() const{
				return this->arr_[this->size_ - 1];
			}

			//ITERATOR FUNCTIONS
			
			iterator begin(){
				return iterator(this->arr_);
			}
			const_iterator begin() const{
				return const_iterator(this->arr_);
			}

			iterator end(){
				return iterator(this->arr_ + this->size_);
			}
			const_iterator end() const{
				return const_iterator(this->arr_ + this->size_);
			}

			reverse_iterator rend(){
				return reverse_iterator(iterator(this->arr_));
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(iterator(this->arr_));
			}

			reverse_iterator rbegin(){
				return reverse_iterator(iterator(this->arr_ + this->size_));
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(iterator(this->arr_ + this->size_));
			}
			
			//CONTENT MOD FUNCTIONS

			void clear(){
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.destroy(&this->arr_[i]);
				this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
				this->arr_ = NULL;
				this->size_ = 0;
				this->capacity_ = 0;
			}

			iterator erase (iterator position){
				T tmp[this->size_];
				size_t retpos;
				size_t j = 0;
				for (iterator i = this->begin(); i != this->end(); i++)
				{
					if (i == position)
						retpos = j; 
					else
						tmp[j++] = *i;
				}
				this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
				this->arr_ = this->Alloc_.allocate(j);
				for (size_t i = 0; i < j; i++)
					this->Alloc_.construct(&arr_[i], tmp[i]);
				this->size_ = j;
				return iterator(&this->arr_[retpos]);
			}
			iterator erase (iterator first, iterator last){
				T tmp[this->size_];
				size_t retpos;
				size_t j = 0;
				for (iterator i = this->begin(); i != this->end(); i++)
				{
					if (i == first)
					{
						retpos = j;
						i = last - 1;
					}
					else
						tmp[j++] = *i;
				}
				this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
				this->arr_ = this->Alloc_.allocate(j);
				for (size_t i = 0; i < j; i++)
					this->Alloc_.construct(&arr_[i], tmp[i]);
				this->size_ = j;
				return iterator(&this->arr_[retpos]);
			}
			
			void swap (vector& x){
				T *tmp;
				
				size_t tmpsize = this->size_;
				this->size_ = x.size_;
				x.size_ = tmpsize;
				
				size_t tmpcapacity = this->capacity_;
				this->capacity_ = x.capacity_;
				x.capacity_ = tmpcapacity;
				
				tmp = this->arr_;
				this->arr_ = x.arr_;
				x.arr_ = tmp;
			}

			void assign (size_type n, const value_type& val){
				if (!this->arr_)
					this->arr_ = this->arr_ = this->Alloc_.allocate(n);
				if (n <= this->capacity())
				{
					for (size_t i = 0; i < this->size_; i++)
						this->Alloc_.destroy(&this->arr_[i]);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&this->arr_[i], val);
					this->capacity_ = this->capacity() - n;
					this->size_ = n;
				}
				else
				{
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&this->arr_[i], val);
					this->capacity_ = 0;
					this->size_ = n;
				}
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_t j = 0;
					for (InputIterator i = first; i != last; i++)
						j++;
				if (!this->arr_)
					this->arr_ = this->Alloc_.allocate(j);
				if (j <= this->capacity())
				{
					j = 0;
					for (size_t i = 0; i < this->size_; i++)
						this->Alloc_.destroy(&this->arr_[i]);
					for (InputIterator i = first; i != last; i++)
						this->Alloc_.construct(&this->arr_[j++], *i);
					this->capacity_ = this->capacity() - j;
					this->size_ = j;
				}
				else
				{
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->capacity_ = 0;
					this->size_ = j;
					this->arr_ = this->Alloc_.allocate(j);
					for (size_t i = 0; i < j; i++)
						this->Alloc_.construct(&this->arr_[i], *first++);
				}
			}

			iterator insert (iterator position, const value_type& val){
				if (!this->arr_)
					this->arr_ = this->arr_ = this->Alloc_.allocate(this->size_ + 1);
				if (this->size_ + 1 <= this->capacity())
				{
					for (iterator i = this->end(); i != position; i--)
					{
						this->Alloc_.construct(&(*i), *(i - 1));
						this->Alloc_.destroy(&(*(i - 1)));
					}
					this->Alloc_.construct(&*(position), val);
					this->size_ += 1;
					this->capacity_ -= 1;
				}
				else
				{
					size_t pos = 0;
					T tmp[this->size_ + 1];
					size_t j = 0;
					for (iterator i = this->begin(); i != this->end(); i++)
					{
						if (i != position)
							tmp[j] = *i;
						else
						{
							pos = j;
							tmp[j++] = val;
							tmp[j] = *i;
						}
						j++;
					}
					if (position == this->end())
					{
						pos = j;
						tmp[j] = val;
					}
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(this->size_ + 1);
					for (size_t i = 0; i < this->size_ + 1; i++)
						this->Alloc_.construct(&this->arr_[i], tmp[i]);
					this->capacity_ = 0;
					this->size_++;
					return iterator(&this->arr_[pos]);
				}
				return iterator(&*(position));
			}

			void insert (iterator position, size_type n, const value_type& val){
				if (!this->arr_)
					this->arr_ = this->arr_ = this->Alloc_.allocate(this->size_ + n);
				if (this->size_ + n <= this->capacity())
				{
					for (iterator i = this->end(); i != position; i--)
					{
						this->Alloc_.construct(&(*(i + n - 1)), *(i - 1));
						this->Alloc_.destroy(&(*(i - 1)));
					}
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&*(position + i), val);
					this->size_ += n;
					this->capacity_ -= n;
				}
				else
				{
					T tmp[this->size_ + n];
					size_t j = 0;
					for (iterator i = this->begin(); i != this->end(); i++)
					{
						if (i != position)
							tmp[j] = *i;
						else
						{
							for (size_t i = 0; i < n; i++)
								tmp[j++] = val;
							tmp[j] = *i;
						}
						j++;
					}
					if (position == this->end())
						for (size_t i = 0; i < n; i++)
								tmp[j++] = val;
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(this->size_ + n);
					for (size_t i = 0; i < this->size_ + n; i++)
						this->Alloc_.construct(&this->arr_[i], tmp[i]);
					this->capacity_ = 0;
					this->size_ += n;
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_t j = 0;
				for (InputIterator i = first; i != last; i++)
					j++;
				if (!this->arr_)
					this->arr_ = this->arr_ = this->Alloc_.allocate(this->size_ + j);
				if (this->size_ + j <= this->capacity())
				{
					for (iterator i = this->end(); i != position; i--)
					{
						this->Alloc_.construct(&(*(i + j - 1)), *(i - 1));
						this->Alloc_.destroy(&(*(i - 1)));
					}
					for (size_t i = 0; i < j; i++)
						this->Alloc_.construct(&*(position + i), *first++);
					this->size_ += j;
					this->capacity_ -= j;
				}
				else
				{
					T tmp[this->size_ + j];
					size_t k = 0;
					for (iterator i = this->begin(); i != this->end(); i++)
					{
						if (i != position)
							tmp[k] = *i;
						else
						{
							for (size_t i = 0; i < j; i++)
								tmp[k++] = *first++;
							tmp[k] = *i;
						}
						k++;
					}
					if (position == this->end())
						for (size_t i = 0; i < j; i++)
								tmp[k++] = *first++;
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(this->size_ + j + 1);
					for (size_t i = 0; i < this->size_ + j; i++)
						this->Alloc_.construct(&this->arr_[i], tmp[i]);
					this->capacity_ = 0;
					this->size_ += j;
				}
			}

			void pop_back(){
				if (!this->arr_)
					return;
				this->Alloc_.destroy(&(*(this->end() - 1)));
				this->size_--;
				this->capacity_++;
			}

			void push_back (const value_type& val){
				this->insert(this->end(), val);
			}

		private:
			T *arr_;
			size_type size_;
			size_type capacity_;
			allocator_type Alloc_;
	};

	template <typename T>
	void swap(ft::vector<T> &x, ft::vector<T> &y)
	{
		x.swap(y);
	}
}

// template< typename T, class Allocator = std::allocator<T> > vector::vector(const allocator_type &alloc)
// {
// 	this->arr = alloc.allocate(0);
// }

#endif