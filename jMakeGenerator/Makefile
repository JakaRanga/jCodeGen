##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

SRCS	=	AutoMk.cpp	\
		main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	jAutoMk

CC	=	g++

LDFLAGS	=	-W -Wall -Wextra -Werror

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

re:		fclean all

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

.PHONY:		all clean fclean re
