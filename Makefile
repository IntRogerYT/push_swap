NAME = push_swap

CC = cc
CFLAGS = -I$(INCLUDES_DIR)
INCLUDES_DIR = includes
SRCS_DIR = src
OBJS_DIR = objs

DIRS = $(OBJS_DIR) $(OBJS_DIR)/moves $(OBJS_DIR)/validate $(OBJS_DIR)/libft $(OBJS_DIR)/utils

SRCS_LIBFT = $(SRCS_DIR)/libft/ft_strlen.c \
			 $(SRCS_DIR)/libft/ft_strdup.c \
			 $(SRCS_DIR)/libft/ft_split.c \
			 $(SRCS_DIR)/libft/ft_substr.c \
			 $(SRCS_DIR)/libft/ft_atol.c
SRCS_MOVES = $(SRCS_DIR)/moves/push.c \
			 $(SRCS_DIR)/moves/swap.c \
			 $(SRCS_DIR)/moves/rotate.c \
			 $(SRCS_DIR)/moves/reverse_rotate.c
SRCS_VALIDATE = $(SRCS_DIR)/validate/check_valid_input.c
SRCS_UTILS = $(SRCS_DIR)/utils/free_functions.c
SRC_MAIN = $(SRCS_DIR)/main.c

SRCS = $(SRC_MAIN) $(SRCS_LIBFT) $(SRCS_MOVES) $(SRCS_VALIDATE) $(SRCS_UTILS)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(DIRS) $(OBJS) $(INCLUDES_DIR)/push_swap.h Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
