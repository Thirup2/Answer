Objects = Main.o SqStack.o

SqStack : $(Objects)
	cc -o SqStack $(Objects)

Main.o : SqStack.h
SqStack.o : SqStack.h

.PHONY : clean
clean :
	rm SqStack $(Objects)