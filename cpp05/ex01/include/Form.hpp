/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 16:18:18 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 12:22:51 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
			Form() = delete;
			Form(const Form& src) = default;
			Form& operator=(const Form& rhs) = delete;
			~Form() = default;
			Form(Form& src) noexcept= delete;
			Form& operator=(Form& rhs) noexcept= delete;
			Form(const std::string& _name, int _signGrade, int _execGrade);

			const std::string&	getName() const;
			int					getSignedGrade() const;
			int					getExecGrade() const;
			bool				isSigned() const;
			void				beSigned(const Bureaucrat& bureaucrat);

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

	private:
			const std::string	_name;
			bool				_isSigned = false;
			const int			_signGrade;
			const int			_execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif
