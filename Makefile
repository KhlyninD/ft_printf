NAME 		= 		libftprintf.a

SRC 		= 		ft_printf.c ft_putchar.c ft_putstr.c ft_putadr.c \
					ft_unsigned_putnbr_dec.c ft_putnbr_hex.c ft_putnbr_dec.c

OBJ 		=		$(patsubst %.c,%.o,$(SRC))

D_FILES 	=		$(patsubst %.c,%.d,$(SRC))

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $?

%.o 	: 	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean	:
	rm -f $(OBJ) $(D_FILES)

fclean	:	clean
	rm -f  $(NAME)

re		:	fclean all

.PHONY		: 		all clean fclean re bonus