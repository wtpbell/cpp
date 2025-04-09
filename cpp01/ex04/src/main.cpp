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
	TransformFile	*file;

	if (argc == 4)
	{
		file = new TransformFile(argv[1], argv[2], argv[3]);
		if (file->read() != SUCCESS)
			return (FAILURE);
		if (file->write() != SUCCESS)
			return (FAILURE);
		delete file;
		return (SUCCESS);
	}
	std::cerr << RED << "ex04: Wrong numbers of argument." 
				<< std::endl;
	std::cerr << "ex04: <filename> <String to be replaced> <String to replace>"
				<< RESET << std::endl;
	return (FAILURE);
}
