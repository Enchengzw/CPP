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

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = src;
	return ;
}

Bureaucrat::Bureaucrat(std::string const &type) : _type(type)
{
	std::cout << "Bureaucrat type constructor called." << std::endl;
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
		this->_type = src._type;
	return (*this);
}

std::string const &Bureaucrat::getType(void) const
{
	return (this->_type);
}

void	Bureaucrat::makeSound(void) const
{
	std::cout << this->_type << ": KEKW " << std::endl;
	return ;
}