CC = cc 
CFLAGS = -Wall -Werror -Wextra
RM     = rm -f

NAME = libpush.a

SRC  = 	operations/push.c operations/swap.c operations/rotate.c operations/reverse_rotate.c \
		parsing/check_duplicates.c parsing/parse_args.c parsing/parse_number.c \
		sorting/sort_radix.c sorting/sort_small.c sorting/sort_utils.c \
		stack/stack_init.c stack/stack_utils.c stack/stack_free.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
