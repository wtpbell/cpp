/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:45 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 14:29:45 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", PRE_SIGNGRADE, PRE_EXECGRADE), _target(target){}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	validate(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
