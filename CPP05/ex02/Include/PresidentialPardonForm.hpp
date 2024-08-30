/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:11:07 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_H
# define PRESIDENTIAL_PARDON_FORM_CLASS_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & src);

		std::string const &	getTarget(void) const;

		void	BeExecuted(void) const;

		static int const	SignGrade = 25;
		static int const	ExecGrade = 5;

	private:
		std::string	_target;
};

#endif