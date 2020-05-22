NAME = program
CC = gcc
RM = rm -f
SRCS = ./my_putstr.c \
	./main.c \
	./my_putchar.c \
	./my_strcat.c \
	
OBJS = $(SRCS:.c=.o)
CFLAGS = -I
CFLAGS += -Wall -Wextra

ECHO		+= echo -e

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	@$(ECHO) '[01;31m-----------------[01;31m->[01;33mAll clean[01;31m<-[01;31m----------------[01;00m'

fclean: clean
	$(RM) $(NAME)
	@$(ECHO) '[01;36m---------------[01;36m->[01;36mBinary clean[01;36m<-[01;36m---------------[01;00m'

re: fclean all

.PHONY: all clean fclean re