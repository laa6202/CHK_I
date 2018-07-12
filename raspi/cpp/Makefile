CC=gcc
FLAG= -std=c99
LIB=-lwiringPi -lopencv_core -lopencv_highgui -lopencv_imgproc
INCDIR=inc -I gui/inc
OUTDIR=out
TAR=xmpp
SRC=main.c \
		commu.c cal.c action.c record.c\
		alg.c \
		gui/gui_action.c
OBJ=main.o \
		commu.o cal.o action.o record.o\
		alg.o\
		gui_action.o

$(TAR) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)

$(OBJ) : $(SRC)
	$(CC) $(FLAG) -c $^ -I $(INCDIR)

clean :
	rm -rf $(TAR) $(OBJ)


