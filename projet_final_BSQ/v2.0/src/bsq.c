/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 15:07:27 by adespond          #+#    #+#             */
/*   Updated: 2015/09/23 18:31:17 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void	bsq(int *argc, char **argv)
{
	t_uns	 i;

	i = 0;
	if (*argc > 1)
		while (++i < *argc)
		{
			if (read_file(argv[i]) == 1)
				write(1, "map error\n", 10);
		}
	else
		read_stdin();
}
