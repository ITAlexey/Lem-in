NAME  := lem-in

INC   := includes/

LIB   := libft.a

LIB_DIR := libft/

LIBINC := $(LIB_DIR)includes

O_DIR := objects

SRC   := main \
		parse_input

OBJS  := $(addsuffix .o, $(addprefix $(O_DIR)/, $(SRC)))

CFLAGS := -Wall -Wextra -Werror

CC    := gcc

VPATH = srcs:srcs/validation

all: folder $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -sC $(LIB_DIR)

folder:
	@mkdir -p $(O_DIR)

$(NAME): $(OBJS)
	#$(CC) $(OBJS) $(LIB_DIR)$(LIB) -o $@

$(O_DIR)/%.o: %.c $(INC) $(LIBINC)
	$(CC) $(CFLAGS) -g -o $@ -c $< -I$(INC) -I$(LIBINC)

clean:
	@$(MAKE) clean -sC $(LIB_DIR)
	@rm -rf $(O_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, folder, re, clean, fclean
