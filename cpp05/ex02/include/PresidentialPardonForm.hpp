/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:37 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 14:29:37 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
# define PRE_SIGNGRADE 25
# define PRE_EXECGRADE 5

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(const PresidentialPardonForm& target) = default;
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
		virtual ~PresidentialPardonForm() = default;
		PresidentialPardonForm(PresidentialPardonForm& target) noexcept= delete;
		PresidentialPardonForm& operator=(PresidentialPardonForm& other) noexcept= delete;
		PresidentialPardonForm(const std::string& target);

		const std::string&	getTarget() const;
		virtual void		execute(const Bureaucrat& executor) const override;

	private:
		const std::string	_target;
};

#endif
