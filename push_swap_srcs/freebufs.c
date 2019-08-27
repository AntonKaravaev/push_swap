/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freebufs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:43 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/25 00:50:10 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_intstrdel(int **as)
{
	if (as)
	{
		if (*as != NULL)
		{
			free(*as);
			*as = NULL;
		}
	}
}

void		ft_freebufs(t_p *p)
{
	ft_intstrdel(&p->mas_a);
	ft_intstrdel(&p->mas_b);
}

void		ft_error(void)
{
	write(1, "Error\n", 6);
	exit(-1);
}
