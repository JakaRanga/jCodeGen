##
## EPITECH PROJECT, 2018
## cgen make
## File description:
## 
##

SRCS	=	ClassGenerator.cpp	\
		main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	jClassGen

CC	=	g++

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

re:		fclean all

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

.PHONY:		all clean fclean re
