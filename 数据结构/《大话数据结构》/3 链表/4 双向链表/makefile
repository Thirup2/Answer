Objects = Main.o DoubleList.o

DoubleList : $(Objects)
	cc -o DoubleList $(Objects)

Main.o : DoubleList.h
DoubleList.o : DoubleList.h

.PHONY : clean
clean :
	rm DoubleList $(Objects)