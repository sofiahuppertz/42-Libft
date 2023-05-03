#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;
    unsigned int    i;

    i = 0;
    if (d > s)
    {
        while (n--)
        {
            d[n] = s[n];
        }
    }
    else
    {
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (d);
}

