objects = driver.o StaticList.o

StaticList : $(objects)
	cc -o StaticList $(objects)

driver.o : StaticList.h
StaticList.o : StaticList.h

.PHONY : clean
clean :
	rm StaticList $(objects)