/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 - Create a function that displays all different combination of two digits between 00 and 99, listed by ascending order.

 - Создайте функцию, которая отображает все различные комбинации двух цифр от 00 до 99, перечисленные в порядке возрастания.

Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую



Пример вывода:

00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99

*/


/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

void	ft_print_comb2(void)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < 100)
	{
		k = i + 1;
		while (k < 100)
		{
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			ft_putchar(' ');
			ft_putchar(k / 10 + '0');
			ft_putchar(k % 10 + '0');
			if ((i / 10 != 9) || (i % 10 != 8))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			k++;
		}
		i++;
	}
}


/* ************************************************************************** */
/* *********************************_ИЛИ_************************************ */
/* ************************************************************************** */


void	ft_print_comb2(void)
{
	char	table[4] = {0, 0, 0, 1};

	while (!((table[0] == 9) && (table[1] == 9)))
	{
		ft_putchar(table[0] + 48);
		ft_putchar(table[1] + 48);
		ft_putchar(' ');
		ft_putchar(table[2] + 48);
		ft_putchar(table[3] + 48);
		if (!((table[0] == 9) && (table[1] == 8)))
			ft_putchar(',');
		if (!((table[0] == 9) && (table[1] == 8)))
			ft_putchar(' ');
		table[3]++;
		if ((table[3] = table[3] % 10) == 0)
			table[2] = (table[2] + 1);
		if (table[2] == 10)
		{
			table[2] = table[0];
			table[1]++;
			if (( table[1] = table[1] % 10) == 0)
				table[0]++;
			table[3] = table[1] + 1;
		}
	}
}


/* ************************************************************************** */
/* *********************************_ИЛИ_************************************ */
/* ************************************************************************** */


void	ft_makechars(int i)
{
	ft_putchar(i / 10 + 48);
	ft_putchar(i % 10 + 48);
}

void	ft_putthem(int x, int y)
{
	if (x < 10)
	{
		ft_putchar(48);
		ft_putchar(x + 48);
	}
	else
		ft_makechars(x);
	ft_putchar(' ');
	if (y < 10)
	{
		ft_putchar(48);
		ft_putchar(y + 48);
	}
	else
		ft_makechars(y);
	if (!(x + y == 197))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print(int x, int y)
{
	if (x < y)
	{
		ft_putthem(x, y);
	}
}

void	ft_calc_numbers(int x[])
{
	while (x[0] < 100)
	{
		x[1] = 0;
		while (x[1] < 100)
		{
			ft_print(x[0], x[1]);
			x[1]++;
		}
		x[0]++;
	}
}

void	ft_print_comb2(void)
{
	int x[2];

	x[0] = 0;
	x[1] = 1;
	ft_calc_numbers(x);
}



/* ************************************************************************** */
