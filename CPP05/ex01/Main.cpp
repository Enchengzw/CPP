/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:33:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:11 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Include/Bureaucrat.hpp"
#include "./Include/Form.hpp"

int main()
{
	Bureaucrat b("Carlos", 100);
	Form a("Form1", 120, 25);
	Form c("Form2", 75, 25);
	Form d("Form3", 50, 25);
	a.BeSigned(b);
	try	{
		a.BeSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form d("Form3", 0, 25);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Form e("Form4", 151, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		c.BeSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		b.signForm(d);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return(0);
}