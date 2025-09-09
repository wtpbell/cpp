/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 18:48:24 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/13 18:48:25 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

#include <iostream>
#include <string>

enum class Level { DEBUG, INFO, WARNING, ERROR, INVALID };

class Harl
{
	private:
		void			debug(void);
		void			info(void);
		void			warning(void);
		void			error(void);

	public:
		Harl(void);
		~Harl(void);
		void			filterComplain(Level level);
		Level			getLevel(const std::string& level);
};

#endif
