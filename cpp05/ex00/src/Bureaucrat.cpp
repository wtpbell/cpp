/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 14:18:47 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 14:00:56 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	_grade = grade;
}

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(int num)
{
	if (_grade - num < MAX_GRADE)
		throw GradeTooHighException();
	_grade -= num;
}

void	Bureaucrat::decrementGrade(int num)
{
	if (_grade + num > MIN_GRADE)
		throw GradeTooLowException();
	_grade += num;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
