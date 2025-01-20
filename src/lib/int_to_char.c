/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** int_to_char
*/

#include "my.h"

char *int_to_char(int n)
{
    int len = (n < 0) ? 2 : 1;
    int temp = n;
    char *result = malloc((len + 1) * sizeof(char));

    (temp /= 10);
    while (temp != 0) {
        len++;
        (temp /= 10);
    }
    if (!result)
        return NULL;
    result[len] = '\0';
    if (n < 0)
        result[0] = '-';
    for (int i = len - 1; i >= (n < 0); i--) {
        result[i] = (n < 0 ? -(n % 10) : n % 10) + '0';
        n /= 10;
    }
    return result;
}
