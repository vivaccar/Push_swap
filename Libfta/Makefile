FILES	= 		ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_strlen.c ft_tolower.c \
				ft_toupper.c ft_strlcat.c ft_strlcpy.c ft_strlcpy.c \
				ft_strncmp.c ft_strchr.c ft_strrchr.c ft_memset.c \
				ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_putchar_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_strjoin.c \
				ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
				ft_striteri.c 

BONUSFILES =  	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS	= $(FILES:.c=.o)

BONUSOBJS = $(BONUSFILES:.c=.o)

CC		= cc

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUSOBJS)
			ar rcs $(NAME) $(OBJS) $(BONUSOBJS)

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
