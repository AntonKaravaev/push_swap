/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/05 19:32:05 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_maxinsort(t_p *p, int i)
{
	p->max = p->mas_a[0];
	while(++i < p->anum)
		p->max = (p->max < p->mas_a[i]) ? p->mas_a[i] : p->max;
}

static int		ft_equal(t_p *p, int num, int temp)
{
	int i;

	i = -1;
	while(++i < num + 1)
	{
		if (temp == p->sorted[i])
			return (1);
	}
	return (0);
}

void			ft_sorting(t_p *p)
{
	int i;
	int j;

	i = -1;
	p->sorted = NULL;
	if (!(p->sorted = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
	ft_maxinsort(p, 0);
	while(++i < p->anum)
	{
		j = -1;
		p->sorted[i] = p->max;
		while(++j < p->anum)
		{
			if (p->sorted[i] > p->mas_a[j] && ft_equal(p, i, p->mas_a[j]) != 1)
				p->sorted[i] = p->mas_a[j];
		}
	}
	p->sorted[i - 1] = p->max;
}

void	ft_value_of_position(t_p *p)
{
	int i;
	int j;

	i = -1;
	while(++i < p->anum)
	{
		j = -1;
		while(++j < p->anum)
		{
			if (p->mas_a[i] == p->sorted[j])
			{
				p->mas_a[i] = j;
				break;
			}
		}
	}
}

int		ft_find_optimal_way(t_p *p, int i)
{
	int bot;
	int top;

	bot = i;
	top = p->bnum - i;
	if (bot <= top)
	{
		while (i != 0)
		{
			ft_rb(p);
			i--;
		}
	}
	else
	{
		while (top != 0)
		{
			ft_rrb(p);
			top--;
		}
	}
	return (1);
}

void	ft_from_b_to_a(t_p *p)
{
	int i;
	int check;

	i = -1;
	check = 0;

	// printf ("p->anum = %d\n", p->anum);
	// printf ("p->bnum = %d\n", p->bnum);
	// printf ("p->max = %d\n", p->max);
	// // printf ("p->bnum = %d\n", p->bnum);
	while (++i < p->bnum)
	{
		if (p->mas_a[p->anum - 1] + 1 == p->mas_b[i]
			|| ((p->mas_a[p->anum - 1] == p->max) && p->mas_b[i] == 0))
		{
			if (ft_find_optimal_way(p, i))
				ft_pa(p);
			return ;
		}
	}
}

int		ft_where_is_the_zero(t_p *p)
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
int		ft_cycle_ok(t_p *p)
{
	int i;

	i = 0;
	if (ft_where_is_the_zero(p) == 1)
	{
		if (p->zeropos == 0)
		{
			while (i < p->anum - 1)
			{
				if (p->mas_a[i] == p->mas_a[i + 1] - 1)
					i++;
				else
					return (0);
			}
			if (i == p->anum - 1)
				return (1);
		}
		else if (p->zeropos == p->anum - 1)
		{
			while (i < p->anum - 1)
			{
				if (p->mas_a[i] == p->mas_a[i + 1] + 1)
					i++;
				else
					return (0);
			}
			if (i == p->anum - 1)
				return (1);
		}
		else
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
			if (i == p->anum - 1)
				return (1);
		}
	}
	return (0);
}

void		ft_find_zero_pos(t_p *p)
{
	int i;

	i = 0;
	while (i < p->anum)
	{
		if (p->mas_a[i] == 0)
			break;
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

void		ft_whirling(t_p *p)
{
	int i;

	i = -1;
	p->connection = 0;
	p->max = p->anum - 1;
 	while(++i < p->max + 1)
	{
		if (p->bnum > 0)
			ft_from_b_to_a(p);
		if (p->bnum == 0 && ft_cycle_ok(p) == 1)
			break ;
		if (ft_w1(p) == 1)
			p->connection++;
		else if (p->mas_a[0] - 1 == p->mas_a[1] || (p->mas_a[0] == 0 && p->mas_a[1] == p->max))
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
		else
		{
			if ((p->mas_a[0] == p->mas_a[p->anum - 1] + 1) || (p->mas_a[0] == 0 && p->mas_a[p->anum - 1] == p->max))
			{
				if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
					ft_rr(p);
				else
					ft_ra(p);
			}
			else
				ft_pb(p);
		}
	}
	printf ("i = %d\n", i);
}


void			ft_worker(t_p *p)
{
	ft_sorting(p);
	ft_value_of_position(p);
	ft_whirling(p);
	//ft_find_zero_pos(p);
	ft_printstacks(p);
}
