# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 09:51:11 by phbarrad          #+#    #+#              #
#    Updated: 2021/06/11 09:42:50 by phbarrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################
#                            Informations                            #
######################################################################

NAME			= push_swap
NAME_BONUS		= checker
CC				= @gcc
CFLAGS			= -fsanitize=leak -Wall -Wextra -Werror
LIB_FLAGS		= -lncurses -lft -L ./libft
RM				= @rm -rf
LIBFT			= ./libft
INCLUDE			= -I /srcs
INCLUDE_B		= -I /bonus
INCLUDE_LIB		= -I ./libft/libft.a

######################################################################
#                               C0l0r$                               #
######################################################################

BLACK			:= $(shell tput -Txterm setaf 0)
RED				:= $(shell tput -Txterm setaf 1)
GREEN			:= $(shell tput -Txterm setaf 2)
YELLOW			:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE		:= $(shell tput -Txterm setaf 4)
PURPLE			:= $(shell tput -Txterm setaf 5)
BLUE			:= $(shell tput -Txterm setaf 6)
WHITE			:= $(shell tput -Txterm setaf 7)
BOLD			:= $(shell tput -Txterm bold)
END				:= $(shell tput -Txterm sgr0)
NAMEC			= ${BLUE}${BOLD}$(NAME)${END}

######################################################################
#                            Source Files                            #
######################################################################

SRCS			= main.c error.c op.c op2.c ffree.c long_start.c long_loop.c loop.c \
				 tool_loop3.c tool_loop2.c tool_loop.c tool2.c tool3.c

SRC				= $(addprefix srcs/, $(SRCS))

######################################################################
#                         Source Files_bonus                         #
######################################################################

BONUS			= main_bonus.c error_bonus.c op_bonus.c op2_bonus.c ffree_bonus.c

SRC_B			= $(addprefix bonus/, $(BONUS))

######################################################################
#                            Object Files                            #
######################################################################

OBJ				= $(SRC:c=o)

OBJ_B			= $(SRC_B:c=o)

######################################################################
#                               Rules                                #
######################################################################

%.o: %.c
			@printf "${PURPLE}${BOLD}Start compile ... %-50.50s\r${END}" $@
			${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJ)
			@echo "\n"
			@$(MAKE) -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LIB) -o $(NAME) $(OBJ) $(LIB_FLAGS)
			@echo "\n${GREEN}The $(NAMEC) ${GREEN}has been build !${END}\n"

bonus:		$(OBJ_B)
			@echo "\n"
			@$(MAKE) -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDE_B) $(INCLUDE_LIB) -o $(NAME_BONUS) $(OBJ_B) $(LIB_FLAGS)
			@echo "\n${GREEN}The $(NAMEC) ${GREEN}has been build" \
				"(with ${BOLD}${WHITE}$@${END}${GREEN}) !${END}"

clean:
			$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) clean -C $(LIBFT)
			@echo "${LIGHTPURPLE}Cleaning ...${END}\n"

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)
			@$(MAKE) fclean -C $(LIBFT)
			@echo "${LIGHTPURPLE}Delete $(NAMEC)${LIGHTPURPLE}...${END}\n"

re:			fclean all

.PHONY:		all test clean fclean re
