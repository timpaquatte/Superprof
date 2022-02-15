CXX := g++
LDFLAGS := -lpthread
targets := exo1

all: ${targets}

%: %.cpp
	$(CXX) $? -o $@ ${LDFLAGS}

clean:
	rm -f $(targets)