Objects = Main.o CycleList.o

CycleList : $(Objects)
	cc -o CycleList $(Objects)

Main.o : CycleList.h
CycleList.o : CycleList.h

.PHONY : clean
clean :
	rm CycleList $(Objects)