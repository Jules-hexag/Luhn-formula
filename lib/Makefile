SRC	=	my_getnbr.c \
		my_str_to_word_array.c \
		my_str_isnum.c \
		my_strlen.c \
		my_printf/my_printf_char.c \
		my_printf/my_printf_dbl_sequel.c \
		my_printf/my_printf_dbl.c \
		my_printf/my_printf_dbl_suite.c \
		my_printf/my_printf_int.c \
		my_printf/my_printf_parse.c \
		my_printf/my_printf_str.c \
		my_printf/my_printf_uint_sequel.c \
		my_printf/my_printf_uint.c \
		my_printf/my_printf_utils.c \
		my_printf/my_printf.c \
		my_printf/my_putstr.c \
		my_printf/my_strlen.c \
		my_printf/my_compute_power_rec.c \
		my_printf/my_printf_per.c \
		my_printf/my_strncmp.c \
		my_printf/my_printf_getpad.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../include
	cp my.h ../include

clean:
	@$(RM) -vf $(OBJ)
	@$(RM) -vf $(NAME)

fclean: clean
	## rm -f ../../include/my.h
	@$(RM) -vf ../libmy.a

re: fclean all

.PHONY:	all clean
