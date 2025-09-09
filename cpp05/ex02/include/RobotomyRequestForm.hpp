/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:40 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 14:29:40 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
# define ROBOT_SIGNGRADE 72
# define ROBOT_EXECGRADE 45

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(const RobotomyRequestForm& target) = default;
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
		virtual ~RobotomyRequestForm() = default;
		RobotomyRequestForm(RobotomyRequestForm& target) noexcept = delete;
		RobotomyRequestForm& operator=(RobotomyRequestForm& other) noexcept = delete;
		RobotomyRequestForm(const std::string& target);

		const std::string&	getTarget() const;
		virtual void		execute(const Bureaucrat& executor) const override;

	private:
		const std::string	_target;
};

#endif
