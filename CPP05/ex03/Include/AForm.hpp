/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:48:12 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 17:13:44 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_CLASS_H
# define AForm_CLASS_H

# include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(void);
		AForm(AForm const &src);
		AForm(std::string const &name, int SignGrade, int ExecGrade);
		virtual ~AForm(void);
		AForm &operator=(AForm const &src);
			
		std::string const &getName(void) const;
        bool				IsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

        void	            BeSigned(Bureaucrat const & Bureaucrat);
		void				execute(Bureaucrat const & bureaucrat) const;
		virtual void		BeExecuted(void) const = 0;

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

		class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
        int const           _signGrade;
        int const           _execGrade;
};

std::ostream & operator<<( std::ostream & os, const AForm & person );

#endif