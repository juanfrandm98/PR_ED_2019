INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g

# all: $(BIN)/usoletra $(BIN)/usoconjuntoletras $(BIN)/usodiccionario $(BIN)/usojuegoletras
all: $(BIN)/practicafinal 

# LETRA
$(BIN)/usoletra : $(OBJ)/usoletra.o $(OBJ)/letra.o
	$(CXX) -o $(BIN)/usoletra $(OBJ)/usoletra.o $(OBJ)/letra.o 

$(OBJ)/usoletra.o : $(SRC)/usoletra.cpp $(INC)/letra.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/usoletra.o $(SRC)/usoletra.cpp

$(OBJ)/letra.o : $(INC)/letra.h $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/letra.o $(SRC)/letra.cpp

# CONJUNTOLETRAS
$(BIN)/usoconjuntoletras : $(OBJ)/usoconjuntoletras.o $(OBJ)/letra.o $(OBJ)/conjuntoletras.o
	$(CXX) -o $(BIN)/usoconjuntoletras $(OBJ)/usoconjuntoletras.o $(OBJ)/letra.o $(OBJ)/conjuntoletras.o

$(OBJ)/usoconjuntoletras.o : $(SRC)/usoconjuntoletras.cpp $(INC)/letra.h $(INC)/conjuntoletras.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/usoconjuntoletras.o $(SRC)/usoconjuntoletras.cpp

$(OBJ)/conjuntoletras.o : $(SRC)/conjuntoletras.cpp $(INC)/conjuntoletras.h $(INC)/letra.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/conjuntoletras.o $(SRC)/conjuntoletras.cpp

# DICCIONARIO
$(BIN)/usodiccionario : $(OBJ)/usodiccionario.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/usodiccionario $(OBJ)/usodiccionario.o $(OBJ)/diccionario.o

$(OBJ)/usodiccionario.o : $(SRC)/usodiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/usodiccionario.o $(SRC)/usodiccionario.cpp

$(OBJ)/diccionario.o : $(INC)/diccionario.h $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

# JUEGOLETRAS
$(BIN)/usojuegoletras : $(OBJ)/usojuegoletras.o $(OBJ)/juegoletras.o $(OBJ)/diccionario.o $(OBJ)/bolsaletras.o $(OBJ)/conjuntoletras.o $(OBJ)/letra.o
	$(CXX) -o $(BIN)/usojuegoletras $(OBJ)/usojuegoletras.o $(OBJ)/juegoletras.o $(OBJ)/diccionario.o $(OBJ)/bolsaletras.o $(OBJ)/conjuntoletras.o $(OBJ)/letra.o

$(OBJ)/usojuegoletras.o : $(SRC)/usojuegoletras.cpp $(OBJ)/juegoletras.o $(OBJ)/diccionario.o $(OBJ)/bolsaletras.o $(OBJ)/conjuntoletras.o $(OBJ)/letra.o
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/usojuegoletras.o $(SRC)/usojuegoletras.cpp

$(OBJ)/juegoletras.o : $(SRC)/juegoletras.cpp $(INC)/juegoletras.h $(INC)/diccionario.h $(INC)/bolsaletras.h $(INC)/conjuntoletras.h $(INC)/letra.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/juegoletras.o $(SRC)/juegoletras.cpp

# BOLSALETRAS
$(OBJ)/bolsaletras.o : $(SRC)/bolsaletras.cpp $(INC)/bolsaletras.h $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/bolsaletras.o $(SRC)/bolsaletras.cpp

# JUEGO
$(BIN)/practicafinal : $(OBJ)/practicafinal.o $(OBJ)/juego.o $(OBJ)/juegoletras.o $(OBJ)/diccionario.o $(OBJ)/bolsaletras.o $(OBJ)/conjuntoletras.o $(OBJ)/letra.o $(OBJ)/juegocifras.o
	$(CXX) -o $(BIN)/practicafinal $(OBJ)/practicafinal.o $(OBJ)/juego.o $(OBJ)/juegoletras.o $(OBJ)/diccionario.o $(OBJ)/bolsaletras.o $(OBJ)/conjuntoletras.o $(OBJ)/letra.o $(OBJ)/juegocifras.o

$(OBJ)/practicafinal.o : $(SRC)/practicafinal.cpp $(OBJ)/juego.o $(OBJ)/diccionario.o
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/practicafinal.o $(SRC)/practicafinal.cpp

$(OBJ)/juego.o : $(SRC)/juego.cpp $(INC)/juego.h $(INC)/juegoletras.h $(INC)/juegocifras.h $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/juego.o $(SRC)/juego.cpp

# JUEGOCIFRAS
$(OBJ)/juegocifras.o : $(SRC)/juegocifras.cpp $(INC)/juegocifras.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/juegocifras.o $(SRC)/juegocifras.cpp

clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/*
	rm -r doc/*