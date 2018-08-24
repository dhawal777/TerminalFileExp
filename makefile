CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = lsls.h
OBJ =  terminal2.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

terminal2: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

