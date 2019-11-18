.SUFFIXES: .cpp .o

OBJECTS = test.o Integer.o Float.o Complex.o

CXX = g++
CPPFLAGS = -c
TARGET = test


$(TARGET) : $(OBJECTS)
			  $(CXX) -o $(TARGET) $(OBJECTS)

clean :
		rm -rf $(OBJECTS) $(TARGET)
