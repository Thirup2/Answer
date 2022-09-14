Objects = driver.o LinkStack.o

LinkStack: $(Objects)
	cc -o LinkStack $(Objects)

driver.o: LinkStack.h
LinkStack.o: LinkStack.h

.PHONY: clean
clean:
	del LinkStack.exe $(Objects)