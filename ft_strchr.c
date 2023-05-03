#define NULL ((void *) 0);
char *ft_strchr(const char *s, int c)
{
    int i;
    char *result;

    i = 0;
    result = NULL;

    while (s[i] != '\0')               
    {

        if (s[i] == c)
        {
            result = (char *)&s[i];
            return (result);
        }
        i++;
    }
    return (result);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "aaa";
    char c = 'p';

    char *result = ft_strchr(str,c);
    printf("%p\n", (char *)ft_strchr(str, c));
    printf("Adress of str is %p\n", str);
    printf("The first occurrence of %c is index %li\n", c, result - str);
    printf("\n\n\n");

    char *original = strchr(str,c);
    printf("%p\n", (char *) strrchr(str, c));
    printf("Adress of str is %p\n", str);
    printf("The last occurrence of %c is index %li\n", c, original - str);
}
*/