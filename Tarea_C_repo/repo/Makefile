# The compiler
CC = gcc

# Compiler flags
CFLAGS  = -I.

# the build target executable:
TARGET = pkmn_sim

# Source files
SRCS = func_pkmn

# This creates the .o files from the dependency list
%.o: %.c $(SRCS).h
	$(CC) -c -o $@ $< $(CFLAGS)

# Build of the execution file
$(TARGET): $(TARGET).o $(SRCS).o
	$(CC) -o $(TARGET) $(TARGET).o $(SRCS).o

# Delete the object files
clean:
	del *.o