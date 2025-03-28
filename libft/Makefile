NAME = libft.a
SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_abs.c \
		ft_split_len.c \
		ft_free_split.c \
		ft_strlowcase.c \
		ft_strupcase.c \
		ft_str_is_numeric.c \
		ft_str_is_alpha.c \
		ft_str_is_uppercase.c \
		ft_str_is_lowercase.c \
		ft_sort_tab.c \
		ft_atoi_base.c \
		ft_atoi_hexa.c \
		ft_degtorad.c \
		ft_radtodeg.c \
		ft_to_trgb.c \
		*ft_sort_tab.c \
		ft_tab_is_sort.c \
		ft_median.c \
		ft_average.c \
		ft_strcmp.c \
		ft_strjoin_ptr.c \
		ft_strstr.c \
		ft_strrstr.c \
		ft_splits.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c libft.h Makefile
	$(CC) $(FLAGS) -g3 -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
