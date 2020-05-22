/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates two functions
*/
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    int i;
    int a;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest[i] != '\0'; ++i)
        str[i] = dest[i];
    for (a = 0; src[a] != '\0' && src[a] != '\n'; ++a, ++i)
        str[i] = src[a];
    str[i] = '\0';
    return (str);
}