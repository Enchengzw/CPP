/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:05:42 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/05 18:03:41 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Span.hpp"

Span::Span() {
}

Span::Span(unsigned int n) : _size(n) {
}

Span::Span(const Span& other) : _vector(other._vector), _size(other._size) {
	*this = other;
}

Span::~Span() {
}

Span& Span::operator=(const Span& other) {
	if (this == &other) return *this;
	this->_size = other._size;
	this->_vector = other._vector;
	return *this;
}

void Span::addNumber(int n) {
	if (this->_vector.size() == this->_size) {
		throw Span::FullException();
	}
	this->_vector.push_back(n);
}

void Span::addRange(IT begin, IT end) {
	if (this->_vector.size() + std::distance(begin, end) > this->_size) {
		throw Span::FullException();
	}
	this->_vector.insert(this->_vector.end(), begin, end);
}

std::size_t Span::size() const {
	return this->_size;
}

unsigned int Span::shortestSpan() const {
	if (this->_size < 2 || this->_vector.size() < 2) 
        throw Span::SmallException();
    std::vector<int> tmp = this->_vector;
    int max = *std::max_element(tmp.begin(), tmp.end());
    tmp.erase(std::max_element(tmp.begin(), tmp.end()));
    int new_max = *std::max_element(tmp.begin(), tmp.end());
    return  (max - new_max);
}

unsigned int Span::longestSpan() const {
	if (this->_size < 2 || this->_vector.size() < 2) throw Span::SmallException();
	return *std::max_element(this->_vector.begin(), this->_vector.end())
		- *std::min_element(this->_vector.begin(), this->_vector.end());
}

const char* Span::FullException::what() const throw() {
	return "Span is full";
}

const char* Span::SmallException::what() const throw() {
	return "Span is too small";
}