/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: encheng <encheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:12:04 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/03 18:28:21 by encheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& max(const T& x, const T& y) {
	if (x > y) return x;
	return y;
}

template<typename T>
const T& min(const T& x, const T& y) {
	if (x < y) return x;
	return y;
}

#endif