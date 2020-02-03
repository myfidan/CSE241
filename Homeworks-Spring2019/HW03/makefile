
output: main.o hw3_class.o 
	g++ main.o hw3_class.o -o output

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

hw3_class.o: hw3_class.cpp hw3_class.h
	g++ -c -std=c++11 hw3_class.cpp

clean:
	rm *.o output


