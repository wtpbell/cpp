/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 18:03:50 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/06 19:32:40 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	Contact();
	~Contact();
	
	private:
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNum;
			std::string darkestSecret;

	public:
			bool	isprintable(const std::string& str);
			void	setFirstName(const std::string& firstName);
			void	setLastName(const std::string& lastName);
			void	setNickname(const std::string& nickName);
			void	setPhoneNumber(const std::string& phoneNumber);
			void	setDarkestSecret(const std::string& darkestSecret);
			std::string	getFirstName(void) const;
			std::string	getLastName(void) const;
			std::string	getNickname(void) const;
			std::string	getPhoneNumber(void) const;
			std::string	getDarkestSecret(void) const;
};

#endif
