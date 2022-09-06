files=Initiator.c Worker.c Worker.h
CC = gcc
out_exe= Initiator
build: $(out_exe)
$(out_exe): $(files)
	$(CC) -o $(out_exe) $(files)
package:
	tar -cvzf Brock-Fisher-HW1.tar *.c *.h *.txt Makefile
clean:
	rm -f $(out_exe) 
