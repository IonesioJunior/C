# Makefile : How to compile and use a static lib
# Author : Ionesio Junior

all: libslib.a app

# Generate Static Lib
slib.o : slib.h slib.c
	gcc -c slib.h slib.c

libslib.a : slib.o
	ar rc $@ $^
	rm slib.o && mv libslib.a ./lib

# Link static lib with our Aplication

app : slib.h ./lib/libslib.a
	gcc slib.h app.c -o app -Llib -lslib


# Clean Binary files
clean : 
	rm app ./lib/libslib.a slib.h.gch
