CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -g

SRC_MAIN_DIR       := src
SRC_CFGFILE_DIR    := src/config-file
SRC_STRUCT_DIR     := src/struct
SRC_CAL_DIR        := src/cal
SRC_TESTVALUES_DIR := src/test-values

INC_MAIN_DIR       := src/inc
INC_CFGFILE_DIR    := src/config-file
INC_STRUCT_DIR     := src/struct
INC_CAL_DIR        := src/cal
INC_TESTVALUES_DIR := src/test-values

BIN		:= bin
SRC		:= $(wildcard $(SRC_CFGFILE_DIR)/*.cpp) \
		  $(wildcard $(SRC_STRUCT_DIR)/*.cpp) \
		  $(wildcard $(SRC_CAL_DIR)/*.cpp) \
		  $(wildcard $(SRC_TESTVALUES_DIR)/*.cpp) \
		  $(wildcard $(SRC_MAIN_DIR)/*.cpp)
INCLUDE :=  $(INC_CFGFILE_DIR) \
			$(INC_STRUCT_DIR) \
			$(INC_CAL_DIR) \
			$(INC_TESTVALUES_DIR) \
			$(INC_MAIN_DIR)
INC_PARAMS = $(foreach d, $(INCLUDE), -I$d)
LIB		:=

LIBRARIES	:= -lwiringPi
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) $(INC_PARAMS) $^ -o $@ $(LIBRARIES)
#	$(CXX) $(CXX_FLAGS) $(INC_PARAMS) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	install -d $(BIN)
	-rm -f $(BIN)/*
