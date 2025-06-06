%.x : %.cpp
	g++ -std=c++17 -fopenmp -O3 -fsanitize=address,undefined,leak $< -o $@

ejecutar : lu.x
	rm -f *.txt
	bash lu.sh

Grafica:
	python grafica.py

clean:
	rm -f *.txt *.x