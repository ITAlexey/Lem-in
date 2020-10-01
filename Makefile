CFLAGS := -Wall -Wextra

CC    := gcc

VPATH = srcs:tests:tests/validation

LIB   := libft.a

LIB_DIR := libft/

INC   := includes/

LIBINC := $(LIB_DIR)includes

TEST_INC := tests/

NAME  := lem-in

O_DIR := objects

SRC   := test_lemin \
		test_validation \
		test_rooms \
		test_comments \
		test_ants \
		test_links \
		parse_input \

OBJS  := $(addsuffix .o, $(addprefix $(O_DIR)/, $(SRC)))

all: folder $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -sC $(LIB_DIR)

folder:
	@mkdir -p $(O_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB_DIR)$(LIB) -o $@

$(O_DIR)/%.o: %.c $(INC) $(LIBINC) $(TEST_INC)
	@$(CC) $(CFLAGS) -g -o $@ -c $< -I$(INC) -I$(LIBINC) -I$(TEST_INC)

clean:
	@$(MAKE) clean -sC $(LIB_DIR)
	@rm -rf $(O_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, folder, re, clean, fclean, tests
