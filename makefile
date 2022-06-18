# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 14:41:30 by mchatzip          #+#    #+#              #
#    Updated: 2022/06/18 13:00:52 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

RM		= rm -f

NAME	= vector

VECTOR_SRC	= vector_main.cpp

MAP_SRC	= map_main.cpp

UTILS_SRC	= utils_showcase.cpp

VECTOR_OBJ	= ${VECTOR_SRC:.c=.o}

MAP_OBJ	= ${MAP_SRC:.c=.o}

UTILS_OBJ	= ${UTILS_SRC:.c=.o}

all:		 $(NAME)

map:	$(MAP_OBJ)
		$(CC) -g $(CFLAGS) -o map $(MAP_OBJ)
		$(CC) -g $(CFLAGS) -o stl_map stl_map_main.cpp

vector: $(VECTOR_OBJ)
		$(CC) -g $(CFLAGS) -o vector $(VECTOR_OBJ)
		$(CC) -g $(CFLAGS) -o stl_vector stl_vector_main.cpp

stack: 
		$(CC) -g $(CFLAGS) -o stack stack_main.cpp;
		$(CC) -g $(CFLAGS) -o stl_stack stl_stack_main.cpp;

utils: $(UTILS_OBJ)
		$(CC) -g $(CFLAGS) -o utils $(UTILS_OBJ)

# $(NAME):	echo "nothing to see here"

clean:		
			$(RM) *.o *.comp
			$(RM) -r containers.dSYM map.dSYM vector.dSYM utils.dSYM stl_map.dSYM stl_vector.dSYM stack.dSYM stl_stack.dSYM

fclean:		clean
			$(RM) $(NAME); $(RM) map utils stl_map stl_vector stack stl_stack

re:		fclean all

re_map: fclean map

re_vector: fclean vector

re_stack: fclean stack

.PHONY: all clean fclean re re_map re_vector