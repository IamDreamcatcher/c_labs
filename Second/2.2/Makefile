all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/Sin main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/Sin_test -Dmain=_main main.c main_test.c -lm

runTest:
	./target/test/Sin_test

clean:
	rm -rf target
	