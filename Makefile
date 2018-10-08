NAME = ft_retro

FLAGS = -Wall -Wextra -Werror 

SRC =	Main.cpp \
		Game.cpp \
		Player.cpp \
		Enemies.cpp \
		Background.cpp \
		Boss.cpp \

OBJ = $(SRC:.cpp=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -o $(NAME) $(OBJ) -lncurses

%.o : %.cpp Game.hpp
	clang++ $(FLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
