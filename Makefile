CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q3
OBJECTS = main.o basic.o image.o ppmArray.o decorator.o flip.o rotate.o sepia.o exception.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
