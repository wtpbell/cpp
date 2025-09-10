/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 18:03:50 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/10 09:20:35 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

#include <iostream>

class Contact
{
	
	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	
	public:
			Contact();
			~Contact();
			void	print(void);
			void	setFirstName(void);
			void	setLastName(void);
			void	setNickname(void);
			void	setPhoneNumber(void);
			void	setDarkestSecret(void);
			std::string	getFirstName(void) const;
			std::string	getLastName(void) const;
			std::string	getNickname(void) const;
			std::string	getPhoneNumber(void) const;
			std::string	getDarkestSecret(void) const;
};

bool	getInput(std::string &field, const std::string &prompt, bool isDigits);
bool	isPrintable(const std::string& str);
#endif
