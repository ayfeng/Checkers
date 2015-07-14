CC=g++
CFLAGS=-Wall -pedantic -std=c++11 -g
SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.hpp)
OBJS=$(SOURCES:.cpp=.o)
EXEC=run

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS) $(EXEC)

