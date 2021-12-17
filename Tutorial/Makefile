CFILES   = $(wildcard *.c)
CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)
OUT      = main

CC = g++

LIBS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

$(OUT): $(OBJFILES)
	$(CC) $(LIBS) -o $@ $^

.PHONY: clean
clean:
	rm -fv $(OBJFILES) $(OUT)

run: clean $(OUT)
	./main
