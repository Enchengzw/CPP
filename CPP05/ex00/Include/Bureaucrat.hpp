/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:12:04 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 16:50:03 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <string>
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat(void);
		Bureaucrat &operator=(Bureaucrat const &src);
	
		void incrementGrade(int	amount);
		void decrementGrade(int	amount);
			
		std::string const &getName(void) const;
		int				   getGrade(void) const;

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream & operator<<( std::ostream & os, const Bureaucrat & person );

#endif