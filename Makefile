COMPILER=clang++
COMPILER_FLAGS=-g -Wall -std=c++20
LINKER_FLAGS=$(shell pkg-config --libs --cflags raylib)

SRC_DIR=src
OBJ_DIR=build
SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
HDRS=$(wildcard $(SRC_DIR)/*.hpp)
BIN=executable

all: $(BIN)

$(BIN): $(OBJS) $(OBJ_DIR)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) -o $@ $(LINKER_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(BIN)