CPP=g++

OBJECTS=libs/BinomialHeap.o\
		
BINS=main\
		
CPPFLAGS=-std=c++11 -O3 -DNDEBUG
DEST=.

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: clean bin

bin: $(OBJECTS) $(BINS)

main:
	g++ $(CPPFLAGS) -o $(DEST)/main main.cpp $(OBJECTS) -lm
	
clean:
	rm -f $(OBJECTS) $(BINS)
	cd $(DEST); rm -f *.a $(BINS)

