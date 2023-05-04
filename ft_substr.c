#include <stdlib.h>


char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    //create substring pointer.
    char    *substring;
    int     i;
    //allocates space of the size length * char.
    substring = (char *)malloc(len * sizeof(char));

    //iterate through the ptr to fill the string, size len or until string[start + i] is nul.
    while (i < len && s[start + i] != '\0' )
    {
        //copy substring.
        substring[i] = s[start + i];
        i++;
    }
    //return substring.
    return (substring);

}

