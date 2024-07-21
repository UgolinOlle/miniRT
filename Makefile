CC = gcc
CPPFLAGS = -Iincludes -Isrc -Ilibs/get_next_line/includes -Ilibs/libft/includes
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lm
LIB_DIR = libs

SRC = src
OBJ = obj
BIN = rt

LIBFT_DIR = libs/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

GNL_DIR = libs/get_next_line
GNL_LIB = $(GNL_DIR)/libget_next_line.a

LIBS = -L$(LIB_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd -L$(GNL_DIR) -lget_next_line -L$(LIBFT_DIR) -lft
MKDIR = mkdir -p

SRCs := $(shell find $(SRC) -name "*.c")
OBJs := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCs))

all: $(LIBFT_LIB) $(GNL_LIB) $(BIN)

$(BIN): $(OBJs) $(LIB_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJs) $(LIBS) -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) -R $(BIN)
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -R $(OBJ)
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
