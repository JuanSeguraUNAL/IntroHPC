CXXFLAGS = -fsanitize=address,undefined,leak -fprofile-arcs -ftest-coverage

all: main_factorial.x

%.x: %.o factorial.o
	g++ $(CXXFLAGS) $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

test: test_factorial.x
	./$< 

codecoverage: test_factorial.x
	./$<
	gcov factorial.cpp test_factorial.cpp

	gcovr --html-details coverage.html

	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage
	firefox coverage/index.html
	
clean:
	rm -f *.o *.x a.out	*.gcov *.info *.gcda *.gcno 