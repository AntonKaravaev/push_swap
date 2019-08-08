/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:30:50 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/08 15:51:36 by crenly-b         ###   ########.fr       */
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

void			ft_bad_is_in_stack2(t_p *p)
{
	int i;

	i = -1;
	while (++i < p->bad_numbers)
	{
		if (p->mas_a[0] == p->bad_buf[i])
		{
			ft_pb(p);
			return ;
		}
	}
}

int				ft_be_in_stack2(t_p *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->bnum)
	{
		if (p->mas_a[p->anum - 1] + 1 == p->mas_b[i]
			|| ((p->mas_a[p->anum - 1] == p->max) && p->mas_b[i] == 0))
		{
			j = -1;
			while (++j < p->bad_numbers)
			{
				if (p->mas_b[i] == p->bad_buf[j])
					return (0);
			}
			return (1);
		}
	}
	return (1);
}

void			ft_whirling_2(t_p *p)
{
	int i;

	i = -1;
	printf("ft_whirling_2! p->bnum = %d\n", p->bnum);
	p->cycle_ok = 0;
	while (++i < p->max + 2)
	{
		if (p->bad_numbers > 0)
			ft_bad_is_in_stack2(p);
		if (p->bnum > 0 && ft_be_in_stack2(p) == 1)
			ft_from_b_to_a(p);
		if (p->bnum == 0 && ft_cycle_ok(p) == 1)
		{
			p->cycle_ok = 1;
			break ;
		}
		if ((p->mas_a[0] == p->mas_a[1] - 1)
			|| (p->mas_a[0] == p->max && p->mas_a[1] == 0))
			ft_w1(p);
		else if (p->mas_a[0] - 1 == p->mas_a[1]
				|| (p->mas_a[0] == 0 && p->mas_a[1] == p->max))
			ft_w2(p);
		else
			ft_w3(p);
	}
}

void			ft_whirling(t_p *p)
{
	p->cycle_ok = 0;
	while (1)
	{
		if (p->bnum > 0)
			ft_from_b_to_a(p);
		if (p->bnum == 0 && ft_cycle_ok(p) == 1)
		{
			p->cycle_ok = 1;
			break ;
		}
		if ((p->mas_a[0] == p->mas_a[1] - 1)
			|| (p->mas_a[0] == p->max && p->mas_a[1] == 0))
			ft_w1(p);
		else if (p->mas_a[0] - 1 == p->mas_a[1]
				|| (p->mas_a[0] == 0 && p->mas_a[1] == p->max))
			ft_w2(p);
		else
			ft_w3(p);
	}
}
