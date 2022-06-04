NAME			=	so_long

NAME_BONUS		=	so_long_bonus

SRCS			=	main.c check_error.c check_map.c game.c game_utils.c move.c

SRCS_BONUS		=	main_bonus.c check_error_bonus.c check_map_bonus.c game_bonus.c game_utils_bonus.c move_bonus.c

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

OBJS_BONUS		=	${addprefix bonus/,${SRCS_BONUS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx_linux

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I include -I libft -I mlx_linux

HEAD_BONUS		=	-I include_bonus -I libft -I mlx_linux

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx_linux
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

bonus			:	${NAME_BONUS}

.c.o			:
					${CC} ${CFLAGS} ${HEAD_BONUS} -c $< -o ${<:.c=.o}

${NAME_BONUS}	:	${OBJS_BONUS}
					make -C libft
					make -C mlx_linux
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_BONUS} -o ${NAME_BONUS} -lft ${MLX_FLAGS}

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
					@rm -rf ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}
					@rm -rf ${NAME_BONUS}

re				:	fclean all

.PHONY			:	all clean fclean re