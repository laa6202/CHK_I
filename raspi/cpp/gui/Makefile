CC=g++
#FLAG= -std=c99
LIB=-lopencv_core -lopencv_highgui -lopencv_imgproc #-lpthread
INCDIR=inc
OUTDIR=out
TAR=xmpp_gui
SRC=main.c \
		gui_action.c gui_mat.c gui_dm.c
OBJ=main.o \
		gui_action.o gui_mat.o gui_dm.o

$(TAR) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)

$(OBJ) : $(SRC)
	$(CC) $(FLAG) -c $^ -I $(INCDIR)

clean :
	rm -rf $(TAR) $(OBJ)


