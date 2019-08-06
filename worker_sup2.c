/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_sup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:50:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/06 17:26:09 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_where_is_the_zero(t_p *p)
{
	int i;

	i = -1;
	p->zeropos = -1;
	while (++i < p->anum)
	{
		if (p->mas_a[i] == 0)
		{
			p->zeropos = i;
			return (1);
		}
	}
	return (0);
}

static int		ft_pzeropos0(t_p *p, int i)
{
	while (i < p->anum - 1)
	{
		if (p->mas_a[i] == p->mas_a[i + 1] - 1)
			i++;
		else
			return (0);
	}
	return (1);
}

static int		ft_pzeroposmax(t_p *p, int i)
{
	while (i < p->anum - 1)
	{
		if (p->mas_a[i] == p->mas_a[i + 1] + 1)
			i++;
		else
			return (0);
	}
	return (1);
}

static int		ft_pzeropointhemiddle(t_p *p, int i)
{
	while (i < p->zeropos - 1)
	{
		if (p->mas_a[i] == p->mas_a[i + 1] + 1)
			i++;
		else
			return (0);
	}
	while (i < p->anum - 1)
	{
		if (p->mas_a[i] == p->mas_a[i + 1] - 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int				ft_cycle_ok(t_p *p)
{
	if (ft_where_is_the_zero(p) == 1)
	{
		if (p->zeropos == 0)
		{
			if (ft_pzeropos0(p, 0) == 1)
				return (1);
			else
				return (0);
		}
		else if (p->zeropos == p->anum - 1)
		{
			if (ft_pzeroposmax(p, 0) == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			if (ft_pzeropointhemiddle(p, 0) == 1)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}
