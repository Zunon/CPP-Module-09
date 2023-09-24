# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 10:21:51 by kalmheir          #+#    #+#              #
#    Updated: 2023/09/19 10:22:24 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	PmergeMe
SRCS		:=	main.cpp PmergeMe.cpp
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