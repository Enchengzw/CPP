/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:12:16 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
		:	AForm("Presidential Pardon Form",
					PresidentialPardonForm::SignGrade,
					PresidentialPardonForm::ExecGrade),
			_target("Anyone") {
	std::cout << "PresidentialPardonForm default constructor called."<< std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
		:	AForm(src),
			_target(src._target) {
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
		:	AForm("Presidential Pardon Form",
					PresidentialPardonForm::SignGrade,
					PresidentialPardonForm::ExecGrade),
			_target(target) {
	std::cout << "PresidentialPardonForm attribute constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(
									PresidentialPardonForm const & src) {
	this->_target = src._target;
	return (*this);
}

std::string const &	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

void	PresidentialPardonForm::BeExecuted(void) const{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}