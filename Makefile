CC=g++
OPTS=-g -Wall -std=c++11
BIN=nn
SOURCES=main.cpp mat.cpp randmt.cpp
OBJECTS=$(SOURCES:.cpp=.o)
$(BIN) : $(OBJECTS)
	$(CC) $(OPTS) $^ -o $@
$(OBJECTS): %.o : %.cpp
	$(CC) -c $(OPTS) $^ -o $@
clean:
	rm $(OBJECTS) $(BIN)
