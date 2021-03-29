all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/N_matrices main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/N_matrices_test -Dmain=_main main.c main_test.c -lm

runTest:
	./target/test/N_matrices_test

clean:
	rm -rf target
	