CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -g

SRC_MAIN_DIR   := src
INC_MAIN_DIR   := src/inc

BIN		  := bin
SRC     :=  $(wildcard $(SRC_MAIN_DIR)/*.cpp)
INCLUDE :=  $(INC_MAIN_DIR)
INC_PARAMS = 	$(foreach d, $(INCLUDE), -I$d)
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) $(INC_PARAMS) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	install -d $(BIN)
	-rm -f $(BIN)/*
