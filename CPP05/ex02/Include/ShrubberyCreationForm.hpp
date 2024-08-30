/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:09:39 by ezhou             #+#    #+#             */
/*   Updated: 2024/08/30 19:57:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_CLASS_H
# define SHRUBBERY_CREATION_FORM_CLASS_H

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);

		std::string const &	getTarget(void) const;

		void	BeExecuted(void) const;

		static int const	SignGrade = 145;
		static int const	ExecGrade = 137;

	private:
		std::string					_target;
		static std::string const	_shrubbery;
};

#endif