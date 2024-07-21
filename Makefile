CC = gcc
CPPFLAGS = -Iincludes -Isrc -Ilibs/get_next_line/includes
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lm
LIB_DIR = libs

SRC = src
OBJ = obj
BIN = rt

GNL_DIR = libs/get_next_line
GNL_LIB = $(GNL_DIR)/libget_next_line.a

LIBS = -L$(LIB_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd -L$(GNL_DIR) -lget_next_line
MKDIR = mkdir -p

SRCs := $(shell find $(SRC) -name "*.c")
OBJs := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCs))

all: $(GNL_LIB) $(BIN)

$(BIN): $(OBJs) $(LIB_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJs) $(LIBS) -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(RM) -R $(BIN)
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	$(RM) -R $(OBJ)
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
