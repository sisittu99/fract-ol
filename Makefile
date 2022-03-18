# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:33:10 by mcerchi           #+#    #+#              #
#    Updated: 2022/03/18 15:19:35 by mcerchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC			=	fractol.c commands.c

OBJ			=	$(SRC:.c=.o)

MLX			=	./libmlx.dylib

MATH_LIB	=	./math_lib/math_lib.a

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Werror -Wextra

$(NAME)		:	$(OBJ)
				make -C ./math_lib
				make -C ./mlx
				@mv mlx/libmlx.dylib .
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(MATH_LIB)

all			:	$(NAME)

clean		:
				$(RM) $(OBJ)

clean.all	:	clean
				make clean -C ./math_lib
				make clean -C ./mlx

fclean		:	clean
				$(RM) $(OBJ)
				$(RM) $(NAME)
				$(RM) libmlx.dylib

fclean.all	:	fclean
				make fclean -C ./math_lib
				make clean -C ./mlx

re			:	fclean $(NAME)

re.all		:	fclean.all all

.PHONY		: all clean fclean re
