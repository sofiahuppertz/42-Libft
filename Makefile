# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 18:35:09 by shuppert          #+#    #+#              #
#    Updated: 2023/05/07 17:47:33 by shuppert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c \
ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_strrchr.c ft_strdup.c \
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memcpy.c ft_strlen.c ft_memmove.c \
ft_toupper.c ft_calloc.c ft_memchr.c ft_isalnum.c ft_isascii.c ft_putnbr_fd.c \
ft_memcmp.c ft_strncmp.c ft_isalpha.c ft_strchr.c ft_strnstr.c ft_split.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_striteri.c \


OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Werror -Wextra -I./include

NAME = libft.a

$(NAME): $(OBJ)
		 ar rcs $(NAME) $(OBJ) 

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean $(NAME)

.PHONY: all clean fclean re

