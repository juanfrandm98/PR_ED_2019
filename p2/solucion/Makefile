INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/prueba $(BIN)/pruebafecha

# ************ Generación de documentación ******************
documentacion:
	doxygen ./include

	
# ************ Compilación de módulos ************

$(BIN)/prueba : $(OBJ)/pruebamicronologia.o $(OBJ)/Mi_Fecha_Historica.o $(OBJ)/Mi_Cronologia.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebamicronologia.o $(OBJ)/Mi_Fecha_Historica.o $(OBJ)/Mi_Cronologia.o

$(OBJ)/pruebamicronologia.o : $(INC)/Mi_Cronologia.h $(INC)/Mi_Fecha_Historica.h $(SRC)/pruebamicronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebamicronologia.o $(SRC)/pruebamicronologia.cpp

$(BIN)/pruebafecha : $(OBJ)/pruebamifechahistorica.o $(OBJ)/Mi_Fecha_Historica.o
	$(CXX) -o $(BIN)/pruebafecha $(OBJ)/pruebamifechahistorica.o $(OBJ)/Mi_Fecha_Historica.o

$(OBJ)/pruebamifechahistorica.o : $(INC)/Mi_Fecha_Historica.h $(SRC)/pruebamifechahistorica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebamifechahistorica.o $(SRC)/pruebamifechahistorica.cpp

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
