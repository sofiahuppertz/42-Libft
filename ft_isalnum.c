int ft_isalnum(int c)
{
    if ((c > 47 && c < 58) || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return (1);
    }
    return (0);
}