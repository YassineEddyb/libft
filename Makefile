SRC			= ft_atoi.c         ft_isprint.c      ft_memchr.c       ft_putnbr_fd.c    ft_strlcat.c      ft_strtrim.c\
ft_bzero.c        ft_itoa.c         ft_memcmp.c       ft_putstr_fd.c    ft_strlcpy.c      ft_substr.c\
ft_calloc.c       ft_lstadd_back.c  ft_memcpy.c       ft_split.c        ft_strlen.c       ft_tolower.c\
ft_isalnum.c      ft_lstadd_front.c ft_memmove.c      ft_strchr.c       ft_strmapi.c      ft_toupper.c\
ft_isalpha.c      ft_lstlast.c      ft_memset.c       ft_strdup.c       ft_strncmp.c\
ft_isascii.c      ft_lstnew.c       ft_putchar_fd.c   ft_striteri.c     ft_strnstr.c\
ft_isdigit.c      ft_lstsize.c      ft_putendl_fd.c   ft_strjoin.c      ft_strrchr.c
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
PRE			= ./srcs/
HEAD		= libft.h
NAME		= libft.a
GCC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
