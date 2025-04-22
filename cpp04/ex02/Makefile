DEL_LINE =		\033[2K
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
BLUE =			\033[0;94m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
RED =			\033[0;91m
CYAN =			\033[0;96m
MAGENTA =		\033[0;95m
RESET =			\033[0m

NAME				= ex02

INC					= -I include/
OBJS_DIR 			= ./objs
SRCS_DIR 			= ./src

CPP					= c++
CFLAGS				= -Wextra -Wall -Werror  -std=c++17 $(INC)
RM					= rm -f

SRC					= main.cpp Cat.cpp Dog.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
SRCS				= $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS				= $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

start:
					@echo "$(BLUE) ◎ Starting build process...$(DEF_COLOR)"
					@make all

all: 				$(OBJS_DIR) $(NAME)

$(NAME): 			$(OBJS)
					@echo "$(CYAN) ◎ Linking → $(MAGENTA)$@$(DEF_COLOR)"
					@$(CPP) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
					@echo "$(GREEN) ◎ Executable $(NAME) created successfully! ✓$(DEF_COLOR)"

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
					@echo "$(YELLOW) ◎ Compiling → $(MAGENTA)$<$(DEF_COLOR)"
					@$(CPP) $(CFLAGS) $(INC) -c $< -o $@
					@echo "$(GREEN) ◎ Object file $(notdir $@) created successfully! ✓$(DEF_COLOR)"

clean:
					@echo "$(RED) ◎ Cleaning object files and directories...$(DEF_COLOR)"
					@$(RM) -r $(OBJS) $(OBJS_DIR)
					@echo "$(GREEN) ◎ Cleaned successfully! ✓$(DEF_COLOR)"

fclean: 			clean
					@echo "$(RED) ◎ Removing executable $(NAME)...$(DEF_COLOR)"
					@$(RM) $(NAME)
					@echo "$(GREEN) ◎ Full cleanup completed! ✓$(DEF_COLOR)"

re: 				fclean all

.PHONY				: all clean fclean re
