# This is the main compiler
CXX := g++
# CXX := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
INCDIR := include
BUILDDIR := build
BINDIR := bin
TARGET := $(BINDIR)/addon
 
#SRCEXT := cpp
#SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
#OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CXXFLAGS := -g # -Wall
#LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
#INC := $(shell find $(INCDIR) -maxdepth 1 -type d -exec echo -I {}  \;)

$(TARGET): 
	node-gyp clean configure --arch=mips --verbose rebuild

#$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
#    @mkdir -p $(dir $@)
#    @echo " $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<"; $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(BINDIR)"; $(RM) -r $(BUILDDIR) $(BINDIR)



# Spikes
#ticket:
#  $(CXX) $(CXXFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
