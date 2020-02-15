/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
//*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
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

int		ft_atoi(char *str)	/* Принимаем адрес массива символов */
{
	int	i;					/* обьявляем переменную для вычисления позиции ячейки массива от начала к концу */
	int	negativ;			/* обьявляем переменную для хранения информации от знаке числа */
	int	number;				/* обьявляем переменную для хранения самого числа полученного из строки */

	i = 0;					/* Инициализируем перменную чтобы начать просмотр массива с 0 позиции */
	negativ = 0;			/* Инициализируем перменную нулем предположив что число положителное */
	number = 0;				/* Инициализируем перменную нулем для прибавления в нее добытого числа*/

	/* проверим не лежат ли в этой ячейке массива ненужные символы если они там лежат то пропустим их
	 *  и перейдем к след позиции */
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	/* проверим лежит ли в след ячейке массива знака числа, символ'-' 
	 * если он там то в переменной negativ указываем то что это число 
	 * отрицательное и переходим к след позиции*/
	if (str[i] == '-')
		negativ = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;

	/* Наконец дойдя до места в массиве где начинается число мы можем его вывести его от туда
	 * и сохранить в целочисленную переменную number */
	/* ВОТ ТАК */
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;					/* умножая на 10 мы освобождаем место для след цифры */
		number += ((int)str[i] - 48);	/* туда где появился 0 прибавляем число которое мы вытащили из строки */
		i++;							/* и переходим к след позиции*/
	}

	/* Дальше перед тем как вернуть число которе мы добыли из строки
	 * нужно установить для него тот знак который мы нашли */
	if (negativ == 1)					/* Проверяем, узнали ли мы что число отрицательное */
		return (-number);				/* если число трицательное добавим к нему минус */
	else
		return (number);				/* если чило положительное возвращаем как есть */
}




int 	main(void)
{
	int		i;					/* обьявляем переменную которая будет хранить добытое нами число */
	char	n[] = {"54321"};	/* создаем массив символов из которого мы будем получать число 54321 */

	i = ft_atoi(n);				/* инициализируем переменную - мы вызываем функцию получения числа из строки 
								 * отдавая ей в аргументы адресс масива символов(строки). Функция получит из строки
								 * число и вернет его нам в переменную i */
	ft_putnbr(i);				/* Проверим получилось ли. Напечатаем это число */
	return (0);
}
