CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = megaphone

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all