COMPILER=clang++
COMPILER_FLAGS=-g -Wall -std=c++20
LINKER_FLAGS=$(shell pkg-config --libs --cflags raylib)

SRC_DIR=src
OBJ_DIR=build
SRCS=$(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
HDRS=$(shell find $(SRC_DIR) -type f -name '*.hpp')
BIN=executable

all: $(BIN)

$(BIN): $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) -o $@ $(LINKER_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(BIN)