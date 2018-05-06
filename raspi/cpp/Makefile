CC=gcc
FLAG= -std=c99
LIB=-lwiringPi
INCDIR=inc
OUTDIR=out
TAR=xmpp
SRC=main.c commu.c cal.c action.c
OBJ=main.o commu.o cal.o action.o

$(TAR) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)

$(OBJ) : $(SRC)
	$(CC) $(FLAG) -c $^ -I $(INCDIR)

clean :
	rm -rf $(TAR) $(OBJ)


