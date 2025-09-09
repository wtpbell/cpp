/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformFile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:45:52 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 23:01:22 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformFile.hpp"
#include <filesystem>

TransformFile::TransformFile(std::string filename, std::string from, std::string to) \
								: filename(filename), str1(from), str2(to)
{
}

int	TransformFile::init(void)
{
	std::filesystem::file_status fStatus = std::filesystem::status(this->filename);

	if (!std::filesystem::exists(this->filename))
	{
		std::cerr << RED << this->filename << " does not exist." << RESET << std::endl;
		return (FAILURE);
	}
	if (std::filesystem::is_directory(fStatus))
	{
		std::cerr << RED << this->filename << " is a directory." << RESET << std::endl;
		return (FAILURE);
	}

	this->newFile = this->filename + "_replace";
	std::cout << GREEN << "[Input]: " << this->filename << std::endl;
	std::cout << "[Replace]: '" << this->str1 << "' -> '" << this->str2 << "'"
				<< RESET << std::endl;
	return (SUCCESS);
}

TransformFile::~TransformFile(void)
{
	std::cout << RED << "[Cleanup]: " << this->filename << RESET << std::endl;
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
	std::filesystem::file_status	fStatus;

	fStatus = std::filesystem::status(this->getFileName());
	if ((fStatus.permissions() & std::filesystem::perms::owner_read) == std::filesystem::perms::none)
	{
		std::cerr << RED << "No read permission for " << this->getFileName() << "." << RESET << std::endl;
		return (FAILURE);
	}
	this->inFile.open(this->getFileName());
	if (!this->inFile.is_open())
	{
		std::cerr << RED << "Failed to open " << this->getFileName() << "." << RESET << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}

int	TransformFile::write(void)
{
	std::string	line;
	size_t		pos;

	this->outFile.open(this->getNewFileName());
	if (!this->outFile.is_open())
	{
		std::cerr << RED << "Failed to create " << this->getNewFileName() << "." << RESET << std::endl;
		return (FAILURE);
	}

	while (std::getline(this->inFile, line))
	{
		if (this->str1.empty())
		{
			std::string newLine;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ')
					newLine += this->str2;
				else
					newLine += line[i];
			}
			this->outFile << newLine;
		}
		else
		{
			pos = 0; 
			while ((pos = line.find(this->str1, pos)) != std::string::npos)
			{
				line = line.substr(0, pos) + this->str2 + line.substr(pos + this->str1.length());
				pos += this->str2.length();
			}
			this->outFile << line;
		}
		if (!this->inFile.eof())
			this->outFile << std::endl;
	}

	this->inFile.close();
	this->outFile.close();
	return (SUCCESS);
}
