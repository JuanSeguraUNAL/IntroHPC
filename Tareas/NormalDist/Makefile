DistribucionNormal.pdf : Graficacion.py datos1.txt datos2.txt datos5.txt
	python Graficacion.py

NormalDist.x : NormalDist.cpp
	g++ NormalDist.cpp -o NormalDist.x

datos1.txt : NormalDist.x
	./NormalDist.x 1 5000 3.5 0.4 2.7 4.6 50 > datos1.txt

datos2.txt : NormalDist.x
	./NormalDist.x 2 5000 3.5 0.4 2.7 4.6 50 > datos2.txt

datos5.txt : NormalDist.x
	./NormalDist.x 5 5000 3.5 0.4 2.7 4.6 50 > datos5.txt

clean:
	rm -f *.txt *.pdf *.x