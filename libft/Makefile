# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:18:37 by phbarrad          #+#    #+#              #
#    Updated: 2021/06/11 15:24:40 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

CFLAGS	=	#-Wall -Wextra -Werror

RM	=	rm -rf

HEADER	=	-I includes

SRC	=	cmp.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_atoi.c \
		ft_putstr_fd.c \

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
