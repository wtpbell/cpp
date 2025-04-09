/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformFile.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 20:45:52 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 21:23:51 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transformFile.hpp"

TransformFile::TransformFile(std::string filename, std::string from, std::string to) \
								: filename(filename), str1(from), str2(to)
{
	this->newFile = filename + "_replace";
	std::cout << GREEN << filename << " is ready to be opened!" << std::endl;
	std::cout << from << " will be replaced by " << to
				<< RESET << std::endl;
}

TransformFile::~TransformFile(void)
{
	std::cout << RED << this->filename << " is being deleted."
				<< RESET << std::endl;
}

std::string	TransformFile::getFileName(void)
{
	return (this->filename);
}

std::string	TransformFile::getNewFileName(void)
{
	return (this->newFile);
}

int	TransformFile::read(void)
{
	this->inFile.open(this->getFileName());
	
}

int	TransformFile::write(void)
{

}
