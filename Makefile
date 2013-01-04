SRC=$(sort $(wildcard vm/*.cpp))
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS := -ggdb

all: marius

tools/lemon:
	gcc -o tools/lemon tools/lemon.c

vm/parser.c.inc: vm/parser.lm tools/lemon
	./tools/lemon -Ttools/lempar.c vm/parser.lm
	mv vm/parser.h vm/parser_tokens.h

vm/parser.cpp: vm/parser.c.inc
vm/parser.o: vm/parser.c.inc

marius: $(OBJ)
	c++ -ggdb3 -o marius $(OBJ)
