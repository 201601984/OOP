.SUFFIXES: .cpp .o

OBJECTS = main.o GameController.o IOManager.o Random.o Array_2d.o Block.o Big_Block.o Fold_Block.o Tree_Block.o Cross_Block.o Color_Block.o


CXX = g++
CPPFLAGS = -c -g

TARGET = main

$(TARGET) : $(OBJECTS)
			  $(CXX) -g -o $(TARGET) $(OBJECTS)

clean :
		rm -rf $(OBJECTS) $(TARGET)
