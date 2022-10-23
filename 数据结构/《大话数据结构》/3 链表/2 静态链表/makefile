objects = Main.o StaticList.o

StaticList : $(objects)
	cc -o StaticList $(objects)

Main.o : StaticList.h
StaticList.o : StaticList.h

.PHONY : clean
clean :
	rm StaticList $(objects)