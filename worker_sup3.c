/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_sup3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:14:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/07 02:45:27 by crenly-b         ###   ########.fr       */
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

void	ft_findbestorder(t_p *p)
{
	int connections;
	int i;
	int j;

	i = 0;
	connections = 1;
	p->bestconnections = 0;
	p->circle = 0;
	p->begin = 0;
	p->end = 0;
	if (i == 0)
	{
		j = p->anum - 1;
		while ((p->mas_a[i] == p->mas_a[j] + 1 || (p->mas_a[i] == 0 && p->mas_a[j] == p->max)) && j >= 0)
		{
			connections++;
			p->circle = 1;
			if (connections > p->bestconnections)
			{
				p->bestconnections = connections;
				p->begin = j;
			}
			j--;
			if (j < p->anum - 1)
			{
				i = j + 1;
			}
		}
		i = 0;
		printf("\n");
		printf("!!p->bestconnections = %d\n", p->bestconnections);
		printf("!!connections = %d\n", connections);
		printf("p->circle = %d\n", p->circle);
		printf("i = %d\n", i);
		printf("j = %d\n", j);
		printf("p->mas_a[0] = %d\n", p->mas_a[0]);
		printf("p->mas_a[1] = %d\n", p->mas_a[1]);
		printf("p->begin = %d\n", p->begin);
		printf("p->end = %d\n", p->end);
		printf("\n");
	}
	i = -1;
	while (++i < p->anum)
	{
		j = -1;
		while (++j < p->anum - 1)
		{
			if ((p->mas_a[i + j] == p->mas_a[i + j + 1] - 1)
				|| (p->mas_a[i + j] == p->max && p->mas_a[i + j + 1] == 0))
				connections++;
			else
			{
				if (connections > p->bestconnections)
				{
					p->bestconnections = connections;
					if (p->circle == 1)
					{
						p->end = i + j;
						p->circle = 0;
					}
					else
					{
						p->begin = i;
						p->end = i + j;
					}

				}
				break ;
			}
		}
		connections = 1;
	}
	printf("p->bestconnections = %d\n", p->bestconnections);
	printf("p->circle = %d\n", p->circle);
	printf("p->begin = %d\n", p->begin);
	printf("p->end = %d\n", p->end);
	if (p->bestconnections >= p->anum)
	{
		printf("p->anum = %d, p->bestconnections = %d \n", p->anum, p->bestconnections);
		printf("All in stack are good \n");
	}
	if (p->circle == 0)
	{
		i = p->begin;
		while (i <= p->end)
		{
			printf("p->mas_a[%d] = %d\n", i, p->mas_a[i]);
			i++;
		}
	}
	else
	{
		i = p->begin;
		while (i < p->anum)
		{
			printf("p->mas_a[%d] = %d\n", i, p->mas_a[i]);
			i++;
		}
		i = 0;
		while (i <= p->end)
		{
			printf("p->mas_a[%d] = %d\n", i, p->mas_a[i]);
			i++;
		}
	}

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
	i = 0;
	while (i < p->anum)
	{
		printf("p->mas_a2[%d] = %d\n", i, p->mas_a2[i]);
		i++;
	}
}

void			ft_whirling(t_p *p)
{
	int i;

	i = -1;
	p->max = p->anum - 1;
	p->cycle_ok = 0;
	ft_mas_a2_create(p);
	while (++i < p->max + 2)
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
	if (p->cycle_ok == 1)
		return ;
	ft_findbestorder(p);
	printf("i = %d\n", i);
	printf("p->max = %d\n", p->max);
}
