CC=g++
CFLAGS=-g -Wall
SOBJS=sumfact.o
LOBJS=launch.o
STARGET=sumfact
LTARGET=launch

all: launch sumfact

$(LTARGET): $(LOBJS)
						 $(CC) -o $@ $(LOBJS)
$(STARGET): $(SOBJS)
						 $(CC) -o $@ $(SOBJS) -lpthread

clean:
	rm -f *.o
	rm -f $(LTARGET) $(STARGET)

launch.o: launch.c						
sumfact.o: sumfact.c
