all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/number main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/number_test -Dmain=_main main.c main_test.c -lm

runTest:
	./target/test/number_test

clean:
	rm -rf target
	