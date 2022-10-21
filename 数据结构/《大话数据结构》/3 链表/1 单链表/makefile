objects = Main.o LinkList.o

LinkList : $(objects)
	cc -o LinkList $(objects)

Main.o : LinkList.h
LinkList.o : LinkList.h

.PHONY : clean
clean :
	rm LinkList $(objects)