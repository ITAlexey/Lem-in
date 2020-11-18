NAME    := libft.a

INC     := includes/

OBJ_DIR := objs

CYAN     = \033[36m
RED      = \033[31m
RESET    = \033[0m

CC      := gcc

CFLAGS  := -Wall -Wextra -Werror

HEADERS := $(shell find includes/ -type f | cut -d "/" -f 2)

BOOL    := $(shell find srcs/bool/ -type f | cut -d "/" -f 3)
CONV    := $(shell find srcs/conv/ -type f | cut -d "/" -f 3)
LST     := $(shell find srcs/lst/ -type f | cut -d "/" -f 3)
MEM     := $(shell find srcs/mem/ -type f | cut -d "/" -f 3)
STR     := $(shell find srcs/str/ -type f | cut -d "/" -f 3)
PRINTF  := $(shell find srcs/printf/ -type f | cut -d "/" -f 3)
OTHERS  := $(shell find srcs/others/ -type f | cut -d "/" -f 3)
PUT     := $(shell find srcs/put/ -type f | cut -d "/" -f 3)
HASHMAP := $(shell find srcs/hashmap/ -type f | cut -d "/" -f 3)
QUEUE   := $(shell find srcs/queue/ -type f | cut -d "/" -f 3)


SRCS    := $(BOOL)
SRCS    += $(CONV)
SRCS    += $(LST)
SRCS    += $(MEM)
SRCS    += $(STR)
SRCS    += $(PRINTF)
SRCS    += $(OTHERS)
SRCS    += $(PUT)
SRCS    += $(HASHMAP)
SRCS    += $(QUEUE)

LIB_OBJ  = $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

VPATH = srcs/bool:\
		srcs/conv:\
		srcs/lst:\
		srcs/mem:\
		srcs/str:\
		srcs/printf:\
		srcs/others:\
		srcs/put:\
		srcs/hashmap:\
		srcs/queue\

all: objects $(NAME)

$(NAME): $(LIB_OBJ)
	@echo "$(CYAN)Creating library ...$(RESET)"
	@ar rcs $@ $(LIB_OBJ)
	@echo "$(RED)libft has successfully created!\n$(RESET)"

objects:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(addprefix $(INC), $(HEADERS))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	@echo "$(CYAN)Removing objects dir$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Library has been removed\n$(RESET)"

norm:
	@echo "$(RED)Checking libft files ...$(RESET)"
	@norminette srcs/*/
	@norminette $(INC)

re: fclean all

.PHONY: all, objects, clean, fclean, re, norm
