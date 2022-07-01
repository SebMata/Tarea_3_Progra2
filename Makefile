FLAGS = -g -c --std=c++17


all:
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ -o bin/tienda bin/producto.o bin/tienda.o
	
test:
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ $(FLAGS) tests/tienda_test.cpp -o bin/tienda_test.o
	g++ -g -o bin/tests bin/producto.o bin/tienda.o bin/tienda_test.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm *.dat
