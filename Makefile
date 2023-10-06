# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 18:44:52 by dgiurgev          #+#    #+#              #
#    Updated: 2023/10/06 23:59:43 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.SILENT:
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror 
CC = cc

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
OBJS_B = $(SRCS_B:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(NAME) $(OBJS)

all: $(NAME)
	echo "$(GREEN)Libft Mandatory Compiled$(DEF_COLOR)"

# bonus: $(OBJS_B)
# 	ar rcs $(NAME) $(OBJS_B)
# 	echo "Libft Bonus Compiled"

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	echo "$(RED)Object Files are deleted$(DEF_COLOR)"

fclean: clean
	rm -rf $(NAME)
	echo "Everything is clean"

re: fclean all bonus

.PHONY: all clean fclean bonus re