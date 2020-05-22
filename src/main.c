/*
** EPITECH PROJECT, 2020
** de
** File description:
** de
*/

#include "../include/my.h"
list *gen = NULL;

void print_srcs(int fd)
{
    list *tmp = gen;

    write(fd, " ", 1);
    while (tmp != NULL) {
        write(fd, tmp->value, my_strlen(tmp->value));
        tmp = tmp->next;
        write(fd, " ", 1);
        write(fd, "\\", 1);
        write(fd, "\n\t", 2);
    }
    write(fd, "\n", 1);
}

void normal_template()
{
    int fd = 0;
    int fd_error = 0;
    list *tmp = gen;
    int size = 0;

    remove("Makefile");
    fd = open("Makefile", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    size = write(fd, "NAME = program\nCC = gcc\nRM = rm -f\n", 35);
    write(fd, "SRCS =", 6);
    print_srcs(fd);
    write(fd, "OBJS = $(SRCS:.c=.o)\n", 21);
    write(fd, "CFLAGS = -I\nCFLAGS += -Wall -Wextra\n\n", 37);
    write(fd, "ECHO		+= echo -e\n\n", 18);
    write(fd, "all: $(NAME)\n", 13);
    write(fd, "$(NAME): $(OBJS)\n\t$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)\n", 54);
   write(fd, "\t@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled\033[01;34m<-\033[01;34m---------------\033[01;00m'\n\n", 108);
    write(fd, "clean:\n\t$(RM) $(OBJS)\n", 22);
    write(fd, "\t@$(ECHO) '\033[01;31m-----------------\033[01;31m->\033[01;33mAll clean\033[01;31m<-\033[01;31m----------------\033[01;00m'\n\n", 108);
    write(fd, "fclean: clean\n\t$(RM) $(NAME)\n\t@$(ECHO) '\033[01;36m---------------\033[01;36m->\033[01;36mBinary clean\033[01;36m<-\033[01;36m---------------\033[01;00m'\n\nre: fclean all\n\n", 153);

    write(fd, ".PHONY: all clean fclean re", 27);
}

void my_put_in_list(char *filename)
{
    list *elem = malloc(sizeof(list));
    elem->value = filename;
    elem->next = NULL;
    list *tmp = gen;

    if (tmp == NULL) {
        gen = elem;
        return;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = elem;
}

int nftwfunc(const char *filename, const struct stat *statptr,
    int fileflags, struct FTW *pfwt)
{
    static int i;
    if (fnmatch("*.c", filename, 0) == 0) {
        my_put_in_list(strdup(filename));
    }
    return 0;
}

int main(int ac, char **argv)
{
    int flags = FTW_F;
   
    if (nftw(".", nftwfunc, 300, flags) == -1)
        printf("error\n");
    list *tmp = gen;
    if (ac == 1)
        normal_template();
}