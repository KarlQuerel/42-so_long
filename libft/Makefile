NAME = libft.a
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
SRC = ft_atoi.c	\
	ft_bzero.c	\
	ft_calloc.c	\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_itoa.c	\
	ft_lstnew.c	\
	ft_lstadd_front.c	\
	ft_lstsize.c	\
	ft_lstlast.c	\
	ft_lstadd_back.c	\
	ft_lstdelone.c	\
	ft_lstclear.c	\
	ft_lstiter.c	\
	ft_lstmap.c	\
	ft_memset.c	\
	ft_memcpy.c	\
	ft_strlcpy.c	\
	ft_strlcat.c	\
	ft_toupper.c	\
	ft_tolower.c	\
	ft_strchr.c	\
	ft_strrchr.c	\
	ft_strncmp.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_strnstr.c	\
	ft_strdup.c	\
	ft_memmove.c	\
	ft_substr.c	\
	ft_strjoin.c	\
	ft_strlen.c	\
	ft_strtrim.c	\
	ft_split.c	\
	ft_strmapi.c	\
	ft_striteri.c	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	get_next_line_utils_bonus.c	\
	get_next_line_bonus.c	\
	ft_printf.c	\
	ft_printf_utils.c	\

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o $(<:.c=.o)

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ}

all: ${NAME}

clean :
	rm -f ${OBJ} ${OBJ_BONUS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
