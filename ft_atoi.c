int ft_atoi(const char *n)
{
    int     count;
    int     sign;
    int     num;

    count = 0;
    // check white spaces.
    while ((*n >= 9 && *n <= 13) || *n == 32 )
        n++;
    //check for + and -.
    while (*n == '+' || *n == '-')
    {
        if(*n == '-')
        {
            count++;
        }
        n++;
    }
    //check sign.
    sign = 1;
    if (count % 2 != 0)
    {
        sign *= -1;
    }
    //transform number into int type. :)
    num = 0;
    while (*n >= 48 && *n <= 57 )
    {
        num = num * 10 + (*n - '0');
        n++;
    }
    //fix sign.
    num *= sign;
    return (num);
}

