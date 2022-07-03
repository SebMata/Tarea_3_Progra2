FLAGS = -g -c --std=c++17 -fpic


all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ -shared -o bin/libtienda.so obj/producto.o obj/tienda.o
	mkdir -p bin/include
	cp src/tienda.h ./bin/include
	cp src/producto.h ./bin/include
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/tienda_test.cpp -o obj/tienda_test.o
	g++ $(FLAGS) tests/producto_test.cpp -o obj/producto_test.o
	g++ -g -o bin/tests obj/producto.o obj/tienda.o obj/producto_test.o obj/tienda_test.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm -Rf obj
	rm *.dat
