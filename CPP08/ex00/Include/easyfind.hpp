/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:47:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/05 12:48:23 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

template<typename T>

typename T::iterator easyfind(T& container, int to_find) 
{
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	return it;
}

#endif