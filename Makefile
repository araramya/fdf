SRCS = ${shell find -maxdepth 1 -name "*.c" ! -name "_bonus.c"}
BONUSES = ${shell find -maxdepth 1 -name "*.c" -name "key_hooks.c"}
OBJS   = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUSES:.c=.o}
NAME = fdf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
RM = rm -f
AR = ar csr

.c.o :
	${CC} ${CFLAGS} ${FRAMEWORKS} -c &< -o ${<:.c=.o}
	$(NAME) : ${OBJS}

bonus : ${BONUS_OBJS}
	${AR} fdf.a ${BONUS_OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}
flcean : clean
	${RM} ${NAME}
re : fclean all

.PHONY: all clean fclean re .c.o