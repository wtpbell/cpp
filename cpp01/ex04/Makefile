DEL_LINE =		\033[2K
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
BLUE =			\033[0;94m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
RED =			\033[0;91m
CYAN =			\033[0;96m
MAGENTA =		\033[0;95m

NAME				= ex04

INC					= -I include/
OBJS_DIR 			= ./objs
SRCS_DIR 			= ./src

CPP					= c++
CFLAGS				= -Wextra -Wall -Werror -std=c++17 $(INC)
RM					= rm -f

MAIN_SRC			= main.cpp transformFile.cpp
TEST_SRC			= test.cpp transformFile.cpp

MAIN_SRCS			= $(addprefix $(SRCS_DIR)/, $(MAIN_SRC))
TEST_SRCS			= $(addprefix $(SRCS_DIR)/, $(TEST_SRC))

MAIN_OBJS			= $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(MAIN_SRCS))
TEST_OBJS			= $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(TEST_SRCS))


start:
					@echo "$(BLUE) ◎ Starting build process...$(DEF_COLOR)"
					@make all

all: 				$(OBJS_DIR) $(NAME) test

$(NAME): 			$(MAIN_OBJS)
					@echo "$(CYAN) ◎ Linking → $(MAGENTA)$@$(DEF_COLOR)"
					@$(CPP) $(CFLAGS) $(MAIN_OBJS) -o $(NAME)
					@echo "$(GREEN) ◎ Executable $(NAME) created successfully! ✓$(DEF_COLOR)"

test: $(TEST_OBJS)
					@$(CPP) $(CFLAGS) $(TEST_OBJS) -o test
					@echo "$(GREEN) ◎ Executable test created successfully! ✓$(DEF_COLOR)"

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
					@echo "$(YELLOW) ◎ Compiling → $(MAGENTA)$<$(DEF_COLOR)"
					@$(CPP) $(CFLAGS) $(INC) -c $< -o $@
					@echo "$(GREEN) ◎ Object file $(notdir $@) created successfully! ✓$(DEF_COLOR)"

clean:
					@echo "$(RED) ◎ Cleaning object files and directories...$(DEF_COLOR)"
					@$(RM) -rf $(OBJS_DIR)
					@$(RM) -f test
					@echo "$(GREEN) ◎ Cleaned successfully! ✓$(DEF_COLOR)"

fclean: 			clean
					@echo "$(RED) ◎ Removing executable $(NAME)...$(DEF_COLOR)"
					@$(RM) $(NAME)
					@$(RM) test
					@echo "$(GREEN) ◎ Full cleanup completed! ✓$(DEF_COLOR)"

re: 				fclean all

.PHONY				: all clean fclean re
