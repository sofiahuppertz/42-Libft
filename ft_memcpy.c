#include <stddef.h>

//stddef.h to use size_t;
void    *memcpy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    char *s = (char *)src;
    int i;

    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (d);
}