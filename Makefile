# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 18:35:09 by shuppert          #+#    #+#              #
#    Updated: 2023/07/19 17:48:33 by shuppert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a
EXEC_NAME = pipex

LIB_SRCS_NAMES = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_striteri.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_printf.c \
	check_format.c \
	display_adress.c \
	display_char.c \
	display_hexadecimals.c \
	display_integer.c \
	display_text.c \
	display_unsigned_integer.c \
	str_array_length.c \
	str_to_lower.c \
	generate_random.c 
	
EXEC_SRCS_NAMES = main.c \
	pipex_end_all.c \
	pipex_utils.c \
	



LIB_SRCS = $(addprefix lib_srcs/, $(LIB_SRCS_NAMES))
EXEC_SRCS = $(addprefix pipex_srcs/, $(EXEC_SRCS_NAMES))


LIB_OBJS = $(addprefix objects/lib/, $(LIB_SRCS_NAMES:.c=.o))
EXEC_OBJS = $(addprefix objects/pipex/, $(EXEC_SRCS_NAMES:.c=.o))


all: $(LIB_NAME) $(EXEC_NAME)

$(LIB_NAME): $(LIB_OBJS)
	ar rcs $(LIB_NAME) $(LIB_OBJS)

$(EXEC_NAME): $(EXEC_OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(EXEC_OBJS) -L. -lft -o $(EXEC_NAME)

objects/lib/%.o: lib_srcs/%.c
	cc -Wall -Wextra -Werror -I./headers -c $< -o $@


objects/pipex/%.o: pipex_srcs/%.c
	cc -Wall -Wextra -Werror -I./headers -c $< -o $@

clean: 
	rm -f objects/lib/*.o
	rm -f objects/pipex/*.o

fclean: clean
	rm -f $(LIB_NAME) $(EXEC_NAME)

re: fclean 
	make all

.PHONY: clean re fclean all