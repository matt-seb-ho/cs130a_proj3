CXX = g++
CXXFLAGS = -std=c++11 -Wall
EXE = project3

project3: main.cpp graph_op.cpp graph_gen.cpp treenode.cpp
	${CXX} $^ ${CXXFLAGS} -o ${EXE}

scratch: scratch.cpp
	${CXX} scratch.cpp ${CXXFLAGS} -o scratch

clean:
	rm -f tester ${EXE} *.o
