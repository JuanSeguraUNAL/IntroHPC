DiferenciasSumas.pdf : Graficacion.py data.txt
	python Graficacion.py

DifNumSum.x : DifNumSum.cpp
	g++ DifNumSum.cpp -o DifNumSum.x

data.txt : DifNumSum.x
	./DifNumSum.x > data.txt

clean:
	rm -f *.x *.txt *.pdf
