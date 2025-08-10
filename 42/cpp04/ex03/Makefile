CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = ff_XLII

GOODS = $(addprefix smuggled_goods/, Fire.cpp Bolt.cpp Demi.cpp Quake.cpp)

SRCS = main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp $(GOODS)

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

eval:
	make fclean
	make CXXFLAGS="$(CXXFLAGS) -D EVAL"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
