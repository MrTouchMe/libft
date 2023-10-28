# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 07:37:24 by dgiurgev          #+#    #+#              #
#    Updated: 2023/10/28 04:30:33 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

SRCS			= $(wildcard *.c)

OBJ_DIR			= ./obj/

OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
# 					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
# 					ft_lstmap.c ft_lstsize.c ft_lstnew.c

# BONUS_OBJS		= $(BONUS:%.c=%.o)



all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	%.c
ifneq ($(OBJ_DIR),)
	@mkdir -p $(OBJDIR)
endif
	@$(CC) $(CFLAGS) -o $@ -c $<

# ./%.o: ./%.c
# 				@echo "Compiling $<"
# 				@$(CC) $(FLAGS) -c $< -o $@
# 				@echo "Done!"

# $(BONUS_OBJS):	./%.o: ./%.c
# 				@echo "Compiling $<"
# 				@$(CC) $(FLAGS) -c $< -o $@
# 				@echo "Done!"



clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

# bonus:			$(BONUS_OBJS)
# 				@ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
