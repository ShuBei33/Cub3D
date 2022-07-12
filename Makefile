# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 16:27:08 by estoffel          #+#    #+#              #
#    Updated: 2022/07/11 09:01:20 by lzaccome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -MMD

ICLD	=	-Lmlx/  -lmlx -lXext -lX11 -lm

SRC		=	\
			black_magic.c	\
			check_map.c		\
			direction.c		\
			draw_stuff.c	\
			fld_fill.c		\
			free_all.c		\
			ft_onlysplit.c	\
			horizon_inter.c	\
			loading_data.c	\
			main.c			\
			manage_txtr.c	\
			mini_calc.c		\
			mini_map.c		\
			movements.c		\
			pars_map.c		\
			pars_textures.c	\
			parsing.c		\
			print.c			\
			utils.c			\
			vertc_inter.c	\
			wolf.c			\

OBJ		=	$(addprefix ./srcs/,$(SRC:%.c=%.o))

DEP		=	$(OBJ:%.o=%.d)

all:	$(NAME)

-include $(DEP)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

$(NAME): $(OBJ) ./libft/libft.a
	make -s -C ./mlx/ all
	cp ./mlx/libmlx_Linux.a $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(ICLD) -Llibft -lft -lm
	@printf "\n"
	@printf "\n"
	@echo "🌼\033[1;97m C U B 3 D  C R E A T E D  W I T H  S U C C E S S 🌼\e[0m"
	@printf "\n"
	@printf "\n"

./libft/libft.a:
	make $(@F) -C $(@D)

./mlx/libmlx_Linux.a:
	make $(@F) -C $(@D)

clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	make $@ -C ./mlx/
	make $@ -C ./libft/
	@printf "\n"
	@printf "\n"
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"
	@printf "\n"

fclean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) $(NAME)
	make clean -C ./mlx/
	make $@ -C ./libft/
	@printf "\n"
	@printf "\n"
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re
