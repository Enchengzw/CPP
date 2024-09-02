/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:45:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/02 17:10:14 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
	return ;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern copy constructor called." << std::endl;
	(void)src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern desctructor called." << std::endl;
	return ;
}

Intern &	Intern::operator=(Intern const & src)
{
	std::cout << "Intern assignment operator overload called." << std::endl;
	(void)src;
	return (*this);
}


AForm* Intern::makeForm(std::string const & s1, std::string const& s2)
{
	AForm* res;
	std::string	array[3] = {"presidential", "robotomy", "shrubbery"};
	res = NULL;
    int i = 0;
    while (i < 3)
    {
        if (s1 == array[i])
            break;
        i++;
    }
	switch (i)
	{
		case 0:
			std::cout << "Intern creates presidential" << std::endl;
			res = (new PresidentialPardonForm(s2));
			break;

		case 1:
			std::cout << "Intern creates robotomy" << std::endl;
			res = (new RobotomyRequestForm(s2));
			break;

		case 2:
			std::cout << "Intern creates shrubbery" << std::endl;
			res =  (new ShrubberyCreationForm(s2));
			break;

		default:
			std::cout << "Form: " << s1 << " doesn't exist" << std::endl;
			break;
	}
	return (res);
}