CC= cc

CFLAGS= -Wall -Wextra -Werror -fsanitize=address

NAME= push_swap

SRCS= main.c ft_atoi.c split.c instructions.c instructions1.c helper.c helper2.c small_sort.c big_sort.c helper1.c helper3.c helper4.c

SRCS_BNS= checker.c ft_atoi.c helper.c helper1.c helper4.c instructions.c instructions1.c split.c get_next_line.c get_next_line_utils.c  

OBJS= $(SRCS:.c=.o)

OBJS_BNS= $(SRCS_BNS:.c=.o)

all: $(NAME)

bonus: $(OBJS_BNS)
	$(CC) $(CFLAGS) $(OBJS_BNS) -o checker
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		   $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BNS)

fclean: clean
	rm -rf $(NAME) checker
	
re: fclean all
