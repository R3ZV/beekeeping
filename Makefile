FLAGS = -std=c++11 -Wall -Wextra -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRCDIR = src
BINDIR = bin
BLDDIR = build
TARGET = main

SRCS = $(shell find $(SRCDIR) -name "*.cpp")
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BLDDIR)/%.o, $(SRCS))

$(BINDIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	g++ $(FLAGS) $^ -o $@

$(BLDDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)
	@mkdir -p $(dir $@)
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -r $(BINDIR)
	rm -r $(BLDDIR)

run:
	$(BINDIR)/$(TARGET)
