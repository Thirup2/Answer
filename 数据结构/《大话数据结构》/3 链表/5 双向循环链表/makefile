Objects = driver.o DulCyList.o

DulCyList : $(Objects)
	cc -o DulCyList $(Objects)

driver.o : DulCyList.h
DulCyList.o : DulCyList.h

.PHONY : clean
clean : 
	rm DulCyList $(Objects)