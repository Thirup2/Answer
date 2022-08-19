Objects = driver.o SqDulStack.o

SqDulStack : $(Objects)
	cc -o SqDulStack $(Objects)

driver.o : SqDulStack.h
SqDulStack.o : SqDulStack.h

.PHONY : clean
clean :
	del SqDulStack.exe $(Objects)