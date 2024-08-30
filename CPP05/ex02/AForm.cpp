/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:56:18 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 17:18:14 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/AForm.hpp"

AForm::AForm(void) : _name("Generic"),
	_signed(false),
	_signGrade(Bureaucrat::lowestGrade),
	_execGrade(Bureaucrat::lowestGrade) {
	std::cout << "AForm default constructor called." << std::endl;
	return ;
}

AForm::AForm(AForm const &src) : _name(src._name),
	_signed(src._signed),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade) {
	std::cout << "AForm copy constructor called." << std::endl;
	return ;
}

AForm::AForm(std::string const &name, int SignGrade, int ExecGrade) : _name(name),
	_signed(false),
	_signGrade(SignGrade),
	_execGrade(ExecGrade) {
	std::cout << "AForm name constructor called." << std::endl;
	if (SignGrade < Bureaucrat::highestGrade || ExecGrade < Bureaucrat::highestGrade )
		throw (AForm::GradeTooHighException());
	if (SignGrade > Bureaucrat::lowestGrade || ExecGrade > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called." << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &src)
{
	std::cout << "AForm assignment overload operator called." << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::IsSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	AForm::BeSigned(Bureaucrat const & bureaucrat)
{
	if (this->_signed)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
	return ;
}

void	AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (this->_signed == false)
		throw (AForm::NotSignedException());
	if (bureaucrat.getGrade() > this->_execGrade)
		throw (AForm::GradeTooLowException());
	this->BeExecuted();
	return ;
}

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for AForm.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for AForm.");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return ("AForm is already signed.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed.");
}

std::ostream &	operator<<(std::ostream & os, AForm const & AForm)
{
	os << AForm.getName() << " AForm is " << 
	(AForm.IsSigned() ? "signed" : "not signed") << " and requires grade " << AForm.getSignGrade() <<
	 " to sign and grade " << AForm.getExecGrade() << " to execute." << std::endl;
	return (os);
}