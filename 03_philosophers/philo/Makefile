NAME=philo

COMPILER=cc
FLAGS=-Wall -Wextra -Werror -pthread -g -fsanitize=thread

FILES=p_main.c p_argcheck.c p_init.c p_init_main.c \
	p_loop_check.c p_loop_philo.c p_utils.c p_delete.c

HEADERS=philo.h

all: $(NAME)

$(NAME): $(FILES) $(HEADERS)
	$(COMPILER) $(FLAGS) $(FILES) -o $(NAME) 

clean:
	rm -fr $(FILES:.c=.o)

fclean:
	rm -fr $(NAME) 

re: fclean all
