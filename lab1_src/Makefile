# Makefile

TAR = exlab1
OBJ = http.o tcp.o main.o
CC = gcc
CFLAGS = -lwsock32

$(TAR): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) -c $^ -o $@
