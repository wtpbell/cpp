/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformFile.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 20:18:57 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 21:46:35 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMFILE_HPP
# define TRANSFORMFILE_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"
# define SUCCESS 0
# define FAILURE 1

#include <iostream>
#include <fstream>
#include <filesystem>

class TransformFile
{
	private:
			std::string	filename;
			std::string	newFile;
			std::string	str1;
			std::string	str2;
			std::ifstream	inFile;
			std::ofstream	outFile;

	public:
			int		init(void);
			TransformFile(std::string filename, std::string from, std::string to);
			~TransformFile(void);
			std::string	getFileName(void);
			std::string	getNewFileName(void);
			int		read(void);
			int		write(void);
};

#endif
