
NAME = ft_irc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98 -g

OBJET = $(SRC:.cpp=.o)
DEPS = $(OBJET:.o=.d)

SRC = ft_irc.cpp		\
	Client.cpp			\
	Server.cpp			\
	CommandHandling.cpp \
	Join.cpp			\
	PrivateMsg.cpp		\


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
