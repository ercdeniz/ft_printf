NAME = libftprintf.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RANLIB = ranlib
SRCS_MAND = ft_printf.c \
			ft_printf_char_utilities.c \
			ft_printf_int_utilities.c

OBJS_MAND = $(SRCS_MAND:.c=.o)

$(NAME): $(OBJS_MAND)
	$(AR) $(NAME) $(OBJS_MAND)
	$(RANLIB) $(NAME)
	clear
	@echo "\n\033[1;3;37;44m $(NAME) built ✅\033[0m\n"

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_MAND)
	clear
	@echo "\n\033[1;3;31;40;91m Object files removed 👋\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	clear
	@echo "\n\033[1;3;31;40;91m $(NAME) removed 👋\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
