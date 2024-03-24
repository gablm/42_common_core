NAME=push_swap
CK_NAME=checker

COMPILER=cc
FLAGS=-Wall -Wextra -Werror

FILES= ps.c ps_utils.c \
	ps_sorter.c ps_sorter_small.c ps_sorter_other.c \
	ps_op_p.c ps_op_r.c ps_op_rr.c ps_op_s.c \
	ps_output.c ps_verify.c

INCLUDES = headers/
HEADERS = headers/ps.h

all: $(NAME)

$(NAME): $(FILES) $(HEADERS)
	$(MAKE) -C libft bonus
	$(COMPILER) $(FLAGS) $(FILES) -I$(INCLUDES) -o $(NAME) -Llibft/ -lft

clean:
	$(MAKE) -C libft clean
	rm -fr $(FILES:.c=.o)

fclean:
	$(MAKE) -C libft fclean
	rm -fr $(NAME) 

re: fclean all
