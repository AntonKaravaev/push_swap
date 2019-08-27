/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posoneelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:18:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/25 00:50:34 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_move_from_way0(t_p *p)
{
	int i;

	i = -1;
	while (++i < p->best_ra2)
		ft_ra(p);
	i = -1;
	while (++i < p->best_rrb2)
		ft_rrb(p);
	ft_pa(p);
}

static void	ft_move_from_way1(t_p *p)
{
	int i;

	i = -1;
	while (++i < p->best_rra2)
		ft_rra(p);
	i = -1;
	while (++i < p->best_rb2)
		ft_rb(p);
	ft_pa(p);
}

static void	ft_move_from_way2(t_p *p)
{
	while (p->best_ra2 != 0 && p->best_rb2 != 0)
	{
		ft_rr(p);
		p->best_ra2--;
		p->best_rb2--;
	}
	while (p->best_ra2 != 0)
	{
		ft_ra(p);
		p->best_ra2--;
	}
	while (p->best_rb2 != 0)
	{
		ft_rb(p);
		p->best_rb2--;
	}
	ft_pa(p);
}

static void	ft_move_from_way3(t_p *p)
{
	while (p->best_rra2 != 0 && p->best_rrb2 != 0)
	{
		ft_rrr(p);
		p->best_rra2--;
		p->best_rrb2--;
	}
	while (p->best_rra2 != 0)
	{
		ft_rra(p);
		p->best_rra2--;
	}
	while (p->best_rrb2 != 0)
	{
		ft_rrb(p);
		p->best_rrb2--;
	}
	ft_pa(p);
}

void		ft_pos_one_elem(t_p *p)
{
	if (p->best_way == 0)
		ft_move_from_way0(p);
	else if (p->best_way == 1)
		ft_move_from_way1(p);
	else if (p->best_way == 2)
		ft_move_from_way2(p);
	else if (p->best_way == 3)
		ft_move_from_way3(p);
}
