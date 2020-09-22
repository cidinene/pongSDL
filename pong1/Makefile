GCC		  := g++
CXX_FLAGS := -v -Wall -Wextra -std=c++17 -g -Wno-pragma-once-outside-header

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib


LIBRARIES_DIR:="/usr/local/lib"
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(GCC)  $(CXX_FLAGS) -I$(INCLUDE) -L$(LIBRARIES_DIR)  $^ -o $@ $$(sdl2-config --cflags --libs) -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	