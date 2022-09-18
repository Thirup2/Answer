Objects = SqQueue.o driver.o

SqQueue: $(Objects)
	cc -o SqQueue $(Objects)

SqQueue.o: SqQueue.h
driver.o: SqQueue.h

.PHONY : clean
clean:
	rm SqQueue $(Objects)