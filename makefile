program: main.cpp
	g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o program
run: program
	./program
