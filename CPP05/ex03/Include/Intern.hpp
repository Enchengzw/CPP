/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:43:59 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/02 16:59:42 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern& operator=(const Intern & other);
		Intern(const Intern& copy);
		AForm* makeForm(std::string const &s1, std::string const &s2);
};

#endif