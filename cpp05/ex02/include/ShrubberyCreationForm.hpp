/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:42 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 14:29:42 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
# define SHRUB_SIGNGRADE 145
# define SHRUB_EXECGRADE 137

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const ShrubberyCreationForm& target) = default;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
		virtual ~ShrubberyCreationForm() = default;
		ShrubberyCreationForm(ShrubberyCreationForm& target) noexcept = delete;
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other) noexcept = delete;
		ShrubberyCreationForm(const std::string& target);

		const std::string&	getTarget() const;
		virtual void		execute(const Bureaucrat& executor) const override; 

	private:
		const std::string	_target;
};

#endif
