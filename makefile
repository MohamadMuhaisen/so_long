# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 15:55:13 by mmuhaise          #+#    #+#              #
#    Updated: 2024/07/10 20:24:45 by mmuhaise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-g -Wall -Wextra -Werror

INCLUDE		=	-I/usr/include -Imlx

MLX_DIR		= ./mlx

MLX_LIB		= $(MLX_DIR)/libmlx_$(UNAME).a

MLX_FLAGS	= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIB			=	-L./libft -lft

SRCS		=	main.c map.c errors.c errors_extended.c graphics.c controls.c

OBJS		= 	${SRCS:.c=.o}

LIBPATH		= 	libft/

all: $(MLX_LIB) $(NAME)

${NAME}:	${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB}  $(MLX_FLAGS) -o $@

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
			make clean -C ${LIBPATH}
			rm -f ${OBJS}

fclean:			clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re