# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 16:27:08 by estoffel          #+#    #+#              #
#    Updated: 2022/05/16 16:36:30 by estoffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g3 -pthread

ICLD	=	-Lmlx/ -lmlx -lXext -lX11

SRC		=	\
			main.c		\

OBJ		=	$(addprefix ./src/,$(SRC:%.c=%.o))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ) ./libft/libft.a
	@make -s -C ./mlx/ all
	@cp ./mlx/libmlx_Linux.a $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(ICLD) -Llibft -lft
	clear
	@echo "🌼\033[1;97m C U B 3 D  C R E A T E D  W I T H  S U C C E S S 🌼\e[0m"
	@printf "\n"

./libft/libft.a:
	make $(@F) -C $(@D)

./mlx/libmlx_Linux.a:
	make $(@F) -C $(@D)

clean:
	@rm -f $(OBJ)
	@make $@ -C ./mlx/
	@make $@ -C ./libft/
	clear
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"

fclean:
	@rm -f $(OBJ)
	$(RM) $(NAME)
	@make clean -C ./mlx/
	@make $@ -C ./libft/
	clear
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re