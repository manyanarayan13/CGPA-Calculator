CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = student_system
OBJS = main.o bus_tracking.o

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Build main.o
main.o: main.c bus_tracking.h
	$(CC) $(CFLAGS) -c main.c

# Build bus_tracking.o
bus_tracking.o: bus_tracking.c bus_tracking.h
	$(CC) $(CFLAGS) -c bus_tracking.c

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET) cgpa

# Install dependencies (none required for this simple C program)
install:
	@echo "No dependencies to install for this C program"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Build the original CGPA calculator for compatibility
cgpa: cgpa.c
	$(CC) $(CFLAGS) -o cgpa cgpa.c

.PHONY: all clean install run