NAME = PhoneBook
SRC = PhoneBook.cpp Contact.cpp main.cpp Tools.cpp
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)
Contact = Contacts.csv

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
	./$(NAME)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -f $(NAME) $(Contact)

re: fclean all
