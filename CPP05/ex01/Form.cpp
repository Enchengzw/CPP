/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:56:18 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:11 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Form.hpp"

Form::Form(void) : _name("Generic"),
	_signed(false),
	_signGrade(Bureaucrat::lowestGrade),
	_execGrade(Bureaucrat::lowestGrade) {
	std::cout << "Form default constructor called." << std::endl;
	return ;
}

Form::Form(Form const &src) : _name(src._name),
	_signed(src._signed),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade) {
	std::cout << "Form copy constructor called." << std::endl;
	return ;
}

Form::Form(std::string const &name, int SignGrade, int ExecGrade) : _name(name),
	_signed(false),
	_signGrade(SignGrade),
	_execGrade(ExecGrade) {
	std::cout << "Form name constructor called." << std::endl;
	if (SignGrade < Bureaucrat::highestGrade || ExecGrade < Bureaucrat::highestGrade )
		throw (Form::GradeTooHighException());
	if (SignGrade > Bureaucrat::lowestGrade || ExecGrade > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called." << std::endl;
	return ;
}

Form &Form::operator=(Form const &src)
{
	std::cout << "Form assignment overload operator called." << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::IsSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	Form::BeSigned(Bureaucrat const & bureaucrat)
{
	if (this->_signed)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	this->_signed = true;
	return ;
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

std::ostream &	operator<<(std::ostream & os, Form const & form)
{
	os << form.getName() << " form is " << 
	(form.IsSigned() ? "signed" : "not signed") << " and requires grade " << form.getSignGrade() <<
	 " to sign and grade " << form.getExecGrade() << " to execute." << std::endl;
	return (os);
}