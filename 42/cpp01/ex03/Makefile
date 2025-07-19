CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = lab_03

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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
