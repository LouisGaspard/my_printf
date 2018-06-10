##
## EPITECH PROJECT, 2017
## makefile unitaire
## File description:
## makefile unitaire
##

SRC_DIR		=	$(realpath ../src)

SRC		=	$(SRC_DIR)/my_printable.c		\
			$(SRC_DIR)/my_printf.c			\
			$(SRC_DIR)/my_format.c			\
			$(SRC_DIR)/my_flag.c			\
			$(SRC_DIR)/my_print_pointer.c		\
			$(SRC_DIR)/my_putchar.c			\
			$(SRC_DIR)/my_put_nbr.c			\
			$(SRC_DIR)/my_put_nbr_plus.c		\
			$(SRC_DIR)/my_put_nbr_binary.c		\
			$(SRC_DIR)/my_put_nbr_hexa.c		\
			$(SRC_DIR)/my_put_nbr_hexa_cap.c	\
			$(SRC_DIR)/my_put_nbr_octal.c		\
			$(SRC_DIR)/my_put_nbr_unsigned.c	\
			$(SRC_DIR)/my_putstr.c			\
			$(SRC_DIR)/my_revstr.c			\
			$(SRC_DIR)/my_strlen.c

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/tests_format.c		\
			$(SRC_UT_DIR)/tests_put_nbr.c		\
			$(SRC_UT_DIR)/tests_put_nbr_binary.c	\
			$(SRC_UT_DIR)/tests_put_nbr_hexa.c	\
			$(SRC_UT_DIR)/tests_put_nbr_hexa_cap.c	\
			$(SRC_UT_DIR)/tests_put_nbr_octal.c	\
			$(SRC_UT_DIR)/tests_put_nbr_plus.c	\
			$(SRC_UT_DIR)/tests_put_nbr_un.c	\
			$(SRC_UT_DIR)/tests_str.c		\
			$(SRC_UT_DIR)/tests_pointer.c		\
			$(SRC_UT_DIR)/tests_return_put_nbr.c	\
			$(SRC_UT_DIR)/tests_return_put_nbr_second.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage

CFLAGS		+=	-I ../include/

LDFLAGS		=	-lcriterion -lgcov

NAME		=	units

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*.g*
		rm -f $(SRC_UT_DIR)/*g*

fclean:		clean
		rm -f $(NAME)

re:		fclean all
