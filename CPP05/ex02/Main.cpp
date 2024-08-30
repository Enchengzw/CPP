/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:33:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 20:00:59 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Include/Bureaucrat.hpp"
#include "./Include/AForm.hpp"
#include "./Include/PresidentialPardonForm.hpp"
#include "./Include/RobotomyRequestForm.hpp"
#include "./Include/ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat Carlos("Carlos", 1);
	Bureaucrat Paco("Paco", 150);
	ShrubberyCreationForm Shrubbery("Shrubbery");
	PresidentialPardonForm Presidential("Dumb");
	RobotomyRequestForm Robotomy("Dumber");

	std::cout << "FAIL SIGNS" << std::endl;
	try	{
		Paco.signForm(Shrubbery);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Paco.signForm(Presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Paco.signForm(Robotomy);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "FAIL EXECUTE NOT SIGNED" << std::endl;
	try	{
		Shrubbery.execute(Paco);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Presidential.execute(Paco);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Robotomy.execute(Paco);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "SUCCESS SIGNS" << std::endl;
	try	{
		Carlos.signForm(Shrubbery);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Carlos.signForm(Presidential);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Carlos.signForm(Robotomy);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "FAIL EXECUTE SIGNED" << std::endl;
	try	{
		Shrubbery.execute(Paco);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Presidential.execute(Paco);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Robotomy.execute(Paco);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "SUCCESS EXECUTE" << std::endl;
	try	{
		Shrubbery.execute(Carlos);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Presidential.execute(Carlos);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		Robotomy.execute(Carlos);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return(0);
}