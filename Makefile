SRC=$(wildcard vm/*.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS := -ggdb

marius: $(OBJ)
	g++ -ggdb3 -o marius $(OBJ)
