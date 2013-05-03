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
	./marius -C cimple/moment.mr os.time vm/builtin

vm-test: marius
	./marius -c vm-test/syntax.mr
	test `./marius -p vm-test/simp.mr` = 7
	test `./marius -p vm-test/arg.mr` = 7
	test `./marius -p vm-test/keyword.mr` = 7
	test `./marius -p vm-test/keyword_hybrid.mr` = 7
	test `./marius vm-test/module.mr` = 7
	test `./marius -I vm-test/import vm-test/import.mr` = 7
	test `./marius vm-test/try.mr` = 7
	test `./marius vm-test/try_skip.mr` = 7
	test `./marius vm-test/local.mr` = 7
	test `./marius vm-test/local_def.mr` = 7
	test `./marius vm-test/ivar.mr` = 7
	test `./marius -I vm-test/import vm-test/imported_class.mr` = 7
	test `./marius vm-test/symbol.mr` = 'blah'
	test `./marius vm-test/litstr.mr` = 'blah'
	test `./marius -I vm-test/import vm-test/import2.mr` = 7
	test `./marius -I vm-test/import vm-test/import3.mr` = 7
	test `./marius -I vm-test/import vm-test/import4.mr` = 7
	test `./marius vm-test/lambda.mr` = 7
	test `./marius vm-test/lambda2.mr` = 7
	test `./marius vm-test/lambda_arg.mr` = 7
	test `./marius vm-test/arg_error.mr` = 7
	test `./marius -p vm-test/send.mr` = 7
	test `./marius vm-test/subclass.mr` = 7
	test `./marius vm-test/cast.mr` = 7
	test `./marius -p vm-test/no_self_call.mr` = 7
	test `./marius -p vm-test/keyword_no_recv.mr` = 7
	test `./marius -p vm-test/operator.mr` = 7
	test `./marius -p vm-test/operator2.mr` = 7
	test `./marius -p vm-test/assign_op.mr` = 7
	test `./marius -p vm-test/ivar_assign_op.mr` = 7
	test `./marius -p vm-test/dict.mr` = 7
	test `./marius -p vm-test/cast_arg.mr` = 7
	test `./marius -p vm-test/brackets.mr` = 7
	test `./marius vm-test/trait.mr` = 7
	test `./marius -p vm-test/if_else.mr` = 7
	test `./marius vm-test/try_specific.mr` = 7
	test `./marius vm-test/try_specific2.mr` = 7
	(! ./marius scratch/bad_trait.mr) > /dev/null 2>&1
	test `./marius vm-test/long_return.mr` = 7
	test `./marius vm-test/markov_rule.mr` = 7
	test `./marius -p vm-test/opt_arg.mr` = 7

test: vm-test
	./marius -Ilib -I. test test

.PHONY: test spec

-include depend
