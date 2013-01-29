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
	test `./marius -p test/simp.mr` = 7
	test `./marius -p test/arg.mr` = 7
	test `./marius -p test/cascade.mr` = 7
	test `./marius -p test/keyword.mr` = 7
	test `./marius -p test/keyword_hybrid.mr` = 7
	test `./marius test/module.mr` = 7
	test `./marius -I test/import test/import.mr` = 7
	test `./marius test/try.mr` = 7
	test `./marius test/try_skip.mr` = 7
	test `./marius test/local.mr` = 7
	test `./marius test/local_def.mr` = 7
	test `./marius test/ivar.mr` = 7
	test `./marius -I test/import test/attr.mr` = 7
	test `./marius -I test/import test/imported_class.mr` = 7
	test `./marius test/symbol.mr` = '"blah"'
	test `./marius test/litstr.mr` = '"blah"'
	test `./marius -I test/import test/import2.mr` = 7
	test `./marius test/lambda.mr` = 7
	test `./marius test/lambda2.mr` = 7

.PHONY: test

-include depend
