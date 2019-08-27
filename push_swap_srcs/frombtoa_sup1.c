/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frombtoa_sup1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 03:29:50 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/25 00:50:15 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ft_optimization_way2(t_p *p)
{
	if (p->count_ra2 < p->count_rb2)
		return (p->count_rb2);
	else if ((p->count_ra2 >= p->count_rb2))
		return (p->count_ra2);
	return (0);
}

static int			ft_optimization_way3(t_p *p)
{
	if (p->count_rra2 < p->count_rrb2)
		return (p->count_rrb2);
	else if ((p->count_rra2 >= p->count_rrb2))
		return (p->count_rra2);
	return (0);
}

void				ft_best_decision(t_p *p)
{
	int way[4];
	int i;

	i = -1;
	way[0] = 0;
	way[1] = 0;
	way[2] = 0;
	way[3] = 0;
	way[0] = p->count_ra2 + p->count_rrb2;
	way[1] = p->count_rra2 + p->count_rb2;
	way[2] = ft_optimization_way2(p);
	way[3] = ft_optimization_way3(p);
	p->best_score = way[0];
	while (++i < 4)
	{
		if (way[i] < p->best_score)
		{
			p->way = i;
			p->best_score = way[i];
		}
	}
}
