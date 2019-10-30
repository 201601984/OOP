.SUFFIXES: .cpp .o

OBJECTS = test.o smart_ptr/object.o smart_ptr/smart_obj.o smart_ptr/shared_mut.o smart_ptr/unique_immut.o
OBJECTS2 = main.o smart_ptr/object.o smart_ptr/smart_obj.o smart_ptr/shared_mut.o smart_ptr/unique_immut.o


CXX = g++
SMT_PTR = smart_ptr

TARGET = test

$(TARGET) : $(OBJECTS2)
	$(MAKE) -C $(SMT_PTR)
	$(CXX) -o $(TARGET) $(OBJECTS2)

clean :
	rm -rf $(OBJECTS2) $(TARGET)

main.o : main.cpp

TARGET2 = test_all

$(TARGET2) : $(OBJECTS)
			 $(CXX) -o $(TARGET2) $(OBJECTS)

test.o : test.cpp
