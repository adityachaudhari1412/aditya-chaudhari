#Aditya Chaudhari 1001747134
SRC1 = Code6_1001747134.c
SRC2 = DrawerLib.c
SRC3 = DresserLib.c
SRC4 = SortLib.c
SRC5 = SockLib.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
OBJ5 = $(SRC5:.c=.o)
EXE = $(SRC1:.c=.e)

HFILES2 = DrawerLib.h 
HFILES3 = DresserLib.h 
HFILES4 = SortLib.h 
HFILES5 = SockLib.h

CFLAGS = -g

all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) -o $(EXE) 

$(OBJ1) : $(SRC1) $(HFILES2) $(HFILES3) $(HFILES4) $(HFILES5)
	gcc -c $(CFLAGS) $(SRC1) -o $(OBJ1) 

$(OBJ2) : $(SRC2) $(HFILES2) 
	gcc -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3) $(HFILES3) 
	gcc -c $(CFLAGS) $(SRC3) -o $(OBJ3)

$(OBJ4) : $(SRC4) $(HFILES4) 
	gcc -c $(CFLAGS) $(SRC4) -o $(OBJ4)

$(OBJ5) : $(SRC5) $(HFILES5) 
	gcc -c $(CFLAGS) $(SRC5) -o $(OBJ5)
