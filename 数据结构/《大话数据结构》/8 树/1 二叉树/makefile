Objects = BiTree.o Main.o
BiTree: $(Objects)
	cc -o BiTree $(Objects)

BiTree.o: BiTree.h
Main.o: BiTree.h

.PHONY: clean
clean: 
	rm BiTree $(Objects)