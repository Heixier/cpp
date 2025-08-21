CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD
NAME = basic

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(LIGHT_BLUE)"$(NAME) has been compiled!"$(END)"

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[0;33m
BLUE = "033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
LIGHT_GRAY = \033[0;37m
DARK_GRAY = \033[1;30m
LIGHT_RED = \033[1;31m
LIGHT_GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[38;5;117;1m
LIGHT_PURPLE = \033[1;35m
LIGHT_CYAN = \033[1;36m
LIGHT_WHITE = \033[1;37m
BOLD = \033[1m
FAINT = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
NEGATIVE = \033[7m
CROSSED = \033[9m
END = \033[0m
HIDE = \u001B[?25l
SHOW = \u001B[?25h