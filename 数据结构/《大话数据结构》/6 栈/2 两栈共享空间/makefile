Objects = Main.o SqDulStack.o

SqDulStack : $(Objects)
	cc -o SqDulStack $(Objects)

Main.o : SqDulStack.h
SqDulStack.o : SqDulStack.h

.PHONY : clean
clean :
	rm SqDulStack $(Objects)