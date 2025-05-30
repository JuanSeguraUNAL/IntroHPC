SOURCES := $(wildcard *.cpp)   # Indica todos los que terminen en .cpp
OBJECTS = $(SOURCES: .cpp=.o)  # Los objetos cambiando el .cpp por .o

%.o : %.cpp
	g++ $< -c

percolacion.x : $(OBJECTS)
	g++ $^ -o $@