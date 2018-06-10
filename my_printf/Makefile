##
## EPITECH PROJECT, 2017
## lib
## File description:
## lib
##

NAME	= 	libmy.a

CC	= 	gcc -c

RM	= 	rm -f

SRCS	= 	./src/my_printable.c		\
		./src/my_printf.c		\
		./src/my_flag.c			\
		./src/my_format.c		\
		./src/my_print_pointer.c	\
		./src/my_putchar.c		\
		./src/my_put_nbr_binary.c	\
		./src/my_put_nbr.c		\
		./src/my_put_nbr_plus.c		\
		./src/my_put_nbr_hexa.c		\
		./src/my_put_nbr_hexa_cap.c	\
		./src/my_put_nbr_octal.c	\
		./src/my_put_nbr_unsigned.c	\
		./src/my_putstr.c		\
		./src/my_revstr.c		\
		./src/my_strlen.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS 	= 	-I ./include

CFLAGS 	+= 	-W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(SRCS) $(LDFLAGS) $(CFLAGS)
	 ar rc $(NAME) $(OBJS)
	 rm *.o

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
