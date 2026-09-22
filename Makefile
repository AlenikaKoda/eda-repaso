CC = g++
CFLAGS = -Wall -g
TARGET = programa

all:$(TARGET)

$(TARGET): main.o Pila.o Repaso.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Pila.o Repaso.o

main.o: main.cpp Repaso.hpp Pila.hpp
	$(CC) $(CFLAGS) -c main.cpp

Pila.o: Pila.cpp
	$(CC) $(CFLAGS) -c Pila.cpp

Repaso.o: Repaso.cpp Repaso.hpp Pila.cpp Pila.hpp
	$(CC) $(CFLAGS) -c Repaso.cpp

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
