/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirling_sup1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:38:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/08 02:07:06 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_find_optimal_way(t_p *p, int i)
{
	int bot;
	int top;

	bot = i;
	top = p->bnum - i;
	if (bot <= top)
	{
		while (i != 0)
		{
			ft_rb(p);
			i--;
		}
	}
	else
	{
		while (top != 0)
		{
			ft_rrb(p);
			top--;
		}
	}
	return (1);
}

void			ft_from_b_to_a(t_p *p)
{
	int i;

	i = -1;
	while (++i < p->bnum)
	{
		if (p->mas_a[p->anum - 1] + 1 == p->mas_b[i]
			|| ((p->mas_a[p->anum - 1] == p->max) && p->mas_b[i] == 0))
		{
			if (ft_find_optimal_way(p, i))
				ft_pa(p);
			return ;
		}
	}
}
