NAME = push_swap

CC = cc

CFLAGS = -O3 -Wall -Wextra -fsanitize=address -g

SRCS = main.c \
	   Aux/ft_atoi.c \
	   Aux/ft_split.c \
	   Aux/ft_isdigit.c \
	   Aux/ft_strlen.c \
	   lists_aux.c \
	   lists_aux2.c \
	   lists_aux3.c \
	   check_input.c \
	   Operations/swap.c \
	   Operations/push.c \
	   Operations/reverse_rotate.c \
	   Operations/rotate.c \
	   swap_anytwo.c \
	   quick_sort.c \
	   chunk.c \
	   cost.c 


OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all