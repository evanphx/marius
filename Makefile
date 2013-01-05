SRC=$(sort $(wildcard vm/*.cpp))
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS := -ggdb -Wall

all: marius

dep:
	: > depend
	for i in $(SRC); do $(CC) $(CXXFLAGS) -MM -MT $${i%.cpp}.o $$i >> depend; done

clean:
	rm $(OBJ)

tools/lemon:
	gcc -o tools/lemon tools/lemon.c

vm/parser.c.inc: vm/parser.lm tools/lemon
	./tools/lemon -Ttools/lempar.c vm/parser.lm
	mv vm/parser.h vm/parser_tokens.h

vm/parser.cpp: vm/parser.c.inc
vm/parser.o: vm/parser.c.inc

marius: $(OBJ)
	c++ -ggdb -o marius $(OBJ)

test: marius
	test `./marius test/simp.mr` = 7

-include depend
