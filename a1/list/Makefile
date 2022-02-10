CC=cc
CXX=CC
CCFLAGS= -g -std=c99 -Wall -Werror
DEPS = list.h
OBJ = test_list.o list.o

all: test_list test

%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

test_list: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

test: test_list
	./test_list


clean:
	rm -f core *.o test_list

