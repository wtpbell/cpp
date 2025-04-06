/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 18:05:14 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/06 17:11:59 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
			Contact			contacts[8];
			unsigned int	numContacts;
			void			printPhonebook(void);
			
	public:
			void	add(void);
			void	search(void);
};

#endif
