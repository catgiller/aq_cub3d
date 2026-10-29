NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

SRC = \
	ft_atoi.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strncmp.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
