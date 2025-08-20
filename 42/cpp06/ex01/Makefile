CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD
NAME = serializer

SRCS = main.cpp Serializer.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[38;5;117;1m%s has been compiled!\n\033[0m" $(NAME)

segfault:
	@printf "\033[38;5;117;1mrecompiling %s with segfault header!\n\033[0m" $(NAME)
	@make -s fclean
	@make -s CXXFLAGS="$(CXXFLAGS) -D SEGFAULT"

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re segfault