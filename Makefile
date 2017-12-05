msg:
	@echo "** Welcome to the Robot-Arm makefile **\n"
	@echo "1) To download and install necessary OpenGL libraries, type:"
	@echo "\tmake download\n"
	@echo "2) To compile the program, type:"
	@echo "\tmake compile\n"
download:
	sudo apt-get install freeglut3 freeglut3-dev
	sudo apt-get install binutils-gold

compile: main.cpp
	g++ -std=c++11 main.cpp robotarm.cpp -o main.o -lGL -lglut -lGLU
	@echo "\n\n** Now type make run to execute object file **\n"

run: main.o
	./main.o

clean:
	rm *.o