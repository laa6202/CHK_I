CC=gcc
FLAG= -std=c99
LIB=
INCDIR=inc
OUTDIR=out
TAR=xmpp
SRC=main.c
OBJ=main.o

$(TAR) : $(OBJ)
	$(CC) -o $@ $^

$(OBJ) : $(SRC)
	$(CC) $(FLAG) -c $^ -I $(INCDIR)

clean :
	rm -rf $(TAR) $(OBJ)

