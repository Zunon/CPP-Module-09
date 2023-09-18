# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 14:30:35 by kalmheir          #+#    #+#              #
#    Updated: 2023/09/18 18:47:22 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	RPN
SRCS		:=	main.cpp RPN.cpp
OBJS		:=	$(SRCS:cpp=o)
CPP			:=	c++
CPPFLAGS	:=	-Wall -Wextra -Werror -g3 -std=c++98
RM			:=	rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all