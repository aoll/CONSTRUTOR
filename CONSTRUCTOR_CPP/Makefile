EXEC=cons
CXX=g++
CXXFLAGS=-Wall -Werror -Wextra
SRC=class/Function.class.cpp class/Variable.class.cpp class/main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.c
	$(CXX) -o &@ -c $<

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
