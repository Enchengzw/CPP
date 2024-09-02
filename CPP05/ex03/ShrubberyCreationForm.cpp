/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:11:49 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::SignGrade,
					ShrubberyCreationForm::ExecGrade),
			_target("Unknown") {
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
		:	AForm(src),
			_target(src._target) {
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::SignGrade,
					ShrubberyCreationForm::ExecGrade),
			_target(target) {
	std::cout << "ShrubberyCreationForm name constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(
									ShrubberyCreationForm const & src) {
	this->_target = src._target;
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

void	ShrubberyCreationForm::BeExecuted(void) const {
	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(),
								std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << ShrubberyCreationForm::_shrubbery;
		std::cout << "A shrubbery has been planted at " << _target << "_shrubbery." << std::endl;
		ofs.close();
	}
	return ;
}

std::string const ShrubberyCreationForm::_shrubbery =
"\n"
"                        %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"               ; %%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"               % *%%, ,%%%%*(    '\n"
"           %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";
