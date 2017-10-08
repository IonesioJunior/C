# Makefile : How to compile and use a static lib
# Author : Ionesio Junior

static: libslib.a static_app
dynamic : libslib.so dynamic_app

# Generate Lib Object
slib.o : slib.h slib.c
	@echo "Generating Lib Object ..."
	@gcc -fPIC -c slib.h slib.c

#Generate Static Lib
libslib.a : slib.o
	@echo "Generating Static Lib ..."
	@ar rc $@ $^
	@rm slib.o && mv libslib.a ./lib

#Generate Dynamic Lib
libslib.so : slib.o
	@echo "Generating dynamic lib ..."
	@gcc  -shared -Wl,-soname -Wl,$@ \
		-o $@ $^
	@rm slib.o && mv libslib.so ./lib


# Link static lib with our Application
static_app : slib.h ./lib/libslib.a
	@echo "Linking Application with static lib ..."
	@gcc slib.h app.c -o app -Llib -lslib

# Link dynamic lib with our Application
dynamic_app : slib.h ./lib/libslib.so
	@echo "Linking Application with dynamic lib ..."
	@gcc slib.h app.c -o app -Llib -lslib

# Clean Binary files
clean : 
	@echo "Cleaning binaries"
	@rm app ./lib/libslib.a ./lib/libslib.so slib.h.gch
