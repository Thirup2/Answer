Objects = BiTree.o main.o
BiTree: $(Objects)
	cc -o BiTree $(Objects)

BiTree.o: BiTree.h
main.o: BiTree.h

.PHONY: clean
clean: 
	rm BiTree $(Objects)