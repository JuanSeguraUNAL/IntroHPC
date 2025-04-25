SOURCES := $(wildcard *.cpp)   # Indica todos los que terminen en .cpp
OBJECTS = $(SOURCES: .cpp=.o)  # Los objetos cambiando el .cpp por .o

fig.pdf : script.gp data.txt
	gnuplot $<

%.o : %.cpp
	g++ $< -c

sumupdown.x : $(OBJECTS)
	g++ $^ -o $@

data.txt : sumupdown.x
	./$< > $@

clean:
	rm -f *.x a.out *.txt *.pdf *.o

# $< indica la primera dependencia
# $@ indica el target
# % indica que los mismos caracteres para el target y la dependecia (?)

