CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++17		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
SRCS = graph.cpp test.cpp # anything you want compiled change this
DEPS = $(SRCS:.cpp=.d)
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = test

all: $(EXECUTABLE)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(EXECUTABLE): $(OBJS)
	 $(CC) $(OBJS) -o $(EXECUTABLE)
	
clean:
	rm -f *.o $(EXECUTABLE)