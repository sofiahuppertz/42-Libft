#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

void   *ft_calloc(size_t elements, size_t size)
{
    void    *ptr;
    unsigned char   *byte_ptr;
    int     total_size;
    int     i;

    //If any of the arguments is zero return NULL.
    //If overflow return NULL.
    if (( elements > 0 && SIZE_MAX / elements < size) || elements <= 0 || size <= 0)
    {
        return (NULL);
    }
    //Allocate memory with malloc;
    total_size = size * elements;
    ptr = malloc(total_size);
    //The memory is set to zero.
    byte_ptr = (unsigned char *)ptr;
    i = 0;
    if (ptr != NULL)
    {
        while (i < total_size)
        {
            byte_ptr[i] = 0;
            i++;
        }
    }
    return (ptr);
}


