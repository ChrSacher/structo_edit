GXX=g++
LD=g++
GXX_FLAGS=-std=c++11
LD_FLAGS=-lm

OBJECTS=main.o Element.o

EXECUTABLE=test_structogram_cli

$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LD_FLAGS) -o "$@" $(OBJECTS)

%.o: %.cpp %.h
	$(GXX) -c $(GXX_FLAGS) "$<" -o "$@"
