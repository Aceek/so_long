NAME			=	so_long

SRCS			=	main.c check_error.c check_map.c

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx_linux

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I include -I libft -I mlx_linux

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx_linux
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

val				:	${NAME}
					valgrind \
					--leak-check=full --tool=memcheck \
					--show-reachable=yes \
					--track-fds=yes \
					--errors-for-leak-kinds=all \
					--show-leak-kinds=all ./${NAME}

clean			:
					make clean -C libft
					make clean -C mlx_linux
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re