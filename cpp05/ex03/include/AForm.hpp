/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 16:18:18 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 12:25:19 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class	AForm
{
	public:
			AForm() = delete;
			AForm(const AForm& src) = default;
			AForm& operator=(const AForm& rhs) = delete;
			virtual ~AForm() = default;
			AForm(AForm& src) noexcept= delete;
			AForm& operator=(AForm& rhs) noexcept= delete;
			AForm(const std::string& _name, int _signGrade, int _execGrade);

			const std::string&	getName() const;
			int					getSignedGrade() const;
			int					getExecGrade() const;
			bool				isSigned() const;
			void				beSigned(const Bureaucrat& bureaucrat);
			virtual void		execute(const Bureaucrat& executor) const = 0;
			void				validate(const Bureaucrat& executor) const;

			class GradeTooHighException : public std::exception
			{
				public:
						const char* what() const noexcept override;
			};
			class GradeTooLowException : public std::exception
			{
				public:
						const char* what() const noexcept override;
			};
			class NotSignedException : public std::exception
			{
				public:
						const char* what() const noexcept override;
			};

	private:
			const std::string	_name;
			bool				_isSigned = false;
			const int			_signGrade;
			const int			_execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
