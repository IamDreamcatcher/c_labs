all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	g++ -o target/main/LCM main.cpp -lm

buildTest:
	mkdir -p target/test
	g++ -o target/test/LCM_test -Dmain=_main main.cpp main_test.cpp -lm

runTest:
	./target/test/LCM_test

clean:
	rm -rf target
	