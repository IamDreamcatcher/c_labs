all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	g++ -o target/main/Binary_tree main.cpp -lm

buildTest:
	mkdir -p target/test
	g++ -o target/test/Binary_tree_test -Dmain=_main main.cpp main_test.cpp -lm

runTest:
	./target/test/Binary_tree_test

clean:
	rm -rf target
	