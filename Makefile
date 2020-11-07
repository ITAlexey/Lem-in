CYAN     = \033[36m
RED      = \033[31m
RESET    = \033[0m

CFLAGS := -Wall -Wextra -Werror 

CC    := gcc

VPATH = srcs:srcs/validation:srcs/algorithm

LIB   := libft.a

LIB_DIR := libft/

INC   := includes/

LIBINC := $(LIB_DIR)$(INC)

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
		sdl_window \
		draw_background \
		ant_deal \
		draw_movements \

OBJS  := $(addsuffix .o, $(addprefix $(O_DIR)/, $(SRC)))

all: folder $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -sC $(LIB_DIR)
	@echo "$(CYAN)Building project ...$(RESET)"

folder:
	@mkdir -p $(O_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB_DIR)$(LIB) -o $@ -lSDL2 -lSDL2_ttf
	@echo "$(RED)Project has been successfully built$(RESET)"

$(O_DIR)/%.o: %.c $(INC) $(LIBINC) 
	@$(CC) $(CFLAGS) -g -o $@ -c $< -I$(INC) -I$(LIBINC)

norm:
	@$(MAKE) norm -sC $(LIB_DIR)
	@echo "$(RED)Checking project files ...$(RESET)"
	@norminette srcs/*.c srcs/*/*.c
	@norminette $(INC)

test: all
	@./checker.sh

clean:
	@$(MAKE) clean -sC $(LIB_DIR)
	@rm -rf $(O_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIB_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)Execution file has been deleted\n$(RESET)"

re: fclean all

.PHONY: all, folder, re, clean, fclean, norm, test
