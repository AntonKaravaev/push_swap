/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:30:50 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/09 08:31:21 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_poin1_point2(t_p *p)
{
	p->p1 = p->anum / 3;
	p->p2 = p->anum / 3 * 2;
	printf("p->p1 = %d\n", p->p1);
	printf("p->p2 = %d\n", p->p2);
}

void		ft_sort_stack_b(t_p *p)
{
	if (p->mas_b[0] <= p->p1 && p->bnum > 1)
	{
		if (p->mas_b[1] <= p->p2 && p->mas_b[1] > p->p1 && p->bnum > 1)
			ft_rb(p);
	}
}

void			ft_find_min_and_max(t_p *p)
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
			ft_sort_stack_b(p);
		}
	}
}

void			ft_create_circle(t_p *p)
{
	while (p->anum != 3)
	{
		if (p->mas_a[0] == 0 || p->mas_a[0] == p->max)
			ft_ra(p);
		ft_pb(p);
	}
	if (p->mas_a[0] == p->max && p->mas_a[1] != 0)
		ft_sa(p);
	else if (p->mas_a[0] == 0 && p->mas_a[1] == p->max)
		ft_sa(p);
	else if (p->mas_a[0] != 0 && p->mas_a[0] != p->max && p->mas_a[1] == 0)
		ft_sa(p);
}

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

void			ft_matched(t_p *p, int number)
{
	ft_mas_a2(p);
	printf("number = %d\n", number);
	printf("p->anum = %d\n", p->anum);
	printf("p->mas_a[0] = %d\n", p->mas_a[0]);
	printf("p->mas_a[p->anum - 1] = %d\n", p->mas_a[p->anum - 1]);
	while ((number > p->mas_a[0] && number < p->mas_a[p->anum - 1]) != 1)
	{
		p->count_ra2++;
		ft_ra2(p);
	}
	printf("Hello\n");
	ft_rebuf_mas_a(p);
	while ((number > p->mas_a[0] && number < p->mas_a[p->anum - 1]) != 1)
	{
		p->count_rra2++;
		ft_rra2(p);
	}
	printf("222\n");
	ft_rebuf_mas_a(p);
	ft_intstrdel(&p->mas_a2);
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
	while (i < p->bnum + 1)
	{
		i++;
		p->count_rrb2++;
	}
}

int			ft_optimization_way3(t_p *p)
{
	if (p->count_ra2 < p->count_rb2)
		return (p->count_rb2);
	else if ((p->count_ra2 >= p->count_rb2))
		return (p->count_ra2);
	return (0);
}

int			ft_optimization_way4(t_p *p)
{
	if (p->count_rra2 < p->count_rrb2)
		return (p->count_rrb2);
	else if ((p->count_rra2 >= p->count_rrb2))
		return (p->count_rra2);
	return (0);
}

void			ft_best_decision(t_p *p)
{
	int way[4];
	int i;

	i = -1;
	way[0] = 0;
	way[1] = 0;
	way[2] = 0;
	way[3] = 0;
	way[0] = p->count_ra2 + p->count_rrb2; // up down
	way[1] = p->count_rra2 + p->count_rb2; // down up
	way[2] = ft_optimization_way3(p);	// up up
	way[3] = ft_optimization_way4(p); // dawn dawn
	p->best_score = way[0];
	if (++i < 4)
	{
		if (way[i] < p->best_score)
		{
			p->best_way = i;
			p->best_score = way[i];
		}
	}
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
		ft_up_or_down_in_buf_b(p, i);
		ft_matched(p, p->mas_b[i]);
		ft_best_decision(p);
		if (p->best_number > p->best_score)
		{
			p->best_number = p->best_score;
			p->elem_to_move = i;
		}
	}
}

void			ft_whirling(t_p *p)
{
	ft_poin1_point2(p);
	ft_find_min_and_max(p);
	ft_create_circle(p);
	ft_printstacks(p);
	ft_from_b_to_a(p);
	printf("p->elem_to_move = %d\n", p->elem_to_move);
	printf("p->best_number = %d\n", p->best_number);
}
