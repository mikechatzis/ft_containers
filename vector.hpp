/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:03:07 by mchatzip          #+#    #+#             */
/*   Updated: 2022/06/17 23:01:17 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_H
# define VECTOR_H

#include <memory>
#include <exception>
#include <stdexcept>
#include "utils.hpp"
#include <iostream>

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
		
		vector_iterator(): p(NULL) {}
		vector_iterator(T *ptr) : p(ptr) {}
		vector_iterator(const vector_iterator &other){
			*this = other;
		}
		~vector_iterator(){};
		
		vector_iterator &operator=(const vector_iterator &other){
			this->p = other.p;
			return *this;
		}
		reference operator*(void) {
			return *(this->p);
		}
		const T &operator*(void) const {
			return *(p);
		}
		pointer operator->() {
			return this->p;
		}
		const pointer operator->() const {
			return this->p;
		}
		reference operator[](difference_type n){
			return *((*this) + n);
		}
		const T &operator[](difference_type n)const{
			return *((*this) + n);
		}
		vector_iterator &operator++(){
			p++;
			return (*this);
		}
		const vector_iterator &operator++() const {
			p++;
			return (*this);
		}
		vector_iterator &operator--(){
			p--;
			return (*this);
		}
		const vector_iterator &operator--() const {
			p--;
			return (*this);
		}
		vector_iterator operator++(int dummy){
			(void)dummy;
			vector_iterator<T> copy = *this;
			this->p++;
			return (copy);
		}
		const vector_iterator operator++(int dummy)const{
			(void)dummy;
			vector_iterator<T> copy = *this;
			this->p++;
			return (copy);
		}
		vector_iterator operator--(int dummy){
			(void)dummy;
			vector_iterator<T> copy = *this;
			this->p--;
			return (copy);
		}
		const vector_iterator operator--(int dummy)const{
			(void)dummy;
			vector_iterator<T> copy = *this;
			this->p--;
			return (copy);
		}
		vector_iterator &operator+=(const difference_type &offset){
			this->p += offset;
			return (*this);
		}
		const vector_iterator &operator+=(const difference_type &offset)const{
			this->p += offset;
			return (*this);
		}
		vector_iterator &operator-=(const difference_type &offset){
			this->p -= offset;
			return (*this);
		}
		const vector_iterator &operator-=(const difference_type &offset)const{
			this->p -= offset;
			return (*this);
		}
		vector_iterator operator+(difference_type offset){
			vector_iterator copy(*this);

			copy.p += offset;

			return (copy);
		}
		const vector_iterator operator+(difference_type offset)const{
			vector_iterator copy(*this);

			copy.p += offset;

			return (copy);
		}
		vector_iterator operator-(difference_type offset){
			vector_iterator copy(*this);

			copy.p -= offset;

			return (copy);
		}
		const vector_iterator operator-(difference_type offset)const{
			vector_iterator copy(*this);

			copy.p -= offset;

			return (copy);
		}
		bool operator==(const vector_iterator &rhs) const {
			return this->p == rhs.p;
		}
		bool operator!=(const vector_iterator &rhs) const{
			return this->p != rhs.p;
		}

		mutable pointer p;
};

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
bool operator<(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)
{
    return lhs.p < rhs.p;
}

template <typename T>
bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p <= rhs.p;
}

template <typename T>
bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)
{
    return lhs.p <= rhs.p;
}

template <typename T>
bool operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p > rhs.p;
}

template <typename T>
bool operator>(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)
{
    return lhs.p > rhs.p;
}

template <typename T>
bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p >= rhs.p;
}

template <typename T>
bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)
{
    return lhs.p >= rhs.p;
}

template <typename T>
bool operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p == rhs.p;
}

template <typename T>
bool operator==(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)
{
    return lhs.p == rhs.p;
}

template <typename T>
bool operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
{
    return lhs.p != rhs.p;
}

template <typename T>
bool operator!=(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)
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

    explicit reverse_vector_iterator(iterator_type it): it(it) {}
    template <class Iter>
    reverse_vector_iterator(const reverse_vector_iterator<Iter> &rev_it) : it(rev_it.it){}
    reverse_vector_iterator() : it(){}
    ~reverse_vector_iterator(){}

    reverse_vector_iterator &operator=(const reverse_vector_iterator &rhs){
		if (this != &rhs)
		{
			this->it = rhs.it;
		}
		return (*this);
	}

    iterator_type base() const{
		return it;
	}

    reference operator*() {
		Iterator itCopy(this->it);

		itCopy--;
		return (*itCopy);
	}
	const value_type &operator*() const {
		Iterator itCopy(this->it);

		itCopy--;
		return (*itCopy);
	}
    reverse_vector_iterator &operator++(){
		it--;
		return (*this);
	}
	const reverse_vector_iterator &operator++()const{
		it--;
		return (*this);
	}
    reverse_vector_iterator operator++(int){
		reverse_vector_iterator tmp(*this);

		++(*this);
		return (tmp);
	}
	const reverse_vector_iterator operator++(int)const{
		reverse_vector_iterator tmp(*this);

		++(*this);
		return (tmp);
	}
    reverse_vector_iterator &operator--(){
		it++;
		return (*this);
	}
	const reverse_vector_iterator &operator--()const{
		it++;
		return (*this);
	}
    reverse_vector_iterator operator--(int){
		reverse_vector_iterator tmp(*this);

		--(*this);
		return (tmp);
	}
	const reverse_vector_iterator operator--(int)const{
		reverse_vector_iterator tmp(*this);

		--(*this);
		return (tmp);
	}
    reverse_vector_iterator operator+(difference_type n){
		return (reverse_vector_iterator<Iterator>(it - n));
	}
	const reverse_vector_iterator operator+(difference_type n)const{
		return (reverse_vector_iterator<Iterator>(it - n));
	}
    reverse_vector_iterator &operator+=(difference_type n){
		it -= n;
		return (*this);
	}
	const reverse_vector_iterator &operator+=(difference_type n)const{
		it -= n;
		return (*this);
	}
    reverse_vector_iterator operator-(difference_type n){
		return (reverse_vector_iterator<Iterator>(it + n));
	}
	const reverse_vector_iterator operator-(difference_type n)const{
		return (reverse_vector_iterator<Iterator>(it + n));
	}
    reverse_vector_iterator &operator-=(difference_type n){
		it += n;
		return (*this);
	}
	const reverse_vector_iterator &operator-=(difference_type n)const{
		it += n;
		return (*this);
	}
    reference operator[](difference_type n){
		return *((*this) + n);
	}
	const value_type &operator[](difference_type n)const{
		return *((*this) + n);
	}
    pointer operator->() {
		Iterator itCopy(this->it);

		itCopy--;
		return (itCopy.operator->());
	}
	const pointer operator->() const {
		Iterator itCopy(this->it);

		itCopy--;
		return (itCopy.operator->());
	}

    iterator_type it;
};

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
			typedef const vector_iterator<T> const_iterator;
			typedef reverse_vector_iterator<iterator> reverse_iterator;
			typedef const reverse_vector_iterator<const_iterator> const_reverse_iterator;
			typedef T &reference;
			typedef T* pointer;
			typedef const T* const_pointer;
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
				this->capacity_ = 0;
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.construct(&arr_[i], *first++);
			}
			
			//DESTRUCTOR
			~vector(){
				if (this->arr_)
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
			}

			//OPERATORS
			vector &operator=(vector const &other){
				this->Alloc_ = std::allocator<T>(other.Alloc_);
				assign(other.begin(), other.end());
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
				if (!arr_){
					this->arr_ = this->Alloc_.allocate(n * 2);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&this->arr_[i], val);
					size_ = capacity_ = n;
					return;
				}
				if (n < this->size_)
				{
					for (size_t i = n; i < size_; i++)
						this->Alloc_.destroy(&arr_[i]);
				}
				else if (n > this->size_)
				{
					if (n > capacity()){
						size_t multi = 1;
						for	(; multi * size_ < n; multi++)
							continue;
						T *tmp = Alloc_.allocate(multi * size_);
						for (size_t i = 0; i < this->size_; i++)
							this->Alloc_.construct(&tmp[i], arr_[i]);
						for (size_t i = this->size_; i < n; i++)
							this->Alloc_.construct(&tmp[i], val);
						for (size_t i = 0; i < this->size_; i++)
							this->Alloc_.destroy(&arr_[i]);
						this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
						this->arr_ = tmp;
						capacity_ = multi * size_ - n;
					}
					else{
						for (size_t i = this->size_; i < n; i++)
							this->Alloc_.construct(&arr_[i], val);
						capacity_ -= n - size_;
					}
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

				T *tmp = Alloc_.allocate(n);
				for (size_t i = 0; i < this->size_; i++)
					this->Alloc_.construct(&tmp[i], arr_[i]);
				for (size_t i = 0; i < this->size_; i++)
						this->Alloc_.destroy(&arr_[i]);
				this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
				this->arr_ = tmp;
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
				capacity_ += size_;
				this->size_ = 0;
			}

			iterator erase (iterator position){
				pointer p_pos = &(*position);
				if (position + 1 == end())
					Alloc_.destroy(&(*position));
				else
				{
					while (position != end())
					{
						Alloc_.construct(&(*position), *(position + 1));
						Alloc_.destroy(&(*(position + 1)));
						position++;
					}
				}
				size_ -= 1;
				capacity_ += 1;
				return (iterator(p_pos));
			}
			iterator erase (iterator first, iterator last){
				pointer p_first = &(*first);
				size_type dist = 0;
				for (; &(*first) != &(*last); first++)
				{
					Alloc_.destroy(&(*first));
					dist++;
				}
				for (iterator i = iterator(p_first); last != end(); last++)
				{
					Alloc_.construct(&(*i), *last);
					Alloc_.destroy(&(*last));
					i++;
				}
				size_ -= dist;
				capacity_ += dist;
				return (iterator(p_first));
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
				if (!this->arr_){
					this->arr_ = this->Alloc_.allocate(n * 2);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&this->arr_[i], val);
					size_ = capacity_ = n;
					return;
				}
				if (n <= this->capacity())
				{
					for (size_t i = 0; i < this->size_; i++)
						this->Alloc_.destroy(&this->arr_[i]);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&this->arr_[i], val);
					this->capacity_ += size_ - n;
					this->size_ = n;
				}
				else
				{
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(n * 2);
					for (size_t i = 0; i < n; i++)
						this->Alloc_.construct(&this->arr_[i], val);
					this->capacity_ = n;
					this->size_ = n;
				}
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_t j = 0;
					for (InputIterator i = first; i != last; i++)
						j++;
				if (!this->arr_){
					size_t c = 0;
					this->arr_ = this->Alloc_.allocate(j * 2);
					for (InputIterator i = first; i != last; i++)
						this->Alloc_.construct(&this->arr_[c++], *i);
					size_ = capacity_ = j;
				}
				if (j <= this->capacity())
				{
					j = 0;
					for (size_t i = 0; i < this->size_; i++)
						this->Alloc_.destroy(&this->arr_[i]);
					for (InputIterator i = first; i != last; i++)
						this->Alloc_.construct(&this->arr_[j++], *i);
					this->capacity_ += size_ - j;
					this->size_ = j;
				}
				else
				{
					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					this->arr_ = this->Alloc_.allocate(j * 2);
					for (size_t i = 0; i < j; i++)
						this->Alloc_.construct(&this->arr_[i], *first++);
					capacity_ = j;
					size_ = j;
				}
			}

			iterator insert (iterator position, const value_type& val){
				if (!this->arr_){
					this->arr_ = this->Alloc_.allocate(2);
					Alloc_.construct(&arr_[0], val);
					size_ = 1;
					capacity_ = 1;
					return iterator(&arr_[0]);
				}

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
					T *tmp = Alloc_.allocate(size_ * 2);
					size_t j = 0;
					for (iterator i = this->begin(); i != position; i++)
							Alloc_.construct(&tmp[j++], *i);

					pos = j;
					Alloc_.construct(&tmp[j++], val);

					for (iterator i = position; i != end(); i++)
						Alloc_.construct(&tmp[j++], *i);

					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					arr_ = tmp;
					this->capacity_ = size_ * 2 - size_ - 1;
					this->size_++;
					return iterator(&this->arr_[pos]);
				} 
				return iterator(&*(position));
			}

			void insert (iterator position, size_type n, const value_type& val){
				if (!this->arr_){
					this->arr_ = this->Alloc_.allocate(n * 2);
					for (size_t i = 0; i < n; i++)
						Alloc_.construct(&arr_[i], val);
					capacity_ = 2*n - n;
					size_ += n;
					return;
				}

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
					T *tmp;
					size_t multi = 1;
					for (; n > multi*size_ ; multi++)
						continue;
					tmp = Alloc_.allocate(size_ * multi);
					
					size_t j = 0;
					for (iterator i = this->begin(); i != position; i++)
							Alloc_.construct(&tmp[j++], *i);

					for (size_t i = 0; i < n; i++)
						Alloc_.construct(&tmp[j++], val);

					for (iterator i = position; i != end(); i++)
						Alloc_.construct(&tmp[j++], *i);

					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					arr_ = tmp;
					capacity_ = size_ * multi - size_ - n;
					this->size_ += n;
				} 
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
				size_t j = 0;
				for (InputIterator i = first; i != last; i++)
					j++;
				if (!this->arr_){
					this->arr_ = this->Alloc_.allocate(2 * j);
					for (size_t i = 0; first != last; first++)
						Alloc_.construct(&arr_[i++], *first);
					size_ = j;
					capacity_ = 2 * j - j;
					return;
				}
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
					T *tmp;
					size_t t_c;
					if (j > size_){
						t_c = size_ * 4 - size_;
						tmp = Alloc_.allocate(size_ * 4);	
					}
					else{
						t_c = size_ * 2 - size_;
						tmp = Alloc_.allocate(size_ * 2);	
					}
					
					size_t d = 0;
					for (iterator i = this->begin(); i != position; i++)
							Alloc_.construct(&tmp[d++], *i);

					for (; first != last; first++)
						Alloc_.construct(&tmp[d++], *first);

					for (iterator i = position; i != end(); i++)
						Alloc_.construct(&tmp[d++], *i);

					this->Alloc_.deallocate(this->arr_, this->size_ + this->capacity_);
					arr_ = tmp;
					this->size_ += j;
					capacity_ = t_c - j;
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

	template <class T, class Alloc>
		bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			typename ft::vector<T>::const_iterator first1 = lhs.begin();
			typename ft::vector<T>::const_iterator first2 = rhs.begin();
			while (first1 != lhs.end())
			{
				if (first2 == rhs.end() || *first1 != *first2)
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}

	template <class T, class Alloc>
		bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}
	

	template <class T, class Alloc>
		bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}


	template <class T, class Alloc>
		bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

	
	template <class T, class Alloc>
		bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	
	template <class T, class Alloc>
		bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

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
