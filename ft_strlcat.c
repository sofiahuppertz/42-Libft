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

size_t  strlcat(char *dst, const char *src, size_t size)
{
    int srclen;
    int destlen;
    int copylen;
    int i;
    int j;

    i = 0;
    srclen = ft_strlen(src);
    destlen = ft_strlen(dst);
    copylen = size - destlen -1;

   while (dst[i] != '\0')
   {
        i++;
   }
   j = 0;
   while (src[j] != '\0' && j < copylen)
   {
    dst[i + j] = src[j];
    i++;
    j++;
   }
   dst[i] = '\0';

   return (destlen + srclen);
}