Objects = String.o driver.o

String: $(Objects)
	cc -o String $(Objects)

String.o: String.h
driver.o: String.h

.PHONY: clean
clean:
	rm String $(Objects)