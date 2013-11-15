CXX = g++
CXXFLAGS = -Wall -g -MMD
EXEC = a4q2
OBJECTS = main.o expression.o binaryoperation.o loneint.o unaryoperation.o expressionstack.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC} 
