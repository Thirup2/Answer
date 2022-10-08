objects = driver.o Array.o

Array : $(objects)
	cc -o Array $(objects)

driver.o : Array.h
Array.o : Array.h

.PHONY : clean
clean :
	rm Array $(objects)