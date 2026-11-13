CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

FT_PRINTF_DIR = ../ft_printf
LIBFT_DIR = ../Libft

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

SRC = main.c \
      operations/push.c \
      operations/swap.c \
      operations/rotate.c \
      operations/reverse_rotate.c \
      parsing/check_duplicates.c \
      parsing/parse_args.c \
      parsing/parse_number.c \
      sorting/sort_radix.c \
      sorting/sort_small.c \
      sorting/sort_utils.c \
      stack/stack_init.c \
      stack/stack_utils.c \
      stack/stack_free.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean

