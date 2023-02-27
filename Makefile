NAME = push_swap

CC = cc

CFLAGS = -O3 -Wall -Wextra -Werror -fsanitize=address -g

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
	   cost_algorithm.c \
	   cost_aux_functions.c \
	   load_list.c \
	   print_list.c \
	   put_top.c \
	   smaller_sort.c 


OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all