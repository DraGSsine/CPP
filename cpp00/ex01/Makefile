NAME=PhoneBook 
SRC=PhoneBook.o
FLAGS= -Wall -Wextra -Werror -std=c++98
CC=g++

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp PhoneBook.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all