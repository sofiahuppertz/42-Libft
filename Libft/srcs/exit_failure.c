
#include "../headers/libft.h"

void exit_failure(void)
{
    ft_putstr_fd(stderr, "Fatal error: Out of memory\n", 2);
    exit(EXIT_FAILURE);
}
