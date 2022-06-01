# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 14:41:30 by mchatzip          #+#    #+#              #
#    Updated: 2022/06/01 19:54:34 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

NAME	= containers

SRC		= main.cpp

MAP_SRC	= map_main.cpp

OBJ		= ${SRC:.c=.o}

MAP_OBJ	= ${MAP_SRC:.c=.o}

all:		$(NAME)

map:	$(MAP_OBJ)
		$(CC) -g $(CFLAGS) -o map $(MAP_OBJ)

$(NAME):	$(OBJ)
			$(CC) -g $(CFLAGS) -o $(NAME) $(OBJ)

clean:		
			$(RM) *.o
			$(RM) -r containers.dSYM map.dSYM

fclean:		clean
			$(RM) $(NAME); $(RM) map

re:		fclean all

re_map: fclean map

.PHONY: all clean fclean re re_map