#define NULL ((void *) 0);

int     ft_strlen(const char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strrchr(const char *str, int c)
{
    int     i;
    char    *result;

    i = ft_strlen(str) - 1;
    result = NULL;
    // i - 1 >= 0 because strlen returns on index higher and array starts at index 0.
    while (i >= 0)
    {
        if (str[i] == c) 
        {
            result = (char *)&str[i];
            return (result);
        }
        i--;
    }

    return (result);
}
/*#include <stdio.h>

int main(void)
{
    char *str = "papapa";
    char c = 'p';
    char *result = ft_strrchr(str,c);

    printf("%p\n", (char *)ft_strrchr(str, c));
    printf("Adress of str is %p\n", str);
    printf("The last occurrence of %c is index %li\n", c, result - str);
}*/
