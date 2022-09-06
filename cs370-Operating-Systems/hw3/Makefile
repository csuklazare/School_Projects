file1=Initiator.c
file2=Pell.c
file3=Composite.c
file4=Total.c
file5=Reader.c
CC = gcc
out_exe1= Initiator
out_exe2= Pell
out_exe3= Composite
out_exe4= Total
out_exe5= Reader 
build: $(out_exe1) $(out_exe2) $(out_exe3) $(out_exe4) $(out_exe5)
$(out_exe1): $(file1)
	$(CC) -Wall -g -lrt -Wextra -o $(out_exe1) $(file1)
$(out_exe2): $(file2)
	$(CC) -Wall -g -lrt -Wextra -o $(out_exe2) $(file2)
$(out_exe3): $(file3)
	$(CC) -Wall -g -lrt -Wextra -o $(out_exe3) $(file3)
$(out_exe4): $(file4)
	$(CC) -Wall -g -lrt -Wextra -o $(out_exe4) $(file4)
$(out_exe5): $(file5)
	$(CC) -Wall -g -lrt -Wextra -o $(out_exe5) $(file5)
package:
	tar -cvzf Brock-Fisher-HW3.tar *.c *.txt Makefile
clean:
	rm -f $(out_exe1) $(out_exe2) $(out_exe3) $(out_exe4) $(out_exe5)
rebuild:
	make clean
	make build


