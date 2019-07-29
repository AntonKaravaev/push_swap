/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/30 01:42:29 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int			main(int argc, char *argv[])
{
	t_p p;

	if (argc > 1)
	{
		ft_parselines(argc, argv, &p);
		ft_checkduplicates(&p);
		ft_createmasb(&p);
	}
	else
		write(1, "Error\n", 6);
	ft_ra(&p);
	ft_ra(&p);
	ft_ra(&p);
	ft_printmassive(&p);
	return (0);
}
