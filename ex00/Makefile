# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 14:30:35 by kalmheir          #+#    #+#              #
#    Updated: 2023/09/18 14:35:50 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	btc
SRCS		:=	main.cpp BitcoinExchange.cpp
OBJS		:=	$(SRCS:cpp=o)
CPP			:=	c++
CPPFLAGS	:=	-Wall -Wextra -Werror -std=c++98
RM			:=	rm -f

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)