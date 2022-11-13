Objects = Main.o LinkStack.o

LinkStack: $(Objects)
	cc -o LinkStack $(Objects)

Main.o: LinkStack.h
LinkStack.o: LinkStack.h

.PHONY: clean
clean:
	rm LinkStack $(Objects)