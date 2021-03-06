/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:04:28 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Создайте рекурсивную функцию, которая возвращает значение степени, примененной к числу.

Ваша функция должна вернуть свой результат менее чем за две секунды.


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * (ft_recursive_power(nb, power - 1)));
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int			ft_recursive_power(int nb, int power)
{
	if (power >= 2)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (nb);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

double ft_recursive_power(int nb, int power)
{
    if (0 == power)
		return 1;
    if (power%2 == 1)
        return (nb * ft_recursive_power(nb, power-1));
    else
        return ft_recursive_power(nb * nb, power / 2);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
		nb = 1;
	if (power < 0)
		nb = 0;
	if (power-- > 1)
		nb = nb * ft_recursive_power(nb, power);
	return (nb);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (!nb || power < 0)
		return (0);
	if (!power)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
