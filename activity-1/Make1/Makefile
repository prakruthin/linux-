TARGET=hall.out
OBJS=test.o src/mystring.o src/bitwise.o src/myutils.o
TOPDIR=${PWD}

CFLAGS=-I${TOPDIR}/include

all:$(TARGET)

$(TARGET):$(OBJS)
	gcc $^ -o $@

%.o:src/%.c 

test.o:test.c

clean:
	rm -rf ${OBJS} ${TARGET}
