Test: test
test: main.cpp cell.h cell.cpp abstracthex.cpp abstracthex.h hexvector.cpp hexvector.h hexarray1d.cpp hexarray1d.h hexadapter.cpp hexadapter.h error.h
	g++ -std=c++11 -c main.cpp
	g++ -std=c++11 -c cell.cpp
	g++ -std=c++11 -c abstracthex.cpp
	g++ -std=c++11 -c hexvector.cpp
	g++ -std=c++11 -c hexarray1d.cpp
	g++ -std=c++11 -c hexadapter.cpp
	g++ -std=c++11 -o main main.o abstracthex.o hexvector.o hexarray1d.o cell.o hexadapter.o
	./main