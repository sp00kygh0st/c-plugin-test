CC=gcc
CFLAGS=-I.
DEPS=plugin.h
OBJ=main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

plugintest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

plugin:
	gcc -shared -o test-plugin.dll test-plugin.c

clean:
	rm *.o *.exe *.dll