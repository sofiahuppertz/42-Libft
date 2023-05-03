#include <stddef.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *string;
    unsigned char ch;
    unsigned char   *result;
    size_t i;

    string = (unsigned char *)s;
    ch = (unsigned char)c;
    i = 0;
    result = NULL;

    while(i < n)
    {
        if(string[i] == ch)
        {
            result = &string[i];
            return (result);
        }
        i++;
    }
    return (result);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    int string = 123456;
    int c = 4;
    printf("The adress of first %c is %p\n", (char)c, ft_memchr(string, c, 5));
    printf("\n\n\n");
    printf("The adress of first %c is %p\n", (char)c, memchr(string, c, 5));
}

