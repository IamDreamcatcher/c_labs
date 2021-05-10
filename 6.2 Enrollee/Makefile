all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	g++ -o target/main/Enrolle main.cpp -lm

buildTest:
	mkdir -p target/test
	g++ -ftest-coverage -fprofile-arcs -O0 -o target/test/Enrolle_test -Dmain=_main main.cpp main_test.cpp -lm

runTest:
	./target/test/Enrolle_test
	gcov -abcfu main.cpp
clean:
	rm -rf target
	