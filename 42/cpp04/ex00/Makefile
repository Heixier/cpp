CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = zoo0

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
