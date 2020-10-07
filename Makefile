all: program1 program2

program1: main.cpp
	g++ -o program1 main.cpp

program2: helper.cpp
	g++ -o program2 helper.cpp
