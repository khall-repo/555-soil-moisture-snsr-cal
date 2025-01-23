CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -g

SRC_MAIN_DIR       := src
SRC_CFG_DIR        := src/config
SRC_STRUCT_DIR     := src/struct
SRC_CAL_DIR        := src/cal
SRC_TESTVALUES_DIR := src/test-values
INC_MAIN_DIR       := src/inc

BIN		:= bin
SRC     := $(wildcard $(SRC_CFG_DIR)/*.cpp) \
		   $(wildcard $(SRC_STRUCT_DIR)/*.cpp) \
		   $(wildcard $(SRC_CAL_DIR)/*.cpp) \
           $(wildcard $(SRC_TESTVALUES_DIR)/*.cpp) \
           $(wildcard $(SRC_MAIN_DIR)/*.cpp) 
INCLUDE :=  $(INC_MAIN_DIR)
INC_PARAMS = 	$(foreach d, $(INCLUDE), -I$d)
LIB		:=

LIBRARIES	:= -lwiringPi
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) $(INC_PARAMS) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	install -d $(BIN)
	-rm -f $(BIN)/*
