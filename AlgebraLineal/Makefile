%.x : %.cpp
	g++ -O3 -fsanitize=address,undefined,leak $< -o $@

clean:
	rm -f *.x