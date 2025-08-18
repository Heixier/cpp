CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD
NAME = scalar_convert

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re