/*
** EPITECH PROJECT, 2020
** de
** File description:
** de
*/

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdlib.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <ftw.h>
#include <fnmatch.h>
#include <string.h>


#ifndef MY_H
#define MY_H

typedef struct list {
    char *value;
    struct list *next;
}list;

char *my_strcat(char *dest, char *src);
int my_putchar(char c);
void my_putstr(char *str);
char *get_current_dir_name(void);
int my_strlen(char const *str);
#endif