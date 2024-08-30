/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:06:24 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
		:	AForm("Robotomy Request Form",
					RobotomyRequestForm::SignGrade,
					RobotomyRequestForm::ExecGrade),
			_target("Anyone") {
	std::cout << "RobotomyRequestForm default constructor called."<< std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
		:	AForm(src),
			_target(src._target) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
		:	AForm("Robotomy Request Form",
					RobotomyRequestForm::SignGrade,
					RobotomyRequestForm::ExecGrade),
			_target(target) {
	std::cout << "RobotomyRequestForm name constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(
									RobotomyRequestForm const & src) {
	this->_target = src._target;
	return (*this);
}

std::string const &	RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

void	RobotomyRequestForm::BeExecuted(void) const {
	std::cout << "* Drilling Noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " resisted robotomization..." << std::endl;
	return ;
}