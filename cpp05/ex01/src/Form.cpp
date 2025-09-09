/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:38:32 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 11:42:40 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// if any exception is thrown in the constructor, no member variables will be initialized
Form::Form(const std::string& _name, int _signGrade, int _execGrade)
: _name(_name), _signGrade(_signGrade), _execGrade(_execGrade)
{
	if (_signGrade < MAX_GRADE || _execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (_signGrade > MIN_GRADE || _execGrade > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string& Form::getName() const
{
	return (_name);
}

int	Form::getSignedGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

bool	Form::isSigned() const
{
	return (_isSigned);
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Form: Grade is too high (minimum is 1)");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form: Grade is too low (maximum is 150)");
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
	{
		throw std::logic_error("Form is already signed");
	}
	if (bureaucrat.getGrade() > _signGrade)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName()
		<< ", Sign Grade: " << form.getSignedGrade()
		<< ", Execute Grade: " << form.getExecGrade()
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return (os);
}
