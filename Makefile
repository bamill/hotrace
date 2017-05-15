NAME = hotrace

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pg

INCLUDES = -Iinclude

SRCS = src/delet.c \
	src/destroy_table.c \
	src/div_hash.c \
	src/ft_bzero.c \
	src/ft_list_remove_if.c \
	src/ft_lstadd.c \
	src/ft_lstcpy.c \
	src/ft_lstdel.c \
	src/ft_lstnew.c \
	src/ft_memcpy.c \
	src/ft_memdel.c \
	src/ft_strchr.c \
	src/ft_strcmp.c \
	src/ft_strdup.c \
	src/ft_strjoin.c \
	src/ft_strlen.c \
	src/ft_strncpy.c \
	src/ft_strnew.c \
	src/generate_hash_fun.c \
	src/generate_hash_table.c \
	src/get_next_line.c \
	src/grow_table.c \
	src/insert.c \
	src/main.c \
	src/prehash.c \
	src/read_input.c \
	src/search.c \
	src/shrink_table.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
