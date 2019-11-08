INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g

all: $(BIN)/ejemplo_uso_pila_max

$(BIN)/ejemplo_uso_pila_max : $(OBJ)/ejemplo_uso_pila_max.o
	$(CXX) -o $(BIN)/ejemplo_uso_pila_max $(OBJ)/ejemplo_uso_pila_max.o

$(OBJ)/ejemplo_uso_pila_max.o : $(SRC)/ejemplo_uso_pila_max.cpp 
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/ejemplo_uso_pila_max.o $(SRC)/ejemplo_uso_pila_max.cpp

#$(OBJ)/pila_max.o : $(INC)/pila_max.h $(INC)/cola.h $(INC)/pareja.h $(SRC)/pila_max.cpp
#	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pila_max.o $(SRC)/pila_max.cpp

#$(OBJ)/cola.o : $(INC)/cola.h $(SRC)/cola.cpp
#	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cola.o $(SRC)/cola.cpp

#$(OBJ)/pareja.o : $(INC)/pareja.h $(SRC)/pareja.cpp
#	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pareja.o $(SRC)/pareja.cpp

clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o