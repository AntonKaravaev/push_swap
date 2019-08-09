/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:24:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/09 05:45:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_equal(t_p *p, int num, int temp)
{
	int i;

	i = -1;
	while (++i < num + 1)
	{
		if (temp == p->sorted[i])
			return (1);
	}
	return (0);
}

static void		ft_value_of_position(t_p *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->anum)
	{
		j = -1;
		while (++j < p->anum)
		{
			if (p->mas_a[i] == p->sorted[j])
			{
				p->mas_a[i] = j;
				break ;
			}
		}
	}
}

void			ft_sorting(t_p *p)
{
	int i;
	int j;

	i = -1;
	if (!(p->sorted = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
	p->max = p->mas_a[0];
	while (++i < p->anum)
		p->max = (p->max < p->mas_a[i]) ? p->mas_a[i] : p->max;
	i = -1;
	while (++i < p->anum)
	{
		j = -1;
		p->sorted[i] = p->max;
		while (++j < p->anum)
		{
			if (p->sorted[i] > p->mas_a[j] && ft_equal(p, i, p->mas_a[j]) != 1)
				p->sorted[i] = p->mas_a[j];
		}
	}
	p->sorted[i - 1] = p->max;
	ft_value_of_position(p);
	ft_intstrdel(&p->sorted);
}
