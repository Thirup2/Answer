Objects = LinkQueue.o Main.o

LinkQueue: $(Objects)
	cc -o LinkQueue $(Objects)

Main.o: LinkQueue.h
LinkQueue.o: LinkQueue.h

.PHONY: clean
clean:
	rm LinkQueue $(Objects)