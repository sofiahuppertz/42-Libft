#include <stdlib.h>

int     ft_strlen(char *s);

char    *ft_strjoin(char const *s1, char const *s2)
{
    //Create new string.
    char    *newstring;
    int     i;
    int     j;
    int     length;
    //Get length of s1 and s2.
    length = ft_strlen(s1) + ft_strlen(s2);
    //Allocate space for sum of s1 and s2 + nul terminator.
    newstring = (char *)malloc(length * sizeof(char));
    if (newstring == NULL)
    {
        //If allocation doesn't work return NULL.
        return (NULL);
    }
    //Iterate new string and cpy s1 then s2.
    i = 0;
    j = 0;
    while(i < length)
    {
        while(s1[i] != '\0')
        {
            newstring[i] = s1[i];
            i++;
        }
        while(s2[j] != '0')
        {
            newstring[i] = s2[j];
            j++;
            i++;
        }
        newstring[i] = '\0';
    }
    //Return new string.
    return(newstring);
}

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}
