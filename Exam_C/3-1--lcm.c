/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <RTFM@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Напишите функцию, которая принимает два unsigned int в качестве параметров и возвращает вычисленный LCM этих параметров.

LCM (наименьшее общее кратное) из двух ненулевых целых чисел является наименьшим положительным целым числом, делимым на оба целых числа.

LCM можно рассчитать двумя способами:

- Вы можете вычислять все кратные каждого целого числа, пока у вас не будет общего кратного, кроме 0

- Вы можете использовать HCF (наивысший общий коэффициент) этих двух целых чисел и рассчитать следующим образом:


	LCM(x, y) = | x * y | / HCF(x, y)


| х * у | означает «Абсолютное значение произведения х на у».

Если хотя бы одно целое число равно нулю, LCM равно 0.


Ваша функция должна быть прототипирована следующим образом:

  unsigned int    lcm(unsigned int a, unsigned int b);


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	lcm(unsigned int a, unsigned int b)
{
	int		gcd;
	int		old_a;
	int		old_b;

	gcd = 0;
	old_a = a;
	old_b = b;
	while (1)
	{
		if (a == 0)
			break ;
		b %= a;
		if (b == 0)
			break ;
		a %= b;
	}
	gcd = (!b) ? a : b;
	return (gcd ? (old_a / gcd * old_b) : 0);
}
