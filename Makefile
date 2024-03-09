FLAGS = -std=c++11 -Wall -Wextra

# Directories
SRCDIR = src
BINDIR = bin
BLDDIR = build
TARGET = main

$(TARGET): $(BLDDIR)/main.o $(BLDDIR)/bee.o $(BLDDIR)/player.o
	@mkdir -p $(BINDIR)
	g++ $(FLAGS) $(BLDDIR)/main.o $(BLDDIR)/player.o $(BLDDIR)/bee.o -o $(BINDIR)/${TARGET}

$(BLDDIR)/main.o: $(SRCDIR)/main.cpp
	@mkdir -p $(BLDDIR)
	g++ $(FLAGS) -c $(SRCDIR)/main.cpp -o $(BLDDIR)/main.o

$(BLDDIR)/bee.o: $(SRCDIR)/bee.cpp
	@mkdir -p $(BLDDIR)
	g++ $(FLAGS) -c $(SRCDIR)/bee.cpp -o $(BLDDIR)/bee.o

$(BLDDIR)/player.o: $(SRCDIR)/player.cpp
	@mkdir -p $(BLDDIR)
	g++ $(FLAGS) -c $(SRCDIR)/player.cpp -o $(BLDDIR)/player.o

clean:
	rm -r $(BINDIR)
	rm -r $(BLDDIR)

run:
	$(BINDIR)/$(TARGET)
