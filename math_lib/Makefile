# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:05:33 by mcerchi           #+#    #+#              #
#    Updated: 2022/03/19 16:05:45 by mcerchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	math_lib.a

SRC		=	basic_math.c math_mult_n_div.c newton.c\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -rf

CFLAGS	=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJ)
			ar rc ${NAME} ${OBJ}

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)
