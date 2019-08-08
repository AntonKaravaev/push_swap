/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prewhirling_sup1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:24:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/08 02:07:18 by crenly-b         ###   ########.fr       */
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
	p->sorted = NULL;
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
}

static int		ft_prefind_optimal_way(t_p *p, int i)
{
	int bot;
	int top;

	bot = i;
	top = p->bnum - i;
	if (bot <= top)
	{
		while (i != 0)
		{
			ft_rb2(p);
			i--;
		}
	}
	else
	{
		while (top != 0)
		{
			ft_rrb2(p);
			top--;
		}
	}
	return (1);
}

void			ft_prefrom_b_to_a(t_p *p)
{
	int i;

	i = -1;
	while (++i < p->bnum)
	{
		if (p->mas_a[p->anum - 1] + 1 == p->mas_b[i]
			|| ((p->mas_a[p->anum - 1] == p->max) && p->mas_b[i] == 0))
		{
			if (ft_prefind_optimal_way(p, i))
				ft_pa2(p);
			return ;
		}
	}
}
