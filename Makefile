NAME = push_swap
CHECKER_NAME = checker

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
	   smaller_sort.c \
	   print_moves.c \
	   get_best_buddy.c 

CHECKER_SRCS = checker.c \
			   checker_utils.c \
			   Aux/ft_atoi.c \
			   Aux/ft_split.c \
			   Aux/ft_isdigit.c \
			   Aux/ft_strlen.c \
			   Aux/lists_aux.c \
			   Get_Next_Line/get_next_line.c \
			   Get_Next_Line/get_next_line_utils.c \
			   Operations/swap.c \
			   Operations/push.c \
			   Operations/reverse_rotate.c \
			   Operations/rotate.c \
			   print_moves.c \
	  		   check_input.c \
			   load_list.c 

OBJS	= ${SRCS:.c=.o}
CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

${CHECKER_NAME}: ${CHECKER_OBJS}
		${CC} ${CFLAGS} ${CHECKER_OBJS} -o ${CHECKER_NAME}

clean:
	rm -f ${OBJS}

clean_checker:
	rm -f $(CHECKER_OBJS)

fclean: clean
	rm -f ${NAME}

fclean_checker: clean_checker
		@rm -rf ${CHECKER_NAME}

fclean_all: clean fclean_checker

re: fclean all

re_checker: fclean_checker checker

.PHONY: all clean fclean re