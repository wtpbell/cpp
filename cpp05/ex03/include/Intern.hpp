/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:55:37 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 19:55:37 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

// static : no this Pointer, cant access non static members, class level not with individual instances
// can be called without an instance of the class

class	Intern
{
	public:
			Intern() = default;
			Intern(const Intern&) = default;
			Intern& operator=(const Intern&) = default;
			~Intern() = default;

			[[nodiscard]] AForm*	makeForm(const std::string& name, const std::string& target);

	private:
			struct FormCreator
			{
				const char* name;
				AForm* (*formCreator)(const std::string& target);
			};
			[[nodiscard]] static AForm* createShrubberyCreationForm(const std::string& target);
			[[nodiscard]] static AForm* createRobotomyRequestForm(const std::string& target);
			[[nodiscard]] static AForm* createPresidentialPardonForm(const std::string& target);
};

#endif
