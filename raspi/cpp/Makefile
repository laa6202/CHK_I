CC=gcc
FLAG= -std=c99
LIB=-lwiringPi
INCDIR=inc
OUTDIR=out
TAR=xmpp
SRC=main.c commu.c
OBJ=main.o commu.o

$(TAR) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)

$(OBJ) : $(SRC)
	$(CC) $(FLAG) -c $^ -I $(INCDIR)

clean :
	rm -rf $(TAR) $(OBJ)

