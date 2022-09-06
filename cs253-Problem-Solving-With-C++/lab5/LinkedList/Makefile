files=ll.cc main.cc
CC = g++
executable = link
build: $(executable)
$(executable): $(files)
	$(CC) -Wall -o $(executable) $(files)
clean:
	rm -f $(executable)
leak:
	valgrind --leak-check=full --show-leak-kinds=all ./$(executable)
build:
	tar -cvf results.tar Makefile main.cc ll.cc ll.h
