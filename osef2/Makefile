
NAME = ft_irc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98 -g

OBJET = $(SRC:.cpp=.o)
DEPS = $(OBJET:.o=.d)

SRC = osef.cpp		\
	Server.cpp		\
	Client.cpp		\
	tools.cpp		\

all: $(NAME)

$(NAME): $(OBJET)
	$(CXX) $(CXXFLAGS) $(OBJET) -o $(NAME)

clean:
	rm -f $(OBJET) $(DEPS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}
