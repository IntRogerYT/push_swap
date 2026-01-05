NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)
INCLUDES_DIR = includes
SRCS_DIR = src
OBJS_DIR = objs

SRCS_LIBFT = $(SRCS_DIR)/libft/ft_strlen.c \
			 $(SRCS_DIR)/libft/ft_strdup.c
SRCS_MOVES = $(SRCS_DIR)/moves/push.c \
			 $(SRCS_DIR)/moves/swap.c \
			 $(SRCS_DIR)/moves/rotate.c \
			 $(SRCS_DIR)/moves/reverse_rotate.c

SRCS = $(SRCS_LIBFT) $(SRCS_MOVES)

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
