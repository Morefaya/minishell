CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = main.c lst_tab2d.c print_lst.c read_cmd.c print_tab2d.c free_tab2d.c \
builtins.c get_paths_vars.c get_arg.c get_cmd.c make_cmd_path.c \
minishell.c tab2d_lst.c ft_unsetenv.c ft_setenv.c ft_env.c ft_env_2.c lstenv_cpy.c \
tool.c ft_exit.c ft_cd.c tablen.c get_a_pwd.c get_pwd.c get_var_env.c ft_cd_2.c \
cmp_env.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LIB = libft/libft.a
FILE = 
NAME = minishell
.PHONY: re run rr clean fclean all

all: $(LIB) $(NAME)

%.a:
	@make -C $(dir $@)

clean_lib:
	@make fclean -C $(dir $(LIB))

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) $(LIB) $(OBJ_O) $(CFLAG)
	@echo "\033[32m$(NAME) done\033[0m"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O) $(OBJ_DIR)
	@echo "\033[31mobject files removed\033[0m"

fclean: clean clean_lib
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) removed\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
