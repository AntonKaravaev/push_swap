/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/11 03:31:20 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_find_zero_pos_and_twist(t_p *p)
{
	int i;

	i = 0;
	while (i < p->anum)
	{
		if (p->mas_a[i] == 0)
			break ;
		i++;
	}
	if (i <= p->anum - i)
	{
		while (p->mas_a[0] != 0)
			ft_ra(p);
	}
	else
	{
		while (p->mas_a[0] != 0)
			ft_rra(p);
	}
}

static void		ft_find_min_and_max(t_p *p)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (p->mas_a[0] == 0 || p->mas_a[0] == p->max)
		{
			ft_ra(p);
			i++;
		}
		else if (p->mas_a[0] > p->p2)
			ft_ra(p);
		else
		{
			ft_pb(p);
			if (p->mas_b[0] <= p->p1 && p->bnum > 1)
			{
				if (p->mas_b[1] <= p->p2 && p->mas_b[1] > p->p1 && p->bnum > 1)
					ft_rb(p);
			}
		}
	}
}

static void		ft_create_circle(t_p *p)
{
	while (p->anum != 3)
	{
		if (p->mas_a[0] == 0 || p->mas_a[0] == p->max)
			ft_ra(p);
		else
			ft_pb(p);
	}
	if (p->mas_a[0] == p->max && p->mas_a[1] != 0)
		ft_sa(p);
	else if (p->mas_a[0] == 0 && p->mas_a[1] == p->max)
		ft_sa(p);
	else if (p->mas_a[0] != 0 && p->mas_a[0] != p->max && p->mas_a[1] == 0)
		ft_sa(p);
}

void			ft_whirling(t_p *p)
{
	p->p1 = p->anum / 3;
	p->p2 = p->anum / 3 * 2;
	ft_find_min_and_max(p);
	ft_create_circle(p);
	while (p->bnum != 0)
	{
		p->best_ra2 = 0;
		p->best_rra2 = 0;
		p->best_rb2 = 0;
		p->best_rrb2 = 0;
		p->best_number = 0;
		p->elem_to_move = 0;
		ft_from_b_to_a(p);
		ft_pos_one_elem(p);
	}
}

void			ft_worker(t_p *p)
{
	ft_sorting(p);
	ft_whirling(p);
	ft_find_zero_pos_and_twist(p);
}
