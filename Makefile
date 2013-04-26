SRC=$(sort $(wildcard vm/*.cpp vm/util/*.cpp vm/builtin/*.cpp))
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS := -std=c++11 -ggdb -Wall -Ivm -Ivm/builtin

LDFLAGS := -lprotobuf

all: marius

linux-dep:
	sudo apt-get install libprotobuf-dev

dep:
	: > depend
	for i in $(SRC); do $(CC) $(CXXFLAGS) -MM -MT $${i%.cpp}.o $$i >> depend; done

clean:
	rm $(OBJ)

tools/lemon:
	$(CC) -o tools/lemon tools/lemon.c

vm/parser.c.inc: vm/parser.lm tools/lemon
	./tools/lemon -Ttools/lempar.c vm/parser.lm
	mv vm/parser.h vm/parser_tokens.h

vm/parser.cpp: vm/parser.c.inc
vm/parser.o: vm/parser.c.inc

marius: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o marius $(OBJ)

rebuild_kernel: marius
	for i in kernel/*.mr; do ./marius -bc $$i; mv $${i%.mr}.mrc vm/kernel/; done
	$(MAKE) marius

rebuild_pb:
	protoc -Ivm --cpp_out=vm vm/code.proto
	mv vm/code.pb.cc vm/code.pb.cpp

rebuild_builtin:
	./marius -C cimple/buffer.mr os.buffer vm/builtin
	./marius -C cimple/file.mr os.file vm/builtin
	./marius -C cimple/dir.mr os.dir vm/builtin
	./marius -C cimple/stat.mr os.stat vm/builtin

test: marius
	./marius -c test/syntax.mr
	test `./marius -p test/simp.mr` = 7
	test `./marius -p test/arg.mr` = 7
	test `./marius -p test/keyword.mr` = 7
	test `./marius -p test/keyword_hybrid.mr` = 7
	test `./marius test/module.mr` = 7
	test `./marius -I test/import test/import.mr` = 7
	test `./marius test/try.mr` = 7
	test `./marius test/try_skip.mr` = 7
	test `./marius test/local.mr` = 7
	test `./marius test/local_def.mr` = 7
	test `./marius test/ivar.mr` = 7
	test `./marius -I test/import test/imported_class.mr` = 7
	test `./marius test/symbol.mr` = 'blah'
	test `./marius test/litstr.mr` = 'blah'
	test `./marius -I test/import test/import2.mr` = 7
	test `./marius -I test/import test/import3.mr` = 7
	test `./marius -I test/import test/import4.mr` = 7
	test `./marius test/lambda.mr` = 7
	test `./marius test/lambda2.mr` = 7
	test `./marius test/lambda_arg.mr` = 7
	test `./marius test/arg_error.mr` = 7
	test `./marius -p test/send.mr` = 7
	test `./marius test/subclass.mr` = 7
	test `./marius test/cast.mr` = 7
	test `./marius -p test/no_self_call.mr` = 7
	test `./marius -p test/keyword_no_recv.mr` = 7
	test `./marius -p test/operator.mr` = 7
	test `./marius -p test/operator2.mr` = 7
	test `./marius -p test/assign_op.mr` = 7
	test `./marius -p test/ivar_assign_op.mr` = 7
	test `./marius -p test/dict.mr` = 7
	test `./marius -p test/cast_arg.mr` = 7
	test `./marius -p test/brackets.mr` = 7
	test `./marius test/trait.mr` = 7
	test `./marius -p test/if_else.mr` = 7
	test `./marius test/try_specific.mr` = 7
	test `./marius test/try_specific2.mr` = 7
	(! ./marius scratch/bad_trait.mr) > /dev/null 2>&1
	test `./marius test/long_return.mr` = 7
	test `./marius test/markov_rule.mr` = 7
	test `./marius -p test/opt_arg.mr` = 7

spec: test
	./marius -Ilib -I. test spec

.PHONY: test spec

-include depend
