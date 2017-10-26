COMP = g++
EDL = g++
RM=@rm
ECHO=@echo
RMFLAGS = -f
OUTPUT = -o
CPPFLAGS = -std=c++0x -Wall 
INT = 
REAL = main.cpp
OBJ = $(REAL:.cpp=.o)
CLEAN = efface
LIBS = # -lm
LIBPATH = # -L
INCPATH = # -I
PROG = ../bin/iplayer

all: $(PROG)

$(PROG) : $(OBJ)
	$(COMP) $(OUTPUT) $(PROG) $(OBJ)

%.o:%.cpp $(INT)
	$(COMP) $(OUTPUT) $@ -c $< $(CPPFLAGS)


.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXE)
