NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

GNL_DIR = get_next_line/
GNL_SRCS = get_next_line.c get_next_line_utils.c

SRCS = ft_lstadd_back.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	swap.c \
	rotate.c \
	push.c \
	reverse_rotate.c \
	init_stack_a.c \
	ft_atoi.c \
	ft_split.c \
	sort.c \
	sort_two.c \
	sort_three.c \
	sort_more.c \
	pos.c \
	find_target_b.c \
	sort_four.c \
	cheapest.c \
	move.c \
	push_swap.c

SRCB = ft_lstadd_back.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	swap_bonus.c \
	rotate_bonus.c \
	push_bonus.c \
	reverse_rotate_bonus.c \
	init_stack_a.c \
	ft_atoi.c \
	ft_split.c \
	apply_instructions.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_strcmp.c \
	checker_bonus.c

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BNAME): $(OBJB)
	@echo "Linking $(BNAME)..."
	@$(CC) $(CFLAGS) $(OBJB) -o $(BNAME)

%.o: %.c
	@echo "Compiling object file $<..."
	@$(CC) $(CFLAGS) -I$(GNL_DIR) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS) $(OBJB)

fclean: clean
	@echo "Cleaning executables..."
	@rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all bonus clean fclean re
