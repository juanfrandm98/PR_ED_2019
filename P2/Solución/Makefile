INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/prueba

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/prueba : $(OBJ)/pruebamicronologia.o $(OBJ)/Mi_Fecha_Historica.o $(OBJ)/Mi_Cronologia.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebamicronologia.o $(OBJ)/Mi_Fecha_Historica.o $(OBJ)/Mi_Cronologia.o

$(OBJ)/pruebamicronologia.o : $(INC)/Mi_Cronologia.h $(INC)/Mi_Fecha_Historica.h $(SRC)/pruebamicronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebamicronologia.o $(SRC)/pruebamicronologia.cpp

$(OBJ)/Mi_Cronologia.o : $(INC)/Mi_Cronologia.h $(INC)/Mi_Fecha_Historica.h $(SRC)/Mi_Cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Mi_Cronologia.o $(SRC)/Mi_Cronologia.cpp

$(OBJ)/Mi_Fecha_Historica.o : $(INC)/Mi_Fecha_Historica.h $(SRC)/Mi_Fecha_Historica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Mi_Fecha_Historica.o $(SRC)/Mi_Fecha_Historica.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*
