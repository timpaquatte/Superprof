CXX := g++
LDFLAGS := -lpthread
targets != exo1 exo2 exo3

all: exo2

%: %.cpp
	$(CXX) $? -o $@ ${LDFLAGS}

clean:
	rm -f $(targets)