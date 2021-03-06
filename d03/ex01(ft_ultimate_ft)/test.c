/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 18:29:56 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)           /* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)            /* Функция вывода числа */
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

/*  Эта функция принимает адрес указателя на указатель на указатель на указатель на указатель
**  на указатель на указатель на указатель на указатель на указатель и меняет содержимое на своё */ 

/*  P.S Просто е*нутся можно */

/*  Чтоб это затестить и показать что оно работает я создам кучу указателей на указателлей и т.д.,
**  которые будут указывать на адреса следующего указателя чтоб в конечном счете один из них указывал на адресс переменной. 
**  Вот её то значение мы и поменяем прйдя через тучу указателей(ссылок с адресами). */


void	ft_ultimate_ft(int *********nbr)    /* СЮДА(в указатель nbr(он обьявлен в скобках)) ПРИНИМАЕТСЯ И ЗАПИСЫВАЕТСЯ АДРЕСС УКАЗАТЕЛЯ НА УКАЗАТЕЛЬ и тд. */
{
	*********nbr = 42;                      /* с помощью операции разыменовывания(*********nbr) меняем данные(*********nbr = 42), которые хранятся по адресу который мы получили */
}


int		main(void)
{
	int		*********i;     /* Тут обьявляем кучу указателей которые могут хранить только адреса указателей(это можно заметить по количеству звездочек,
                            ** если их больше одной то это указатель к на указатель) и сохраним в них последовательно адреса друг друга */
	int		********q;		
	int		*******w;
	int		******e;
	int		*****r;
	int		****t;
	int		***y;
	int		**u;
	int 	*Point;         /* Тут обьявляем указатель который будет хранить адресс на переменную num */
	int 	num;            /* Тут обьявляем переменную которая будет хранить число 21, которое мы хотим поменять */

                            /* А теперь инициализируем все указатели */	
	i = &q;                 /* Запишем в указатель как бы "старшего ранга"(где количество звездочек больше) адрес указателя "младшего ранга"(количество звездочек меньше) */
	q = &w;
	w = &e;
	e = &r;
	r = &t;
	t = &y;
	y = &u;
	u = &Point;
	Point = &num;

	num = 21;                /*Запишем туда число 21 */

	ft_ultimate_ft(i);      /* Вызываем функцию и отправляем этот указатель на указатель и тд. в аргументы функции.
                            ** Эта функция должна принять адрес этого указателя на указатель и тд. и перейдя по нему поменять данные с 21 на 42,
                            ** которые хранятся в переменной */

	ft_putnbr(num);         /* А с помощью этой функции выведем содержимое переменной i. Нам нужно поверить изменилось ли число с 21 на 42 */

	return (0);
}


