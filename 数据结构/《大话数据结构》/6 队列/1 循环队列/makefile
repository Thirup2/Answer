Objects = SqQueue.o Main.o

SqQueue: $(Objects)
	cc -o SqQueue $(Objects)

SqQueue.o: SqQueue.h
Main.o: SqQueue.h

.PHONY : clean
clean:
	rm SqQueue $(Objects)