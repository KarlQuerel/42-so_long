NAME	= so_long

PATH_LIBFT	= libft
LIBFT	= ${PATH_LIBFT}/libft.a

PATH_MLX = minilbx
MLX = ${PATH_MLX}/libmlx.a

L_FLAGS	= -lX11 -lXext -lm

PATH_SRCS	= srcs
SRCS	= ${PATH_SRCS}/so_long.c	\
		${PATH_SRCS}/maps.c	\
		${PATH_SRCS}/check_errors.c \
		${PATH_SRCS}/movement.c \
		
OBJS	= ${SRCS:.c=.o}

CC	= cc

C_FLAGS	= -Wall -Werror -Wextra -g

RM	= rm -f

all: ${LIBFT} ${MLX} ${NAME}

${NAME}: ${OBJS}
		${CC} ${C_FLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX} ${L_FLAGS}
		@figlet COMPILED -f term -F border --gay

${LIBFT}:
		make -C ${PATH_LIBFT}
		@figlet LIBFT -f term -F border --gay

${MLX}:
		make -C ${PATH_MLX}
		@figlet MLX -f term -F border --gay

.c.o:
	${CC} ${C_FLAGS} -c $< -o ${<:.c=.o} -I ${PATH_LIBFT} -I ${PATH_SRCS}

clean:
		make -C ${PATH_LIBFT} clean
		make -C ${PATH_MLX} clean
		${RM} ${OBJS}
		@figlet CLEANED -f term -F border --gay

fclean:	clean
		make -C ${PATH_LIBFT} fclean
		${RM} ${NAME}
		@figlet F_CLEANED -f term -F border --gay

re:	fclean all

.PHONY:	all clean fclean re
