/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:09:41 by evgenkarlson     ###   ########.fr       */
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


void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)		/* функция печати строки */
{
	while (*str)
		ft_putchar(*str++);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)/* Принимаем адрес строки в которую будем копировать символы, 
														   * адрес из которой будем копировать символы и количество символов */
{
	unsigned int i;							/* Обьявляем счетчик таким же типом что и 'n' - "unsigned int" */

	i = 0;									/* Инициализируем счетчик нулем чтобы начать копирование из строки в строку с нулевой ячейки */	
	while ((src[i] != '\0') && (i < n))		/* Пока ячейка первой строки не равна '\0' и пока счетчик i не дошел до 'n' работает цикл копирования */
	{
		dest[i] = src[i];					/* Копируем ячейку src в ячейку dest */
		i++;								/* Переходим к след ячейке */
	}
	while ((dest[i] != '\0') && (i < n))	/* Пока ячейка второй строки не равна '\0' и пока счетчик i не дошел до 'n' работает цикл заполнения 
											 * оставшейся части второй строки символом завершающего нуля '\0' */
	{
		dest[i] = '\0';						/* Сохраняем в ячейку символом завершающего нуля '\0' */
		i++;								/* Переходим к след ячейке */
	}
	return (dest);							/* Завершаем функцию и возвращаем адрес строки */
}


int 	main(void)
{
	char	r[] = {"Fuck.Fuck.Fuck.Fuck"};	/* Создадим строку(массив символов) которую будем копировать */
	char	t[20];							/* Создадим пустую строку(массив символо) длинной в 20 ячеек для копирования в нее строки r[] */
	char	*p;								/* Обьявим указатель для хранения адреса строки(массива символов), который будет возвращен в нее 
											 * функцией после копирования */


	p = ft_strncpy(t, r, 20);		/* Вызываем функцию отправляя в нее адреса итоговой строки, исходной строки, и количество копируемых символов */

	ft_putstr(p);					/* Напечатаем строку(массив символов), адресс которой мы получили из функции и сохранили в указателе */
	return (0);						/* Возвращаем 0 и завершаем программу */
}

