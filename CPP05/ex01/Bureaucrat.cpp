/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:19:28 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/02 11:48:33 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Bureaucrat.hpp"
#include "./Include/Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("John Doe"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat name constructor called." << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Bureaucrat assignment overload operator called." << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}


int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int amount)
{
	if (this->_grade - amount < Bureaucrat::highestGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	else 
	{
		std::cout << *this << " was promoted to grade " << (this->_grade - amount)<< std::endl;
		this->_grade -= amount;
	}
	return ;
}

void	Bureaucrat::decrementGrade(int amount)
{
	if ((this->_grade + amount) > Bureaucrat::lowestGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	else 
	{
		std::cout << *this << " was demoted to grade " << (this->_grade + amount)<< std::endl;
		this->_grade += amount;
	}
	return ;
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade is too high. (lower than 1)");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade is too low. (higher than 150)");
}

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & obj)
{
	os <<  obj.getName() << ", bureaucrat grade: " << obj.getGrade() << " ";
	return (os);
}


void	Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.BeSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << *this << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}