COMP = g++
EDL = g++
RM=@rm
ECHO=@echo
RMFLAGS = -f
OUTPUT = -o
CPPFLAGS = -std=c++0x -Wall 
INT = Command/Command.h Command/CommandParser.h Command/Receiver.h CommandType/AddTrackCommand.h CommandType/CreatePlaylistCommand.h CommandType/LoadPlaylistCommand.h CommandType/NextCommand.h CommandType/PauseCommand.h CommandType/PlayCommand.h CommandType/PreviousCommand.h CommandType/RandomCommand.h CommandType/RemoveDuplicatesCommand.h CommandType/RemoveTrackCommand.h CommandType/RepeatCommand.h CommandType/ShowPlaylistCommand.h CommandType/ShowTrackCommand.h Model/Player.h Model/Playlist.h Model/Track.h Repository/MusicManager.h CommandType/HelpCommand.h
REAL = main.cpp Command/CommandParser.cpp CommandType/AddTrackCommand.cpp CommandType/CreatePlaylistCommand.cpp CommandType/LoadPlaylistCommand.cpp CommandType/NextCommand.cpp CommandType/PauseCommand.cpp CommandType/PlayCommand.cpp CommandType/PreviousCommand.cpp CommandType/RandomCommand.cpp CommandType/RemoveDuplicatesCommand.cpp CommandType/RemoveTrackCommand.cpp CommandType/RepeatCommand.cpp CommandType/ShowPlaylistCommand.cpp CommandType/ShowTrackCommand.cpp Model/Player.cpp Model/Playlist.cpp Model/Track.cpp Repository/MusicManager.cpp CommandType/HelpCommand.cpp
OBJ = $(REAL:.cpp=.o)
CLEAN = efface
LIBS = # -lm
LIBPATH = # -L
INCPATH = # -I
PROG = ../bin/iplayer

all: $(PROG) clean

$(PROG) : $(OBJ)
	$(COMP) $(OUTPUT) $(PROG) $(OBJ)

%.o:%.cpp $(INT)
	$(COMP) $(OUTPUT) $@ -c $< $(CPPFLAGS)


.PHONY: clean mrproper

clean:
	@rm -rf *.o
	@rm -rf Command/*.o
	@rm -rf CommandType/*.o
	@rm -rf Model/*.o
	@rm -rf Repository/*.o

mrproper: clean
	@rm -rf $(EXE)
