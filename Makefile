
output: gates.o addtional.o
	gcc gates.o addtional.o -o output

gates.o: gates.c
	gcc -c gates.c
	
addtional.o: addtional.c addtional.h
	gcc -c addtional.c addtional.h

clean:
	rm *.o output
