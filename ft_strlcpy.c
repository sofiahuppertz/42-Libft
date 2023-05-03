#include <stddef.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t  srclen;
    size_t  copylen;
    int i;

    srclen = ft_strlen(src);
    copylen = src < size ? srclen : size ;

    while (i < copylen && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 

    
    return (srclen);
}