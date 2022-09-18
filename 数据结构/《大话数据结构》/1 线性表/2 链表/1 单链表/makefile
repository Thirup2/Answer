objects = driver.o LinkList.o

LinkList : $(objects)
	cc -o LinkList $(objects)

driver.o : LinkList.h
LinkList.o : LinkList.h

.PHONY : clean
clean :
	rm LinkList $(objects)