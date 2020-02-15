/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
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


/* Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */


#include <unistd.h>

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)     		 /* Функция вывода числа */
{
	int		temp;
	int		size;

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
		ft_putchar((char)(temp / size) + '0');
		temp %= size;
		size /= 10;
	}
}
/* #######################################################################*/

/* Эта функция меняет местами значения двух целых чисел, адреса которых вводятся в качестве параметров. */


void	ft_swap(int *a, int *b)		/* СЮДА(в указатель a и указатель b(они обьявлены в скобках)) ПРИНИМАЕТСЯ И ЗАПИСЫВАЕТСЯ АДРЕСС ОТПРАВЛЯЕМЫХ ПЕРЕМЕННЫХ, СОДЕРЖИМОЕ КОТОРЫХ МЫ ХОТИМ ПОМЕНЯТЬ МЕСТАМИ */
{
	int	temp;						/* создадим переменню для временного хранения данных которые мы меняем местами */

	temp = *a;						/* с помощью операции разыменовывания(*a) достаем из адреса который хранит указатель 'a' данные и сохраняем их в temp */
	*a = *b;						/* с помощью операции разыменовывания(*b) достаем из адреса который хранит указатель 'b' данные и сохраняем их в ячейку адресс, которой хранит указатель 'a' с помощью операции разыменовывания(*a) */
	*b = temp;						/* достаем из переменной temp данные и сохраняем их в ячейку адресс которой хранит указатель 'b' с помощью операции разыменовывания(*b) */
}




int		main(void)
{
	int		i;			/* обьявляем мпеременные типа инт, котрые будут хранить число */
	int		t;

	i = 21;				/* Запишем туда число 21 */
	t = 42;				/* Запишем туда число 42 */
	
	/* Сейчас до смены местами чисел консоль должна вывести "21 42" и перейти на сл. строку */
	ft_putnbr(i);			/* печатаем число */
	ft_putchar(' ');		/* Печатаем симпол ' ' */
	ft_putnbr(t);			/* печатаем число */
	ft_putchar('\n');		/* печатаем символ переноса строки '\n' */


	ft_swap(&i, &t);		/* Вызываем функцию и отправляем адреса переменных, содержимое хотим поменять местами, в аргументы функции.
							Эта функция должна принять адреса переменных и поменять их местами */


	/* А сейчас числа должны были поменятся и консоль должна вывести "42 21" и перейти на сл. строку */ /* Если это произошло значит все прошло успешно и функция Работает */
	ft_putnbr(i);			/* печатаем число */
	ft_putchar(' ');		/* Печатаем симпол ' ' */
	ft_putnbr(t);			/* печатаем число */
	ft_putchar('\n');		/* печатаем символ переноса строки '\n' */

	return (0);
}


