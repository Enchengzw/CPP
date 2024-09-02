/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:33:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/02 17:12:41 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Include/Bureaucrat.hpp"
#include "./Include/AForm.hpp"
#include "./Include/PresidentialPardonForm.hpp"
#include "./Include/RobotomyRequestForm.hpp"
#include "./Include/ShrubberyCreationForm.hpp"
#include "./Include/Intern.hpp"


int	main(void)
{
	srand(time(NULL));
	Intern someIntern;

	Bureaucrat supervisor("Supervisor", 1);
	Bureaucrat francis("Francis", 25);

	AForm *shrub = someIntern.makeForm("shrubbery", "home");
	AForm *pres = someIntern.makeForm("presidential", "Francis");
	AForm *robot = someIntern.makeForm("robotomy", "Bender");
	robot->BeSigned(francis);
	robot->execute(francis);

	try
	{
		AForm *fake = someIntern.makeForm("fake request", "Bender");
		delete fake;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;
	return (0);
}
