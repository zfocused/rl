# Change this to your compiler (gcc for C, g++ for C++)
CC = gcc

# Compiler and Linker flags
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lraylib


# Platform detection
ifeq ($(OS),Windows_NT)
    # Windows flags (Assumes raylib is in your system path or project folder)
    # Add extra Windows subsystem libraries required by raylib
    LDFLAGS += -lopengl32 -lgdi32 -lwinmm -I"C:\raylib\raylib\src" -L"C:\raylib\raylib\src" -lraylib -lopengl32 -lgdi32 -lwinmm

    TARGET = main.exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        # Linux flags
        LDFLAGS += -lGL -lm -lpthread -ldl -lrt -lX11
        TARGET = main
    endif
    ifeq ($(UNAME_S),Darwin)
        # macOS flags
        LDFLAGS += -framework CoreVideo -framework IOHitTest -framework Cocoa -framework GLUT -framework OpenGL
        TARGET = main
    endif
endif

# Source files
SRCS = main.c

# Default rule to build the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
