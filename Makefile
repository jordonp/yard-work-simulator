GCC       := g++
LDFLAGS   := -lGL -lGLEW `sdl2-config --libs`
CCFLAGS   := -std=c++11 `sdl2-config --cflags`
INCLUDES  := -I./include/
SRC_DIR=src
BIN_DIR=bin

EXECUTABLE  := yard-work-simulator
CCFILES     := $(wildcard $(SRC_DIR)/*.cpp)
SRC = $(CCFILES)
OBJ = $(SRC:.cpp=.o)

all: $(EXECUTABLE)

%.o: %.cpp
	$(GCC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<

$(EXECUTABLE): $(OBJ)
	$(GCC) $(CCFLAGS) -o $(BIN_DIR)/$@ $+ $(LDFLAGS)

clean:
	rm -f $(BIN_DIR)/$(EXECUTABLE) $(OBJ)