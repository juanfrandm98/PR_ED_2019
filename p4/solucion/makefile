INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g

all: $(BIN)/usodiccionario

$(BIN)/usodiccionario : $(OBJ)/usodiccionario.o
	$(CXX) -std=c++11 $(OBJ)/usodiccionario.o -o $(BIN)/usodiccionario

$(OBJ)/usodiccionario.o : $(SRC)/usodiccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/usodiccionario.o $(SRC)/usodiccionario.cpp

clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o