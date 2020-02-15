/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_put_Arr_int(int *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(str[i]);
		if(i < n - 1)
		{
			ft_putchar(' ');
		}
		if(i == n - 1)
			ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)/* Принимаем адрес массива чисел и его размер*/
{
	int i;								/* обьявляем переменную для счета количества проверенных ячеек */
	int j;								/* обьявляем переменную для вычисления позиции ячейки массива от начала к концу */
	int temp;							/* обьявляем переменную для временного хранения числа */

	i = 0;								/* Инициализируем перменную нулем чтобы потом отталкиваясь от этой пременной мы знали
										 * до какой ячейки массива нам идти на новой итерации, если условия верны */

	while (i < size - 1)				/* Проверяем все ли ячейки мы проверили */ /* если да то i должна была дойти до "size - 1" */
	{
		j = 0;							/* Инициализируем перменную чтобы начать просмотр массива с 0 позиции */
		while (j < size - i - 1)		/* проверяем достигли ли мы конца массива при проверке.
										 * если да то j должна была дойти до нового конца массива 
										 * вычисляемого прикаждой новой итерерации - "size - i - 1" */
		{
			if (tab[j] > tab[j + 1])	/* если число в ячейкке массива меньше чем число в следующей ячейке
										 * то меняем их местами */
			{
				temp = tab[j];			/* сохраняем символ во временной переменной */
				tab[j] = tab[j + 1];	/* теперь запихиваем в str[j] значение str[j + 1] */
				tab[j + 1] = temp;		/* теперь в str[j + 1] запихиваем значение из временной переменной */
			}
			j++;						/* Идем к след позиции */
		}
		i++;							/* Увеличиваем число, которое укорачиват путь(size - i - 1) по которому
										 * мы идем сравнивая числа в массиве. Это нужно для того что бы сэкономить
										 *  время на том что бы не проверять ячейку массива в  которую мы уже 
										 * положили наибольше число которое нашли во всем массиве. Теперь мы идем 
										 * снова по всему массиву с самого начала но уже до нового конца массива 
										 * в поисках самого большого числа чтобы поместить его в новый конец
										 * (перед ячейкой в которую на прошлой терации мы положили самое большое число) */
	}
}



int 	main(void)
{
	int i[] = {5,4,3,2,1,60,43,12};		/* создаем массив чисел который мы будем сортировать */

	ft_sort_integer_table(i, 8);		/* сортируем массив чисел */

	ft_put_Arr_int(i,8);				/* Проверим получилось ли отсортировать массив. Напечатаем этот массив чисел */
	return 0;
}
