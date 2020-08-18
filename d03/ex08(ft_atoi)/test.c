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

void	ft_putnbr(int nb)     			 /* Функция вывода числа */
{
	int	temp;						/* создадим переменню для временного хранения данных в нее будем сохранять переменную nb */
	int	size;						/* создадим переменню для хранения размера числа*/

	size = 1;						/* Установим ей начальный размер */

	if (nb < 0)						/* Проверяем яляется полученное нами число в nb отрицательным если число отрицательное то в начале выведем этот '-' символ. */	
	{								/* а содержимое переменной nb делаем положительным с помощью хитрости( nb = -nb) помня из математики что минус на минус дает плюс */
		ft_putchar('-');
		nb = -nb;					
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;						/* сохраним в переменную temp наше число nb для вычисления размера этого числа */

	while ((temp /= 10) > 0)		/* Вычисляем размер числа c помощью накопления количества умноженых десяток друг на друга*/ 
		size *= 10;					/* Если результ деления нашего числа в temp на 10 больше нуля то увеличиваем переменную size умножив ее содержимое на 10 */

									/* НУЖО ПОМНИТЬ что при делении целого числа на целое результат сохраняемый в переменной типа int будет без плавающей точки. 
									   она автоматически отбрасывается */ /* ПРимер: делим 4  на 10  в итоге результат будет 0.4 а вот сохраниться в переменной 
									   типа int только 0 по тому что все после точки отбрасывается и не записывается в целочисленную переменную. */

	temp = nb;						/* восстановим расстерзаноеделением число в переменную temp оно нам снова понадобится 
									для того чтобы отделить цифры нужного нам числа и напечатать по отдельности */

	while (size)					/* проверяем длинну числа если длинна еще не равна нулю (в результате уменьшения на 10 в цикле) то продолжаем работу цикла */
	{
		ft_putchar((char)((temp / size)) + 48);			/* делим число на размер, который у нас получился */   /* тут тоже хитрость */  
									/* допустим размер полученогонами числа 345 получисля равным 100 */ 
									/* деля 345 на 100  мы получим 3.45*/ /* 0.45 отбрасывается по тому что идет приведение к целому числу */ /* и остаеться 3 */
									/* Так вот мы и отделяем 3 от 45 и уже можем ее напечатать тройку прибавив к ней 48, чтоб полуить код символа '3' */

		temp %= size;				/* Здесь с помощь деления числа temp (в примере у нас это 345) по модулю на size (в примере у нас это 100) мы получим 
									оставшуюся часть без первого символа temp ( т.е у нас получится 45. Тройка канула в лету. Так мы ее отбрасываем чтоб потом,
									на новой итерации цикла напечатать 4 и 5 и т.д по мере отделения и печати чисел,  и помере того как size уменьшается */
									
		size /= 10;					/* после то как отделили 3 от 45 в числе 345 и после того как оставили себе только 45 для дальнейшего отделения. число 100 нам больше не нужно.
									Так что делим size на 10 чтобы в след итерации число 45 уже делилось на 10 отдавая 4 на печать, и еще 45 делилось по модулю на 10 сохраняя 5 
									на следующую итерацию, потом снова уменьшение size на 10 (чтобы можно было работать с temp, которое теперь уже хранит 5). 
									Теперь 5 делм на 1 получаем пять отдаем его на печать, 5 деленное по модулю на 1 сохраняет в переменную 0 но это нам уже не нужно.
									Потому что дальше size делится на 10 снова и размер size становится равным нулю. А при след итерации цикл будет проверять размер size 
									и если он равен 0 то цикл завершается */
									/* И жили они долго и счастливо, конец */
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


/* проверим не лежат ли в этой ячейке массива ненужные символы если они там лежат то пропустим их и перейдем к след позиции */
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;

/* проверим лежит ли в след ячейке массива знака числа, символ'-'  если он там то в переменной negativ указываем то что это число 
 отрицательное и переходим к след позиции*/
	if (str[i] == '-')
		negativ = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;

/* Наконец дойдя до места в массиве где начинается число мы можем его вывести его от туда и сохранить в целочисленную переменную number */
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + ((int)str[i] - '0');/* умножая number на 10 мы освобождаем место для след цифры и прибавляем число, 
													  * которое мы вытащили из строки. Оно попадет туда где от умножения на 10 появился 0*/
		i++;										 /* и переходим к след позиции*/
	}

/* Дальше перед тем как вернуть число которе мы добыли из строки нужно установить для него тот знак который мы нашли */
	if (negativ == 1)		/* Проверяем, узнали ли мы что число отрицательное */
		return (-number);	/* если число трицательное добавим к нему минус */
	else
		return (number);	/* если чило положительное возвращаем как есть */
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
