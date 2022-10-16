GCC=g++
CFLAGS=-g -Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN=$(BINDIR)/main

all:$(BIN)

release: CFLAGS=-Wall -DNDEBUG
release: clean
release: $(BIN)


$(BIN): $(OBJS)
	$(GCC) -o $@ $(CFLAGS) $^

$(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) -c $< $(CFLAGS) -o $@

clean:
	@- rm -r $(BINDIR)/* $(OBJ)/*
