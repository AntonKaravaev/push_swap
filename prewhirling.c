/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prewhirling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:14:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/08 02:44:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_prew1(t_p *p)
{
	if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
		ft_rr2(p);
	else
		ft_ra2(p);
}

static void		ft_prew2(t_p *p)
{
	if (p->bnum > 1 && p->mas_b[0] < p->mas_b[1])
	{
		ft_ss2(p);
		if (p->anum > 2)
			ft_rr2(p);
		else
			ft_rb2(p);
	}
	else if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
	{
		ft_sa2(p);
		if (p->anum > 2)
			ft_rr2(p);
		else
			ft_rb2(p);
	}
	else
	{
		ft_sa2(p);
		if (p->anum > 2)
			ft_ra2(p);
	}
}

static void		ft_prew3(t_p *p)
{
	if ((p->mas_a[0] == p->mas_a[p->anum - 1] + 1)
		|| (p->mas_a[0] == 0 && p->mas_a[p->anum - 1] == p->max))
	{
		if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
			ft_rr2(p);
		else
			ft_ra2(p);
	}
	else
		ft_pb2(p);
}

void			ft_mas_a2_create(t_p *p)
{
	int i;

	i = 0;
	p->mas_a2 = NULL;
	if (!(p->mas_a2 = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
	while (i < p->anum)
	{
		p->mas_a2[i] = p->mas_a[i];
		i++;
	}
	p->anum2 = p->anum;
}

void			ft_prewhirling(t_p *p)
{
	int i;

	i = -1;
	p->max = p->anum - 1;
	p->cycle_ok = 0;
	ft_mas_a2_create(p);
	while (++i < p->max + 2)
	{
		if (p->bnum > 0)
			ft_prefrom_b_to_a(p);
		if (p->bnum == 0 && ft_cycle_ok(p) == 1)
		{
			p->cycle_ok = 1;
			break ;
		}
		if ((p->mas_a[0] == p->mas_a[1] - 1)
			|| (p->mas_a[0] == p->max && p->mas_a[1] == 0))
			ft_prew1(p);
		else if (p->mas_a[0] - 1 == p->mas_a[1]
				|| (p->mas_a[0] == 0 && p->mas_a[1] == p->max))
			ft_prew2(p);
		else
			ft_prew3(p);
	}
}
