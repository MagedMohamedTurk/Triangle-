# the compiler to use
CC = clang

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
  
#files to link:
LFLAGS = -lcs50 
  
# the name to use for both the target source file, and the output file:
TARGET = test_triangle
  
all: $(TARGET) test
  
$(TARGET): $(TARGET).c ../check_triangle.c ../check_triangle.h
	$(CC) $(CFLAGS)  $(TARGET).c ../check_triangle.c unity.c -o $(TARGET) $(LFLAGS) 

test:
	./test_triangle
	