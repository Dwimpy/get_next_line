# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 01:17:05 by arobu             #+#    #+#              #
#    Updated: 2023/02/25 17:53:21 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= libgnl.a
NAME_BONUS		= libgnlbonus.a
INCLUDE			= -I./gnl/include/
INCLUDE_BONUS	= -I./gnl_bonus/include/
SRC				= ./gnl/src/
OBJ				= ./gnl/obj/
SRC_BONUS		= ./gnl_bonus/src/
OBJ_BONUS		= ./gnl_bonus/obj/

# Compiler

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

#Archive and Remove

RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

GNL_SRCS		=	get_next_line.c get_next_line_utils.c 
GNL_OBJS		= 	$(patsubst %.c, $(OBJ)%.o, $(GNL_SRCS))

GNL_SRCS_BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c 
GNL_OBJS_BONUS	= 	$(patsubst %.c, $(OBJ_BONUS)%.o, $(GNL_SRCS_BONUS))

all:	$(NAME)

$(NAME):	$(OBJ) $(GNL_OBJS)
			@ar rcs $(NAME) $(GNL_OBJS)
			@echo "$(GREEN)$(NAME)$(DEF_COLOR) $(CYAN)successfully created!$(DEF_COLOR)"

$(OBJ)%.o:	$(SRC)%.c | $(OBJ)
			@echo "$(MAGENTA) Compiling:$(DEF_COLOR) $(notdir $<)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(OBJ):
			@mkdir -p $(OBJ)

clean:
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)
			@echo "$(YELLOW)Object$(DEF_COLOR) $(CYAN)files successfullly cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -rdf $(OBJ) 
			@$(RM) -rdf $(OBJ_BONUS) 
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME_BONUS)
			@echo "$(YELLOW)Libraries$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS) $(GNL_OBJS_BONUS)
			@ar rcs $(NAME_BONUS) $(GNL_OBJS_BONUS)
			@echo "$(GREEN)$(NAME)$(DEF_COLOR) $(CYAN)successfully created!$(DEF_COLOR)"

$(OBJ_BONUS)%.o:	$(SRC_BONUS)%.c | $(OBJ_BONUS)
			@echo "$(MAGENTA) Compiling:$(DEF_COLOR) $(notdir $<)"
			@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@ 

$(OBJ_BONUS):
			@mkdir -p $(OBJ_BONUS)
		
.PHONY:		all bonus clean fclean re norm
