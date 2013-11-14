CXX = g++
CXXFLAGS = -Wall -g -MMD
EXEC = a4q3
OBJECTS = main.o cell.o textdisplay.o grid.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC} 

