Objects = main.o SqBiTree.o

SqBiTree: $(Objects)
	cc -o SqBiTree $(Objects)

main.o: SqBiTree.h
SqBiTree.o: SqBiTree.h

.PHONY: clean
clean:
	rm SqBiTree $(Objects)