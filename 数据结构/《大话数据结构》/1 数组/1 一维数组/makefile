Objects = Array.o Main.o

Array: $(Objects)
	cc -o Array $(Objects)

Array.o: Array.h
Main.o: Array.h

.PHONY: clean
clean:
	rm Array $(Objects)