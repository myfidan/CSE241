
output: main.o Rectangle.o Circle.o Triangle.o ComposedShape.o
	g++ main.o Rectangle.o Circle.o Triangle.o ComposedShape.o -o output

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c -std=c++11 Rectangle.cpp

Circle.o: Circle.cpp Circle.h
	g++ -c -std=c++11 Circle.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ -c -std=c++11 Triangle.cpp

ComposedShape.o: ComposedShape.cpp ComposedShape.h
	g++ -c -std=c++11 ComposedShape.cpp		

clean:
	rm *.o output