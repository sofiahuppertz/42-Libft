#include <stddef.h>

int     ft_strlen(char *str);
int     ft_strncmp(const char *s1, const char *s2, int n);

char    *ft_strnstr(const char *big, const char *little, size_t n)
{
    int     i;
    int    little_len;

    i = 0;
    //Get length of little.
    little_len = ft_strlen(little);
    //If little is an empty string return big.
    if (little_len == 0)
            return (big);

    //Iterate through Big until there are to few characters left to find little.
    while (i <= n - little_len)
    {
        //If current iteration is equal to little[0] compare strings for the length of little
        if (big[i] == little[0])
        {
            //If little appears return pointer to first ocurrence of little.
            if (!ft_strncmp(&big[i], little, little_len))
            {
                return(&big[i]);
            }
        }
        
        //Increment.
        i++;
    }
    
    //If little doesn't occur in big, NULL is returned.
    return NULL;
}
/*








*/
int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int     ft_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}
