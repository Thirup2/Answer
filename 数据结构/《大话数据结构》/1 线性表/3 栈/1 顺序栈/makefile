Objects = driver.o SqStack.o

SqStack : $(Objects)
	cc -o SqStack $(Objects)

driver.o : SqStack.h
SqStack.o : SqStack.h

.PHONY : clean
clean :
	rm SqStack $(Objects)