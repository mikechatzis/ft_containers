# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 14:41:30 by mchatzip          #+#    #+#              #
#    Updated: 2022/06/10 19:09:33 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

NAME	= vector

VECTOR_SRC	= vector_main.cpp

MAP_SRC	= map_main.cpp

VECTOR_OBJ	= ${VECTOR_SRC:.c=.o}

MAP_OBJ	= ${MAP_SRC:.c=.o}

all:		$(NAME)

map:	$(MAP_OBJ)
		$(CC) -g $(CFLAGS) -o map $(MAP_OBJ)

vector: $(NAME)

$(NAME):	$(VECTOR_OBJ)
			$(CC) -g $(CFLAGS) -o $(NAME) $(VECTOR_OBJ)

clean:		
			$(RM) *.o
			$(RM) -r containers.dSYM map.dSYM vector.dSYM

fclean:		clean
			$(RM) $(NAME); $(RM) map

re:		fclean all

re_map: fclean map

.PHONY: all clean fclean re re_map