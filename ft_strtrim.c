#include <stdlib.h>

int     ft_strlen(char *s);
int     check_start(const char *s1, const char *set, int set_len);
int     check_end(const char *s1, const char *set, int set_len, int s1_len);

char    *ft_strtrim(char const *s1, char const *set)
{
    //Create trimmed string pointer.
    char    *trimmed_string;
    int     set_len;
    int     s1_len;
    int     trimmed_len;
    int     i;

    //Get length of set.
    set_len = ft_strlen((char *)set);
    //Get length of s1.
    s1_len = ft_strlen((char *)s1);
    //Check if set is in the start of s1.
    //Check if set is in the end of s1.
    //Get length of trimmed string.
    trimmed_len = check_start(s1, set, set_len) ? s1_len - set_len : s1_len;
    trimmed_len = check_end(s1, set, set_len, s1_len) ? trimmed_len - set_len : trimmed_len;
    trimmed_len += 1;
    //AlLocate space for trimmed string;
    trimmed_string = (char *)malloc(trimmed_len * sizeof(char));
    //If alocation fails return NULL.
    if (trimmed_string == NULL)
    {
        return (NULL);
    }
    //Iterate s1 according to presence of set in star and copy to trimmed string.
    i = 0;
    if (check_start(s1, set, set_len))
    {
        while(set_len + i < s1_len - set_len)
        {
            trimmed_string[i] = s1[set_len + i - 1];
            i++; 
        }
        if (!check_end(s1, set, set_len, s1_len))
        {
            while(set_len + i < s1_len)
            {
                trimmed_string[i] = s1[set_len + i - 1];
                i++;
            }
        } 
    }
    else
    {
        while(i < s1_len - set_len)
        {
            trimmed_string[i] = s1[i];
            i++;
        }
        if (!check_end(s1, set, set_len, s1_len))
        {
            while(set_len + i < s1_len)
            {
                trimmed_string[i] = s1[i];
                i++;
            }
        }   
    }
    //Return trimmed string.
    return (trimmed_string);
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

//Check if set is in the start of s1.
int     check_start(const char *s1, const char *set, int set_len)
{
    int     i;

    i = 0;
    while (i < set_len)
    {
        if(s1[i] != set[i])
        {
            return(0);
        }
        i++;
    }
    return (1);
}

int     check_end(const char *s1, const char *set, int set_len, int s1_len)
{
    //strncomp with set_lenand from s1[s1_len - set_len].
    int     i;

    i = 0;
    while (s1_len - set_len + i < s1_len)
    {
        if(s1[s1_len - set_len + i] != set[i])
        {
            return (0);
        }
        i++;
    }
    return(1);
}