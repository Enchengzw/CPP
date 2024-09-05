/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:48:41 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/05 12:54:26 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/easyfind.hpp"

int main() 
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; ++i) 
		v.push_back(i);
	
	it = easyfind(v, 9);
	if (it == v.end()) std::cout << "Not found" << std::endl;
	else std::cout << "iterator: " << *it << std::endl;

	it = easyfind(v, 25);
	if (it == v.end()) std::cout << "Not found" << std::endl;
	else std::cout << "iterator: " << *it << std::endl;

	return 0;
}