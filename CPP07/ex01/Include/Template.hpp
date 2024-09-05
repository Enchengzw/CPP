/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: encheng <encheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:12:04 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/03 18:37:12 by encheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>
#include <string>
#include <cstddef>

template<typename T>
void iter(T* array, size_t size, void(*f)(const T)) {
    for (size_t i = 0; i < size; i++) {
        f(array[i]);
    }
}

#endif