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

NAME := push_swap
BNAME := checker
HEADER_SRCS := push_swap.h libft/libft.h
SOURCES = \
	push_swap.c push_swap_utils.c instructions.c tri.c petit_tri_utils.c \
	gros_tri_utils.c
BSOURCES = \
	checker.c push_swap_utils.c instructions.c get_next_line.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)
INCLUDE := $(sort $(addprefix -I,$(dir $(HEADER_SRCS))))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: libft $(NAME)
	@printf "\033[2K\r$(_GREEN)$(_BOLD)Done.\n"



$(NAME): Makefile libft/libft.a $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) libft/libft.a -o $@
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  $@" "$(_BOLD)[OK]$(_END)\n\n"

$(BNAME): Makefile libft/libft.a $(BOBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(BOBJECTS) libft/libft.a -o $@
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  $@" "$(_BOLD)[OK]$(_END)\n\n"

%.o: %.c libft/libft.a $(HEADER_SRCS)
	@printf "%-30b%b" "\033[2K\r$(_YELLOW)  $(NAME)" "\033[1m[$<]\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: libft $(BNAME)
	@printf "\033[2K\r$(_GREEN)$(_BOLD)Done.\n"

libft:
	@printf "$(_CYAN)$(_BOLD)Compilation:$(_END)\n"
	@$(MAKE) -s -C libft

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)
	@make clean -C libft
	@printf "\033[2K\r$(_RED)$(NAME): Tout les objets ont ete supprimes. $(_END)\n"

fclean: clean
	@rm -f push_swap checker libft/libft.a
	@printf "\033[2K\r$(_RED)Tout les programmes ont ete supprimes. $(_END)\n"

re: fclean all

norme:
	@norminette .
.PHONY: all bonus libft clean fclean re norme

