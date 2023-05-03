#include <stdio.h>

//stdio.h to use size_t;
//Type int was before function prototypes existed; 
//https://stackoverflow.com/questions/5919735/why-does-memset-take-an-int-instead-of-a-char

void *ft_memset(void *s, int c, size_t n)
{
    unsigned int i;
    char *str;
    
    *str = (char *)s;
    i = 0;
    while (i < n)
    {
        str[i] = (unsigned char)c;
        i++;
    }
    return(str);
}

