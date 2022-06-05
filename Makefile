NAME				=	so_long

HEADER_FILE			=	-I include -I libft -I mlx_linux

HEADER_FILE_BONUS	=	-I bonus/include_bonus -I libft -I mlx_linux

SRCS				=	main.c check_error.c check_map.c game.c game_utils.c move.c

SRCS_BONUS			=	main_bonus.c check_error_bonus.c check_map_bonus.c game_bonus.c game_utils_bonus.c move_bonus.c animation_bonus.c

OBJS				=	${addprefix srcs/,${SRCS:.c=.o}}

OBJS_BONUS			=	${addprefix bonus/,${SRCS_BONUS:.c=.o}}

CC					=	gcc

MLX_FLAGS			=	-lm -lmlx -lXext -lX11

CFLAGS				=	-Wall -Werror -Wextra -g #-fsanitize=address

LD_FLAGS			=	-L libft -L mlx_linux

ifdef WITH_BONUS
HEAD				=	${HEADER_FILE_BONUS}
OBJ					=	${OBJS_BONUS}
else
HEAD				=	${HEADER_FILE}
OBJ					=	${OBJS}
endif

${NAME}				:	${OBJ}
					make -C libft
					make -C mlx_linux
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJ} -o ${NAME} -lft ${MLX_FLAGS}

all					:	${NAME}

.c.o				:	${HEAD}
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean				:
					make clean -C libft
					make clean -C mlx_linux
					@rm -rf ${OBJS_BONUS} ${OBJS}

fclean				:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re					:	fclean all

bonus				:	${NAME}
					${MAKE} WITH_BONUS=1

.PHONY				:	all clean fclean re