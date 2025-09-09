/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFrom.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:47 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 14:29:47 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", ROBOT_SIGNGRADE, ROBOT_EXECGRADE), _target(target){}

const std::string&	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	validate(executor);
	std::cout << "Rrrrrrrrrr" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
