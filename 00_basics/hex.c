#include <unistd.h>

void ft_write_number(int number)
{
    if (number > 15)
        ft_write_number(number / 16);
    write(1, &"0123456789ABCDEF"[number % 16], 1);
}

int main(void)
{
        ft_write_number(32);
        write(1, "\n", 1);
}