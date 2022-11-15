# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 12:42:42 by svan-ass          #+#    #+#              #
#    Updated: 2022/04/19 10:40:45 by svan-ass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
			ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
			ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

BONUS_SRC	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS 	= $(BONUS_SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

ifdef WITH_BONUS
ALL_OBJS = $(OBJS) $(BONUS_OBJS)
else
ALL_OBJS = $(OBJS)
endif

NAME		= libft.a

all:		$(NAME)

$(NAME): 	$(ALL_OBJS)
	ar r $(NAME) $(ALL_OBJS)

bonus:
	$(MAKE) WITH_BONUS=1

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: 	clean 
	rm -f $(NAME) 

re:			fclean all

.PHONY: 	all bonus clean fclean re
