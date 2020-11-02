CFLAGS := -Wall -Wextra 

CC    := gcc

VPATH = srcs:srcs/validation:srcs/algorithm

LIB   := libft.a

LIB_DIR := libft/

INC   := includes/

LIBINC := $(LIB_DIR)includes

NAME  := lem-in

O_DIR := objects

SRC   := define_link \
		define_command \
		parse_input \
		main \
		find_path \
		find_solution \
		optimaze_path \
		prepare_paths \
		restore_path \
		sort_paths \
		utils \
		print_solution \

OBJS  := $(addsuffix .o, $(addprefix $(O_DIR)/, $(SRC)))

all: folder $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -sC $(LIB_DIR)

folder:
	@mkdir -p $(O_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB_DIR)$(LIB) -o $@

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
