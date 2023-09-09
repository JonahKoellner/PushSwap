CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = ft_printf.h
FILES = ft_printf.c specifier_interpreter.c specifier_handling.c
LIBFT_SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
LIBFT = libft/libft.a
SRCFILES = ft_substr.c
OBJS = ${FILES:.c=.o}
LIBFTOBJS = ${LIBFT_SRC:.c=.o}
RM = rm -f
NAME = libftprintf.a
TESTFILES = ft_printf_tester.c

Black = \033[3;30m
Red = \033[3;31m
Green = \033[3;32m
Yellow  = \033[3;33m
Blue = \033[0334m
Purple = \033[3;35m
Cyan = \033[3;36m
White  = \033[3; 7m
Update = \033[0K\r
Reset = \e[0m

%.o: %.c ${DEPS}
	@printf "${Yellow}Compiling $@${Reset}${Update}"
	@sleep .5
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@printf "${Yellow}Remaking libft${Reset}${Update}"
	@make -C libft/
	@printf "${Yellow}Extracting libft library${Reset}${Update}"
	@cp ${LIBFT} ${NAME}

#ar -t ${NAME}
	@printf "${Yellow}Adding Objects to library${Reset}${Update}"
	@ar -rcs ${NAME} ${OBJS}
	@printf "${Update}${Green}Build Library📚${Reset}\n"
#ar -t ${NAME}

all:	${NAME}
	@printf "${Green}Successfully Compiled 🎉${Reset}\n"

clean:
	@printf "${Red}Cleaning${Reset}\n"
	@${RM} ${OBJS}

fclean:
	@printf "${Red}Full clean${Reset}\n"
	@make clean
	@make tclean
	@make -C libft fclean
	@${RM} ${NAME}

re:
	@printf "${Purple}ReMaking${Reset}\n"
	@make fclean
	@make all

tclean:
	@printf "${Red}Cleaning Tests${Reset}\n"
	@${RM} ${TESTFILES:.c=.o}
	@${RM} a.out

test:
	@printf "${Cyan}Testing${Reset}\n"
	@make all
	@${CC} ${CFLAGS} ${NAME} ${TESTFILES} && ./a.out

.PHONY: all clean fclean re
