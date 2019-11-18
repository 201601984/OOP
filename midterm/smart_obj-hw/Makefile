.SUFFIXES: .cpp .o

OBJECTS = test.o human.o student.o smart_obj.o shared_ref.o weak_pointer.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
			  $(CXX) -o $(TARGET) $(OBJECTS)
					   
clean :
		rm -rf $(OBJECTS) $(TARGET)

test.o : test.cpp

