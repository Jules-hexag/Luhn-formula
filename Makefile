SRC 	=	src/main.c \

OBJ		= 	$(SRC:.c=.o)

NAME 	=	verify_numbers

LIB 	=	lib/libmy.a

LDFLAGS = 	-L./lib

LDLIBS	=	-lmy

CFLAGS	=	-I./include -O2 -Wall -Wextra

CFLAGS_DEBUG	=	-I./include -ggdb3 -fsanitize=address

CFLAGS_TESTS	=	-I./include/ -ggdb3 -O0 --coverage

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIB):
	make -C lib/

debug: CFLAGS=$(CFLAGS_DEBUG)
debug: re

clean:
	@$(RM) -vf $(OBJ)
	@$(RM) -vf $(NAME)

fclean: clean
	@$(RM) -vf $(NAME)
	make fclean -C lib/

re: fclean all

.PHONY: all clean fclean re
