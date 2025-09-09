/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 21:35:34 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 21:48:30 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transformFile.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "ex04: Wrong number of arguments." << std::endl
		<< "Usage: " << argv[0] << " <filename> <string to replace> <replacement>"
		<< RESET << std::endl;
		return (FAILURE);
	}
	TransformFile file(argv[1], argv[2], argv[3]);
	
	if (file.init() != SUCCESS)
		return (FAILURE);
	if (file.read() != SUCCESS)
		return (FAILURE);
	if (file.write() != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
