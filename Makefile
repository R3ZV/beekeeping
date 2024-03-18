CC := g++
CFLAGS := -std=c++11 -Wall -Wextra
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
INCLUDES := -I/usr/local/include
LIBRARIES := -L/usr/local/lib

# Directories
SRCDIR = src
BINDIR = bin
BLDDIR = build
TARGET = main

SRCS = $(shell find $(SRCDIR) -name "*.cpp")
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BLDDIR)/%.o, $(SRCS))

$(BINDIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) $(LIBRARIES) -o $@ $^ $(LDFLAGS)

$(BLDDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -r $(BINDIR)
	rm -r $(BLDDIR)

run:
	$(BINDIR)/$(TARGET)
