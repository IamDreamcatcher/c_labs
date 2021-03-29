all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/23_task main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/23_task_test -Dmain=_main main.c main_test.c -lm

runTest:
	./target/test/23_task_test

clean:
	rm -rf target
	