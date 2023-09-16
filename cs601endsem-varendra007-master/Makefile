CXX = g++
CFLAGS+= -std=c++11 -g 

SOURCE = src/
BINARY = bin/

all: checkbin cs601endsem 

cs601endsem: checkbin $(SOURCE)index.cpp 
	$(CXX) $(CFLAGS) $(SOURCE)index.cpp -o $(BINARY)index.out

checkbin:
	if [ ! -d $(BINARY) ]; then mkdir $(BINARY); fi

clean:
	rm -f $(BINARY)*