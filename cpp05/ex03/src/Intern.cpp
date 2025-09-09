/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:57:06 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 20:57:06 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

[[nodiscard]]AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	static const FormCreator forms[] = {
		{"shrubbery creation", &Intern::createShrubberyCreationForm},
		{"robotomy request", &Intern::createRobotomyRequestForm},
		{"presidential pardon", &Intern::createPresidentialPardonForm}
	};
	
	static const int numForms = sizeof(forms) / sizeof(forms[0]);

	for (int i = 0; i < numForms; ++i)
	{
		if (name == forms[i].name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (forms[i].formCreator)(target);
		}
	}
	throw std::invalid_argument("Unknown form name: " + name);
}

[[nodiscard]] AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

[[nodiscard]] AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

[[nodiscard]] AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

