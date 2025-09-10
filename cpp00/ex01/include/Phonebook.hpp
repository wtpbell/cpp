/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 18:05:14 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/10 09:40:51 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

class PhoneBook
{
	private:
			Contact			contacts[8];
			unsigned int	numContacts;
			void			printPhonebook(void);
			void			displaySearchResult(unsigned int index);
			
	public:
			PhoneBook(void);
			~PhoneBook(void);

			void	add(void);
			void	search(void);
};

bool		isValidIndex(const std::string& input, unsigned int& index);
std::string	truncateField(const std::string& str);
#endif
