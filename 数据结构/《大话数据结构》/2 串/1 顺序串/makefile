Objects = String.o Main.o

String: $(Objects)
	cc -o String $(Objects)

String.o: String.h
Main.o: String.h

.PHONY: clean
clean:
	rm String $(Objects)