CC = gcc
CFLAGS = -Wall -g -fPIC
LDFLAGS = -L. -lm


STATIC_LIB = libfredjohn.a
SHARED_LIB = libbillsam.so

OBJECTS_STATIC = fred.o john.o
OBJECTS_SHARED = bill.o sam.o

TARGET = solution

INTERPOSE_OBJ = interpose.o


all: $(TARGET)


$(TARGET): solution.o $(STATIC_LIB) $(SHARED_LIB) $(INTERPOSE_OBJ)
	$(CC) -o $(TARGET) solution.o $(INTERPOSE_OBJ) -L. -lfredjohn -lbillsam $(LDFLAGS) -Wl,--wrap=fred

$(STATIC_LIB): $(OBJECTS_STATIC)
	ar rcs $(STATIC_LIB) $(OBJECTS_STATIC)

$(SHARED_LIB): $(OBJECTS_SHARED)
	$(CC) -shared -o $(SHARED_LIB) $(OBJECTS_SHARED) -lm


fred.o: fred.c
	$(CC) $(CFLAGS) -c fred.c

john.o: john.c
	$(CC) $(CFLAGS) -c john.c

bill.o: bill.c
	$(CC) $(CFLAGS) -c bill.c

sam.o: sam.c
	$(CC) $(CFLAGS) -c sam.c

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c


interpose.o: interpose.c
	$(CC) $(CFLAGS) -c interpose.c

run: $(TARGET)
	DYLD_LIBRARY_PATH=.:$$DYLD_LIBRARY_PATH ./$(TARGET)
	ldd $(TARGET)

clean:
	rm -f *.o $(STATIC_LIB) $(SHARED_LIB) $(TARGET)

.PHONY: all run clean