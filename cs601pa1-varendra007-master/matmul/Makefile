CXX = g++
CFLAGS=-I../papi/src/install/include/
ifeq ($(DEBUG), 1)
CFLAGS+= -std=c++11 -g -DPAPI -O3
LDFLAGS=-L/home/s200010055/papi/src/install/lib -lpapi
endif

SOURCE = src/
BINARY = bin/


all: team matmul1 matmul2 matmul3

checkbin:
	if [ ! -d $(BINARY) ]; then mkdir $(BINARY); fi

clean:
	rm -f $(BINARY)*

matmul1: checkbin $(SOURCE)matmul1.cpp 
	$(CXX) $(CFLAGS) $(SOURCE)matmul1.cpp -o $(BINARY)matmul1.out $(LDFLAGS)

matmul2: checkbin $(SOURCE)matmul2.cpp 
	$(CXX) $(CFLAGS) $(SOURCE)matmul2.cpp -o $(BINARY)matmul2.out $(LDFLAGS)

matmul3: checkbin $(SOURCE)matmul3.cpp
	$(CXX) $(CFLAGS) $(SOURCE)matmul3.cpp -o $(BINARY)matmul3.out $(LDFLAGS)

team:
	@echo "Niteesh Kamal Chaudhary 200010035@iitdh.ac.in"
	@echo "Varendra Maurya 200010055@iitdh.ac.in"
