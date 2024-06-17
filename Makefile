# can you make the following makefile :

# NAME	= so_long

# PATH_LIBFT	= libft
# LIBFT	= ${PATH_LIBFT}/libft.a

# PATH_MLX = minilbx
# MLX = ${PATH_MLX}/libmlx.a

# L_FLAGS	= -lX11 -lXext -lm

# PATH_SRCS	= srcs
# SRCS	= ${PATH_SRCS}/main.c	\
# 		${PATH_SRCS}/maps.c	\
# 		${PATH_SRCS}/check_errors.c \
# 		${PATH_SRCS}/movement.c \
# 		${PATH_SRCS}/flood_fill.c \
# 		${PATH_SRCS}/exit.c \
# 		${PATH_SRCS}/text.c \
# 		${PATH_SRCS}/images.c \
# 		${PATH_SRCS}/check_maps.c \
# 		${PATH_SRCS}/check_maps_2.c \
# 		${PATH_SRCS}/free.c \
		
		
# OBJS	= ${SRCS:.c=.o}

# CC	= cc

# C_FLAGS	= -Wall -Werror -Wextra -g

# RM	= rm -f

# all: ${LIBFT} ${MLX} ${NAME}

# ${NAME}: ${OBJS}
# 		${CC} ${C_FLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX} ${L_FLAGS}
# 		clear
# 		@toilet COMPILED -F border -f future

# ${LIBFT}:
# 		make -C ${PATH_LIBFT}
# 		clear
# 		@toilet LIBFT -F border -f future

# ${MLX}:
# 		make -C ${PATH_MLX}
# 		clear
# 		@toilet MLX -F border -f future

# .c.o:
# 	${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

# clean:
# 		make -C ${PATH_LIBFT} clean
# 		make -C ${PATH_MLX} clean
# 		${RM} ${OBJS}
# 		clear
# 		@toilet CLEAN -F border -f future

# fclean:	clean
# 		make -C ${PATH_LIBFT} fclean
# 		${RM} ${NAME}
# 		clear
# 		@toilet FCLEAN -F border -f future

# norminette:
# 		norminette srcs
# 		norminette includes
# 		@toilet NORMINETTE -F border -f future

# re:	fclean all

# .PHONY:	all clean fclean re


# Looks like that :

# #----		Project		----#
# NAME		=	so_long

# #----		Compiler		----#
# CC			=	clang
# CC_FLAGS	=	-Wall -Wextra -Werror

# #----		Commands		----#
# RM			=	rm -rf

# #----		Directories		----#
# OBJ_DIR		=	.objFiles
# SRC_DIR		=	srcs
# INC_DIR		=	includes
# LIBFT_DIR	=	libft

# #----		Files			----#
# SRC_FILES	:=  $(shell find $(SRC_DIR) -name "*.c")
# OBJ_FILES	:=  $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
# INC_FILES	:=  $(wildcard $(INC_DIR)/*.h)

# #----		Colors			----#
# GREEN		=	\e[92;5;118m
# YELLOW		=	\e[93;5;226m
# RESET		=	\e[0m

# #----		Progress bar	----#
# TOTAL		:=  $(words $(SRC_FILES))
# COUNT		:=  0

# #----		Library			----#
# LIBFT		=	$(LIBFT_DIR)/libft.a
# LIBFT_INC	=	$(LIBFT_DIR)/includes

# .PHONY: all clean fclean re

# #----		Rules			----#
# all: $(LIBFT) $(NAME)

# $(NAME): $(OBJ_FILES)
# 	 @$(CC) ${CC_FLAGS} $(OBJ_FILES) -L$(LIBFT_DIR) ${MLX} ${L_FLAGS} -lft -o $(NAME)
# 	 @printf "\n\n$(GREEN) - Executable ready: $(NAME)\n$(RESET)"

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
# 	 @mkdir -p $(dir $@)
# 	 @$(CC) $(CC_FLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -c $< -o $@
# 	 @$(eval COUNT=$(shell expr $(COUNT) + 1))
# 	 @$(eval PERCENT=$(shell expr $(COUNT) \* 100 / $(TOTAL)))
# 	 @printf "$(GREEN) - Compiling: [%-0s] %d%%$(RESET)\r" "$$(printf '▉%.0s' $$(seq 1 $$(expr $(PERCENT) \* 50 / 100)))" $(PERCENT)

# $(LIBFT):
# 	 @make -C $(LIBFT_DIR)

# clean:
# 	 @$(RM) $(OBJ_DIR)
# 	 @make -C $(LIBFT_DIR) clean
# 	 @printf "$(YELLOW) - Object files removed.\n$(RESET)"

# fclean: clean
# 	 @$(RM) $(NAME)
# 	 @make -C $(LIBFT_DIR) fclean
# 	 @printf "$(YELLOW) - Executable removed: $(NAME)\n\n$(RESET)"

# re: fclean all

#----        Project        ----#
NAME        =    so_long

#----        Compiler        ----#
CC            =    clang
CC_FLAGS    =    -Wall -Wextra -Werror

#----        Commands        ----#
RM            =    rm -rf

#----        Directories        ----#
OBJ_DIR        =    .objFiles
SRC_DIR        =    srcs
INC_DIR        =    includes
LIBFT_DIR    =    libft
MLX_DIR     =    minilbx

#----        Files            ----#
SRC_FILES    :=  $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES    :=  $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
INC_FILES    :=  $(wildcard $(INC_DIR)/*.h)

#----        Libraries        ----#
LIBFT        =    $(LIBFT_DIR)/libft.a
MLX            =    $(MLX_DIR)/libmlx.a
LIBFT_INC    =    $(LIBFT_DIR)/includes
L_FLAGS        =    -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

#----        Colors            ----#
GREEN        =    \e[92;5;118m
YELLOW        =    \e[93;5;226m
RESET        =    \e[0m

#----        Progress bar    ----#
TOTAL        :=  $(words $(SRC_FILES))
COUNT        :=  0

.PHONY: all clean fclean re norminette

#----        Rules            ----#
all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ_FILES)
	 @$(CC) ${CC_FLAGS} $(OBJ_FILES) -L$(LIBFT_DIR) ${L_FLAGS} -I$(MLX_DIR) -I$(INC_DIR) -lft -o $(NAME)
	 @printf "\n\n$(GREEN) - Executable ready: $(NAME)\n$(RESET)"
	 @toilet COMPILED -F border -f future

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	 @mkdir -p $(dir $@)
	 @$(CC) $(CC_FLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -I $(MLX_DIR) -c $< -o $@
	 @$(eval COUNT=$(shell expr $(COUNT) + 1))
	 @$(eval PERCENT=$(shell expr $(COUNT) \* 100 / $(TOTAL)))
	 @printf "$(GREEN) - Compiling: [%-0s] %d%%$(RESET)\r" "$$(printf '▉%.0s' $$(seq 1 $$(expr $(PERCENT) \* 50 / 100)))" $(PERCENT)

$(LIBFT):
	 @make -C $(LIBFT_DIR)
	 @clear
	 @toilet LIBFT -F border -f future

$(MLX):
	 @make -C $(MLX_DIR)
	 @clear
	 @toilet MLX -F border -f future

clean:
	 @$(RM) $(OBJ_DIR)
	 @make -C $(LIBFT_DIR) clean
	 @make -C $(MLX_DIR) clean
	 @printf "$(YELLOW) - Object files removed.\n$(RESET)"
	 @toilet CLEAN -F border -f future

fclean: clean
	 @$(RM) $(NAME)
	 @make -C $(LIBFT_DIR) fclean
	 @printf "$(YELLOW) - Executable removed: $(NAME)\n\n$(RESET)"
	 @toilet FCLEAN -F border -f future

norminette:
	 norminette srcs
	 norminette includes
	 @toilet NORMINETTE -F border -f future

re: fclean all
