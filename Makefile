ordenacao.o: ordenacao.cpp
	g++ -E ordenacao.cpp > ordenacao.i
	g++ -S ordenacao.i
	g++ -c ordenacao.s

main.o: main.cpp
	g++ -E main.cpp > main.i
	g++ -S main.i
	g++ -c main.s

main: main.o ordenacao.o
	g++ -o main main.o ordenacao.o

.PHONY: clean

clean:
	rm *.i *.s *.o main