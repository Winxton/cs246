CXX = g++
CXXFLAGS = -Wall -g -MMD
EXEC = a4q4
OBJECTS = main.o textprocess.o echo.o decorator.o doublevowels.o swapcase.o translate.o skipword.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC} 
