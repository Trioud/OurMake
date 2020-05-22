/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays one by one string
*/

#include "../include/my.h"

void my_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
