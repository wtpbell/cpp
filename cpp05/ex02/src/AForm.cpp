/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:38:32 by bewong            #+#    #+#             */
/*   Updated: 2025/09/03 11:42:40 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// if any exception is thrown in the constructor, no member variables will be initialized
AForm::AForm(const std::string& _name, int _signGrade, int _execGrade)
: _name(_name), _signGrade(_signGrade), _execGrade(_execGrade)
{
	if (_signGrade < MAX_GRADE || _execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (_signGrade > MIN_GRADE || _execGrade > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string&	AForm::getName() const
{
	return (_name);
}

int	AForm::getSignedGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

bool	AForm::isSigned() const
{
	return (_isSigned);
}

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return ("AForm: Grade is too high (minimum is 1)");
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return ("AForm: Grade is too low (maximum is 150)");
}

const char* AForm::NotSignedException::what() const noexcept
{
	return ("AForm: Not signed");
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
	{
		throw std::logic_error("AForm is already signed");
	}
	if (bureaucrat.getGrade() > _signGrade)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void	AForm::validate(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "AForm: " << Aform.getName()
		<< ", Sign Grade: " << Aform.getSignedGrade()
		<< ", Execute Grade: " << Aform.getExecGrade()
		<< ", Signed: " << (Aform.isSigned() ? "Yes" : "No");
	return (os);
}
