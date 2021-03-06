/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


	• Напишите функциюft_rot42, которая будет возвращать строку, переданную в 
	качестве параметра, путем поворота необходимых символов на 42.


	• Эта функция будет прототипирована следующим образом:

	char	*ft_rot42(char *str)



   **************************************************************************

** P.S функия которую нас просят сделать должна взять строку и каждую букву в 
** ней заменить на ту, которая окажется на 42 месте после текущей. Это что то
** вроде шифра цезаря только со мещением каждой буквы на 42 позиции вперед.


** Вместо того, чтобы вращать 13, как это делает ROT13 (поскольку в латинском 
** алфавите 26 символов), мы делаем вращение на 42, чтобы сделать ROT42. Таким 
** образом, мы вычитаем 26 (все буквы в алфавите) в 42, чтобы сделать фактическое 
** вращение, которое составляет 16 (первое значение от начальной точки, которая 
** является A). Теперь нам нужно найти число, которое завершает алфавит, из 16, 
** что равно 10 (26 - 16 = 10). Таким образом, мы можем успешно вращаться. : D 
** Эта ссылка мне очень помогла: 
** http://stackoverflow.com/questions/13520067/about-rot13-implementation
** ----------------------------------------------------------------------
** ----------------------------------------------------------------------
** ----------------------------------------------------------------------
** Instead of rotating 13, as ROT13 does (because there is 26 characters
** in the latin alphabet), we do a 42 rotation to make ROT42. This way, we
** substract 26 (all the letters in the alphabet) to 42, to make the actual
** rotation, which is 16 (the first value, from the starting point, which is
** A). Now, we need to find the number that completes the alphabet, from 16,
** which is 10 (26 - 16 = 10). This way, we can rotate successfully. :D
** This link helped me a lot:
** http://stackoverflow.com/questions/13520067/about-rot13-implementation
** ----------------------------------------------------------------------
** ----------------------------------------------------------------------
** ----------------------------------------------------------------------
*  Алфавит для примера:
*
*           1   2   3   4   5   6   7   8   9  10  11  12  13
*           a   b   c   d   e   f   g   h   i   j   k   l   m

*          14  15  16  17  18  19  20  21  22  23  24  25  26
*           n   o   p   q   r   s   t   u   v   w   x   y   z	


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


char	*ft_rot42(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr >= 'A' && *ptr <= 'Z')
		{
			*ptr = *ptr - 'A';
			*ptr = ((*ptr + 42) % 26);
			*ptr = *ptr + 'A';
		}
		else if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = *ptr - 'a';
			*ptr = ((*ptr + 42) % 26);
			*ptr = *ptr + 'a';
		}
		ptr++;
	}
	return (str);
}

/*			ИЛИ_ТАК/OR_THAT
char	*ft_rot42(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'a';
			str[i] = ((str[i] + 42) % 26);
			str[i] = str[i] + 'a';
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a';
			str[i] = ((str[i] + 42) % 26);
			str[i] = str[i] + 'a';
		}
		i++;
	}
	return (str);
}
*/

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


char	rotate_maj(char c)
{
	c = c - 'A';
	c = ((c + 42) % 26);
	c = c + 'A';
	return (c);
}

char	rotate_min(char c)
{
	c = c - 'a';
	c = ((c + 42) % 26);
	c = c + 'a';
	return (c);
}

char	rotate(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (rotate_maj(c));
	else if (c >= 'a' && c <= 'z')
		return (rotate_min(c));
	else
		return (c);
}

char	*ft_rot42(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = rotate(str[i]);
		i++;
	}
	return (str);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if ((int)str[i] >= 'K')
				str[i] -= 10;
			else
				str[i] += 16;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if ((int)str[i] >= 'k')
				str[i] -= 10;
			else
				str[i] += 16;
		}
		i++;
	}
	return (str);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



char	*ft_rot42(char *str)
{
	int		i;
	int		y;
	char	c;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (y < 16)
		{
			c = str[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (str[i] == 'z')
					str[i] = 'a';
				else if (str[i] == 'Z')
					str[i] = 'A';
				else
					str[i]++;
			}
			y++;
		}
		i++;
	}
	return (str);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'J') ||	(str[i] >= 'a' && str[i] <= 'j'))
			str[i] += 16;
		else if ((str[i] >= 'K' && str[i] <= 'Z') || (str[i] >= 'k' && str[i] <= 'z'))
			str[i] -= 10;
		i++;
	}
	return (str);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
