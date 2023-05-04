#include <stdlib.h>

char *strdup(const char *s)
{
    void   *string;
    unsigned char   *ch;
    int total_length;
    int i;

    //Get length of the string.
    total_length = ft_strlen(s);
    //Allocate sufficient memory.
    string = (char*)malloc(total_length * sizeof(char));
    //Copy the string byte by byte into allocated memory.
    i = 0;
    ch = (unsigned char *)string;
    while (i < total_length)
    {
        ch[i] = s[i];
        i++;
    }
    //Return pointer to new string.
    return (string);
}