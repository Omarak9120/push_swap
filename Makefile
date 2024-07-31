# Standard
NAME                = push_swap

# Directories
LIBFT               = ./libft/libft.a
INC                 = inc/
SRC_DIR             = srcs/
OBJ_DIR             = obj/

# Compiler and CFlags
CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra -I $(INC) -g
RM                  = rm -f

# Source Files
PUSH_SWAP_DIR       = $(SRC_DIR)handle_errors.c \
	  $(SRC_DIR)init_a_to_b.c \
	  $(SRC_DIR)init_b_to_a.c \
	  $(SRC_DIR)push_swap.c \
	  $(SRC_DIR)stack_init.c \
	  $(SRC_DIR)push_op.c \
	  $(SRC_DIR)reverse_rotate_op.c \
	  $(SRC_DIR)rotate_op.c \
	  $(SRC_DIR)swap_op.c \
	  $(SRC_DIR)sort_stacks.c \
	  $(SRC_DIR)sort_three.c \
	  $(SRC_DIR)push_swap_utils.c \
	  $(SRC_DIR)rotate_both.c 

# Concatenate all source files
SRCS                = $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ                 = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:              
	@$(MAKE) all

$(LIBFT):
	@$(MAKE) -C ./libft

all:                $(NAME)

$(NAME):            $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:      $(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C ./libft

fclean:             clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re:                 fclean all

# Phony targets represent actions not files
.PHONY:             start all clean fclean re
