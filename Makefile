# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11
# Source files
SRCS = main.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
EXEC = program

# Default target
all: $(EXEC)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)
