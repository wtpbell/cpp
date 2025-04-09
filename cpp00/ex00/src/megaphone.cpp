/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 09:48:26 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/04 09:40:55 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string trim(const std::string& s)
{
	size_t start = s.find_first_not_of(" \t\n\r");
	size_t end = s.find_last_not_of(" \t\n\r");

	if (start == std::string::npos)
		return ("");
	else
		return s.substr(start, end - start + 1);
}

void	 printUpperCase(int argc, char **argv)
{
	std::string str;

	for (int i = 1; i < argc; i++)
	{
		std::string word = trim(argv[i]);
		if (!str.empty())
			str.append(" ");
		str.append(word);
	}

	for(auto &c : str)
	{
		c = (char)toupper(c);
	}
	std::cout << str << std::endl;
}

int	main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		printUpperCase(argc, argv);
	return (0);
}
