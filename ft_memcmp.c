#include <stddef.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    unsigned char *s;     
    unsigned char *d;
    int result;

    s = (unsigned char *)s1;
    d = (unsigned char *)s2;
    i = 0;

    while (i < n)
    {
        if (&s[i] != &d[i])
        {
            result = (unsigned char *)&s[i] - (unsigned char *)&d[i];
            return (result);
        }
        i++;
    }
    return (0);
}
