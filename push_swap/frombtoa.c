/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frombtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:30:50 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/11 03:34:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_mas_a2(t_p *p)
{
	int i;

	i = -1;
	if (!(p->mas_a2 = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
	while (++i < p->anum)
		p->mas_a2[i] = p->mas_a[i];
}

void			ft_rebuf_mas_a(t_p *p)
{
	int i;

	i = -1;
	ft_intstrdel(&p->mas_a);
	if (!(p->mas_a = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
	while (++i < p->anum)
		p->mas_a[i] = p->mas_a2[i];
}

void			ft_up_or_down_in_buf_b(t_p *p, int i)
{
	int temp;

	temp = i;
	while (i > 0)
	{
		i--;
		p->count_rb2++;
	}
	i = temp;
	while (i < p->bnum)
	{
		i++;
		p->count_rrb2++;
	}
}

void			ft_matched(t_p *p, int number)
{
	ft_mas_a2(p);
	while ((number < p->mas_a[0] && number > p->mas_a[p->anum - 1]) != 1)
	{
		p->count_ra2++;
		ft_ra2(p);
	}
	ft_rebuf_mas_a(p);
	while ((number < p->mas_a[0] && number > p->mas_a[p->anum - 1]) != 1)
	{
		p->count_rra2++;
		ft_rra2(p);
	}
	ft_rebuf_mas_a(p);
	ft_intstrdel(&p->mas_a2);
}

void			ft_from_b_to_a(t_p *p)
{
	int i;

	i = -1;
	p->best_number = p->max * 2;
	while (++i < p->bnum)
	{
		p->count_ra2 = 0;
		p->count_rra2 = 0;
		p->count_rb2 = 0;
		p->count_rrb2 = 0;
		p->way = 0;
		ft_up_or_down_in_buf_b(p, i);
		ft_matched(p, p->mas_b[i]);
		ft_best_decision(p);
		if (p->best_number > p->best_score)
		{
			p->best_number = p->best_score;
			p->best_way = p->way;
			p->elem_to_move = i;
			p->best_ra2 = p->count_ra2;
			p->best_rra2 = p->count_rra2;
			p->best_rb2 = p->count_rb2;
			p->best_rrb2 = p->count_rrb2;
		}
	}
}
