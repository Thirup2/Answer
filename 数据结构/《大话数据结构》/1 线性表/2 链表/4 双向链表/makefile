Objects = driver.o DoubleList.o

DoubleList : $(Objects)
	cc -o DoubleList $(Objects)

driver.o : DoubleList.h
DoubleList.o : DoubleList.h

.PHONY : clean
clean :
	del DoubleList.exe $(Objects)