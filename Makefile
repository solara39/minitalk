SERVER_SRC	= server.c
CLIENT_SRC	= client.c

LIBFT_SRCS	=	libft/ft_atoi.c 
			libft/ft_bzero.c 
			libft/ft_calloc.c 
			libft/ft_isalnum.c 
			libft/ft_isalpha.c 
			libft/ft_isascii.c 
			libft/ft_isdigit.c 
			libft/ft_isprint.c 
			libft/ft_itoa.c 
			libft/ft_memchr.c 
			libft/ft_memcmp.c 
			libft/ft_memcpy.c 
			libft/ft_memmove.c 
			libft/ft_memset.c 
			libft/ft_putchar_fd.c 
			libft/ft_putendl_fd.c 
			libft/ft_putnbr_fd.c 
			libft/ft_putstr_fd.c
			libft/ft_split.c 
			libft/ft_strchr.c 
			libft/ft_strdup.c 
			libft/ft_striteri.c 
			libft/ft_strjoin.c 
			libft/ft_strlcat.c 
			libft/ft_strlcpy.c 
			libft/ft_strlen.c 
			libft/ft_strmapi.c 
			libft/ft_strncmp.c 
			libft/ft_strnstr.c 
			libft/ft_strrchr.c 
			libft/ft_strtrim.c 
			libft/ft_substr.c 
			libft/ft_tolower.c 
			libft/ft_toupper.c

fPRINTF_SRCS	=	ft_printf/ft_printf.c
			ft_printf/t_count_output.c	
			ft_printf/ft_strdup.c 
			ft_printf/ft_handle_char.c 
			ft_printf/ft_strlen.c 
			ft_printf/ft_handle_hexa.c 
			ft_printf/ft_tolower_str.c 
			ft_printf/ft_handle_integer.c 
			ft_printf/ft_treat_args.c 
			ft_printf/ft_handle_point.c 
			ft_printf/ft_treat_specifier.c 
			ft_printf/ft_handle_string.c 
			ft_printf/ft_toupper_str.c 
			ft_printf/ft_itoa.c 
			ft_printf/ft_putstr_fd.c 
			ft_printf/ft_putchr_fd.c 
			ft_printf/ft_changebase_tohexa.c 
			ft_printf/ft_handle_unit.c

SRCS		= $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJS		= $(SRCS: .c=.o)
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_FLAG	= -o
LEAK_FLAG	= -fsanitize=address -g

all:server client

OBJS		= $(SRCS:.c=.o)

$(SERVER_NAME):$(OBJS) $(SERVER_SRC)
	$(CC) $(CFLAGS) $(NAME_FLAG) $(SERVER_SRC) $(OBJS)

$(CLIENT_NAME):$(OBJS) $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(NAME_FLAG) $(CLIENT_SRC) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re:fclean all

.PHONY: all fclean re clean
