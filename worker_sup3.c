/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_sup3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:14:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/06 17:20:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_w1(t_p *p)
{
	if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
		ft_rr(p);
	else
		ft_ra(p);
}

static void		ft_w2(t_p *p)
{
	if (p->bnum > 1 && p->mas_b[0] < p->mas_b[1])
	{
		ft_ss(p);
		if (p->anum > 2)
			ft_rr(p);
		else
			ft_rb(p);
	}
	else if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
	{
		ft_sa(p);
		if (p->anum > 2)
			ft_rr(p);
		else
			ft_rb(p);
	}
	else
	{
		ft_sa(p);
		if (p->anum > 2)
			ft_ra(p);
	}
}

static void		ft_w3(t_p *p)
{
	if ((p->mas_a[0] == p->mas_a[p->anum - 1] + 1)
		|| (p->mas_a[0] == 0 && p->mas_a[p->anum - 1] == p->max))
	{
		if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
			ft_rr(p);
		else
			ft_ra(p);
	}
	else
		ft_pb(p);
}

void			ft_whirling(t_p *p)
{
	int i;

	i = -1;
	p->connection = 0;
	p->max = p->anum - 1;
	while (++i < 11)
	{
		if (p->bnum > 0)
			ft_from_b_to_a(p);
		if (p->bnum == 0 && ft_cycle_ok(p) == 1)
			break ;
		// if (p->mas_a[0] == 0 || p->mas_a[0] == 2 || p->mas_a[0] == 1)
		// {
		// 	ft_pb(p);
		// }
		if ((p->mas_a[0] == p->mas_a[1] - 1)
			|| (p->mas_a[0] == p->max && p->mas_a[1] == 0))
			ft_w1(p);
		else if (p->mas_a[0] - 1 == p->mas_a[1]
				|| (p->mas_a[0] == 0 && p->mas_a[1] == p->max))
			ft_w2(p);
		else
			ft_w3(p);
	}
	printf("i = %d\n", i);
	printf("p->max = %d\n", p->max);
}
