NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/operations.c src/short_algorithms.c src/handler.c src/push_swap.c src/stack_sort.c src/utils.c src/double_op.c
PRINTF_LIB = ft_printf/libftprintf.a
OBJ = ${SRC:.c=.o}
RM	= rm -f

all: printf $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $@ $(PRINTF_LIB)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	@${RM} ${NAME}
	make -C ft_printf fclean

re:		fclean all

.PHONY:	all clean fclean re prinf

################################################


printf: $(PRINTF_LIB)

$(PRINTF_LIB):
	make -C ft_printf
