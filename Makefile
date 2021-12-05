# tool
CC ?= gcc
CCFLAGS := -Wall -g
LINKER_FLAGS = -L./dep -libSDL2
CCOBJFLAGS := $(CCFLAGS) -c

# path
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src


# compile
TARGET_NAME := App
TARGET := $(BIN_PATH)/$(TARGET_NAME)

SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
SRC += $(foreach x, include, $(wildcard $(addprefix $(x)/*,c.*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

all: $(TARGET)

$(TARGET): $(SRC)

	$(CC) $(CCFLAGS) -o $@ $(SRC) -Iinclude -Llib -lSDL2 -lm
clean:
	rm $(TARGET)
