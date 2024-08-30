/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:48:12 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:11 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		Form(Form const &src);
		Form(std::string const &name, int SignGrade, int ExecGrade);
		~Form(void);
		Form &operator=(Form const &src);
			
		std::string const &getName(void) const;
        bool				IsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

        void	            BeSigned(Bureaucrat const & bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
        int const           _signGrade;
        int const           _execGrade;
};

std::ostream & operator<<( std::ostream & os, const Form & person );

#endif