#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}
/*
#include <stdio.h>
int main(void)
{
    char *first = "hello world";
    char *secnd = "hello";

    printf("%i\n",ft_strncmp(secnd, first, 10));
}
*/