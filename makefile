CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = lsls.h copy.h search.h search_wh.h deletedir.h move.h copydir.h non_canonical.h ls_r.h print.h
OBJ =  terminal2.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

terminal2: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

