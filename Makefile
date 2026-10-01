CC      = clang
CFLAGS  = -Wall -Wextra -g
LDFLAGS = -lncurses

SRC     = main.c
OBJ     = $(SRC:.c=.o)

TARGET  = ./viewer-text

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)