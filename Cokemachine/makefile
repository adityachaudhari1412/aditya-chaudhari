#Aditya Chaudhari 1001747134

#makefile for Code3

SRC1 = Code3_1001747134.cpp

OBJ1 = $(SRC1:.cpp=.o)

EXE = $(SRC1:.cpp=.e)



HFILES = CokeMachine.h



CFLAGS = -g -std=c++11 -pthread



all : $(EXE)

 

$(EXE): $(OBJ1) 

	g++ $(CFLAGS) $(OBJ1) -o $(EXE) 



$(OBJ1) : $(SRC1)

	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) 



