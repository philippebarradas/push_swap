# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:18:37 by phbarrad          #+#    #+#              #
#    Updated: 2021/05/18 13:37:49 by phbarrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

HEADER	=	-I includes

SRC	=	cmp.c \
		ft_isascii.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_itoa.c \
		ft_strlcat.c \
		ft_strtrim.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strchr.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_calloc.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_bzero.c \
		ft_strncmp.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

BONUS	=	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

bonus:	$(OBJ) $(OBJBONUS)
		ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean:
		$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
