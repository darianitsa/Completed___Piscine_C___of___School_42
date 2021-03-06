/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:12:14 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putchar(char c)					/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)				/* функция печати строки */
{
	while (*str)
		ft_putchar(*str++);
}


char	*ft_strcat(char *dest, char *src)	/* принимаем адреса строк для Конкатенации - результирующую и исходную */
{
	int	i;									/* Обьявляем целочисленную переменную для счетчика к массиву src */
	int	dest_size;							/* Обьявляем целочисленную переменную для счетчика к массиву dest */

	i = 0;									/* Инициализируем переменную для счетчика нулем чтобы начать с нулевой ячейки массива src */
	dest_size = 0;							/* Инициализируем переменную для счетчика нулем чтобы начать с нулевой ячейки массива dest */
	while (dest[dest_size])					/* Если эта ячейка массива dest не хранит символ конца массива то запускаем цикл */
		dest_size++;						/* Увеличиваем переменную dest_size при каждом найденом символе пока символы не закончатся */
	while (src[i])							/* Если эта ячейка массива src не хранит символ конца массива то запускаем цикл */
	{
		dest[dest_size] = src[i];			/* начинаем в конец строки dest копировать символы из строки src до тех пор пока не дойдем до окнца строки src */
		dest_size++;						/* Увеличиваем счетчик dest_size для перехода к след ячейке масива dest */
		i++;								/* Увеличиваем счетчик i для перехода к след ячейке масива src */
	}
	dest[dest_size] = '\0';					/* добавляем после строки завершающий символ */
	return (dest);							/* Завершаем функцию и возвращаем адресс строки в которую мы добывили символы из др. строки */
}



int 	main(void)
{
	char	r[] = {"muther_facker\n"};		/* создадим исходную строку(массив символов) для теста */
	char	t[20] = {"Hello "};				/* создадим результирующую строку(массив символов) для теста */

	ft_strcat(t, r);						/* отправим в функцию адреса массивов символов для конкатенации */
	ft_putstr(t);							/* напечатаем результирующую строку для проверки */
	return (0);								/* завершаем функцию и возвращаем 0 */
}

