Objects = LinkQueue.o driver.o

LinkQueue: $(Objects)
	cc -o LinkQueue $(Objects)

driver.o: LinkQueue.h
LinkQueue.o: LinkQueue.h

.PHONY: clean
clean:
	rm LinkQueue $(Objects)