/*
** EPITECH PROJECT, 2017
** File Name : my_put_nbr.c
** File description:
** By Arthur Teisseire
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
	int isneg = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
		isneg = 1;
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_putchar(nb % 10 + '0');
	} else
		my_putchar(nb + '0');
	if (isneg == 1)
		return (-nb);
	return nb;
}
