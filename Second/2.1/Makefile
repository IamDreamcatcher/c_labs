all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/eVegetables main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/eVegetables_test -Dmain=_main main.c main_test.c -lm

runTest:
	./target/test/eVegetables_test

clean:
	rm -rf target
	