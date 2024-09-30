# Style
_END		:=	\033[0m
_BOLD		:=	\033[1m
_UNDER		:=	\033[4m
_REV		:=	\033[7m

# Colors
_GREY		:=	\033[30m
_RED		:=	\033[31m
_GREEN		:=	\033[32m
_YELLOW		:=	\033[33m
_BLUE		:=	\033[34m
_PURPLE		:=	\033[35m
_CYAN		:=	\033[36m
_WHITE		:=	\033[37m

CC := gcc

CFLAGS := -Wall -Wextra -Werror

NAME=libft.a

HEADER_SRCS := libft.h

SRCS := ft_atoi.c ft_bzero.c ft_isalnum.c \
	 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
	 ft_isupper.c ft_itoa.c ft_split.c ft_substr.c \
	 ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	 ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	 ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strcmp.c \
	 ft_strcpy.c ft_strnew.c ft_strlcpy.c ft_calloc.c\
	 ft_strdup.c ft_strjoin.c \
	 ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strncat.c \
	 ft_strncmp.c ft_strncpy.c ft_strnstr.c \
	 ft_strrchr.c ft_strrev.c ft_strstr.c \
	 ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	 ft_lstadd_front.c ft_lstclear.c ft_lstnew.c  ft_abs_bonus.c \
	 ft_atol_bonus.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c \
	 ft_lstmap.c ft_lstsize.c ft_isspace_bonus.c ft_numlen_bonus.c ft_lstlast.c

OBJS := $(SRCS:.c=.o)
	 	
INCLUDE := $(addprefix -I,$(dir $(HEADER_SRCS)))

all: $(NAME)

$(NAME): Makefile $(OBJS)
	@ar rc $@ $(OBJS)
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  libft" "$(_BOLD)[OK]$(_END)\n"

%.o: %.c $(HEADER_SRCS)
	@printf "%-30b%b" "\033[2K\r$(_YELLOW)  libft:" "$(_BOLD)[$<]\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@printf "\033[2K\r$(_RED)libft: Tous les objets ont ete supprimes. $(_END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[2K\r$(_RED)libft: '"$(NAME)"' a ete supprime. $(_END)\n"

re: fclean all

norme:
	@norminette

.PHONY: all clean fclean  re norme