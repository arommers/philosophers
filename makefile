# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/25 11:09:04 by arommers      #+#    #+#                  #
#    Updated: 2023/11/27 11:34:24 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=thread
# CFLAGS += -g -fsanitize=address
NAME = philo

INCLUDE = -I./include
SRC =	./src/main.c ./src/init.c		\
		./src/threads.c ./utils.c		\
		./src/routine.c ./src/print.c	\
		./src/input.c ./src/free.c		\
		./src/monitor.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

GREEN   := \033[32m
BLUE 	:= \033[96m
CYAN    := \033[36m
RESET   := \033[0m
BOLD    := \033[1m
PINK 	:= \033[35m

all: $(NAME)

$(NAME): $(OBJ) 
	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(CYAN)$(BOLD)----------------------------------------"
	@echo "     $(NAME) = NOW READY FOR USE!"
	@echo "----------------------------------------$(RESET)"

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiled ✅ $(CYAN) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE) $(BOLD)$(NAME) $(RESET) Cleansed ✅"

re: fclean all

.PHONY: all clean fclean re bonus