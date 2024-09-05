/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: encheng <encheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:33:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/03 19:00:29 by encheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Array.hpp"

#include <iostream>
#include <string>

int	main( void )
{
	Array<int>			intArray;
	Array<std::string>	stringArray(10);
	Array<std::string>	otherStringArray;

	stringArray[0] = "Hi";
	stringArray[1] = "Hello";
	stringArray[2] = "How are you?";
	stringArray[3] = "Fine and you?";
	stringArray[4] = "Doing great thanks!";
	stringArray[5] = "You're very welcome";
	std::cout << "intArray.size() = " << intArray.size() << std::endl;
	std::cout << "stringArray.size() = " << stringArray.size() << std::endl;
	otherStringArray = stringArray;
	otherStringArray[3] = "I'm good, how about you?";
	std::cout << stringArray[0] << std::endl;
	std::cout << stringArray[1] << std::endl;
	std::cout << stringArray[2] << std::endl;
	std::cout << stringArray[3] << std::endl;
	std::cout << stringArray[4] << std::endl;
	std::cout << stringArray[5] << std::endl;
	

	std::cout << std::endl;
	try
	{
		std::cout << stringArray[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << stringArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}