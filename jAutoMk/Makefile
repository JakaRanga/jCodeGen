SRCS	=	auto_makefile.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	jAutoMakefile

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LDFLAGS	=	-L./libs -lmy -lgnl

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
