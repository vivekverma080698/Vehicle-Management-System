default : prog
prog:  car.o bus.o truck.o main.o linklist.o
	g++  main.o car.o bus.o truck.o -o Veh_Manage
car.o:  src/car.cpp
	g++ -w -c -I./include src/car.cpp -o car.o
bus.o: src/bus.cpp
	g++ -w -c -I./include src/bus.cpp -o bus.o
truck.o: src/truck.cpp
	g++ -w -c -I./include src/truck.cpp -o truck.o
main.o: src/main.cpp
	g++ -w -c -I./include src/main.cpp -o main.o
linklist.o: src/linklist.cpp
	g++ -w -c -I./include src/linklist.cpp -o linklist.o
clean:
	rm car.o bus.o truck.o main.o linklist.o Veh_Manage

