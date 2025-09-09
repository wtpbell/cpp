/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 10:06:48 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 12:25:41 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define BOLD	"\033[1m"
#define BLUE	"\033[0;94m"
#define GREEN	"\033[0;92m"
#define YELLOW	"\033[0;93m"
#define RED		"\033[0;91m"
#define CYAN	"\033[0;96m"
#define MAGENTA	"\033[0;95m"
#define RESET	"\033[0m"
#define ORANGE	"\033[38;5;208m"

#include <string>
#include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Bureaucrat
{
	public:
			Bureaucrat() = delete;
			Bureaucrat(const Bureaucrat& src) = default;
			Bureaucrat& operator=(const Bureaucrat& rhs) = delete;
			~Bureaucrat() = default;
			Bureaucrat(Bureaucrat& src) noexcept = delete;
			Bureaucrat& operator=(Bureaucrat& rhs) noexcept = delete;
			Bureaucrat(const std::string& name, int grade);

			const std::string&	getName() const;
			int					getGrade() const;
			void				incrementGrade(int num = 1);
			void				decrementGrade(int num = 1);
			void				signForm(class AForm& form);
			void				executeForm(class AForm& form) const;
			
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
			int					_grade = 0;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
