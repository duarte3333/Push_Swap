NAME = push_swap

CC = cc

CFLAGS = -O3 -Wall -Wextra -fsanitize=address -g

SRCS = main.c \
	   Aux/ft_atoi.c \
	   Aux/ft_split.c \
	   Aux/ft_isdigit.c \
	   Aux/ft_strlen.c \
	   Aux/lists_aux.c \
	   Aux/lists_aux2.c \
	   Operations/swap.c \
	   Operations/push.c \
	   Operations/reverse_rotate.c \
	   Operations/rotate.c \
	   check_input.c \
	   put_top.c \
	   print_list.c \
	   smaller_sort.c \
	   algorithm.c \
	   quick_sort.c \
	   quick_sort_again.c \
	   quick_final.c \
	   median.c \
	   median_partition.c \
	   cost.c \
	   cost_algorithm.c \
	   pre_quick_sort.c


OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all