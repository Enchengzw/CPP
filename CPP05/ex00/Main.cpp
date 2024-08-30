/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:33:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 17:25:56 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Carlos", 147);
	std::cout << a << std::endl;
	a.decrementGrade(1);
	std::cout << a << std::endl;
	a.decrementGrade(1);
	std::cout << a << std::endl;
	a.incrementGrade(1);
	std::cout << a << std::endl;
    try {
        Bureaucrat b("Carlos", -1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat c("Carlos", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	return (0);
}