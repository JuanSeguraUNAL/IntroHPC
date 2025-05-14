CXXFLAGS = -fsanitize=address,undefined,leak -fprofile-arcs -ftest-coverage

all: main_factorial.x

%.x: %.o factorial.o
	g++ $(CXXFLAGS) $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ -fsanitize=address,undefined,leak -c $<

test: test_factorial.x
	./$< 

codecoverage: test_factorial.x
	./$<
	gcov factorial.cpp test_factorial.cpp
	genhtml lcov-report/coverage.info --output-directory lcov-report

clean:
	rm -f *.o *.x a.out	