all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/Neighbors main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/Neighbors_test -Dmain=_main main.c main_test.c -lm

runTest:
	./target/test/Neighbors_test

clean:
	rm -rf target
	