/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:53:03 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/07 20:36:15 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_findbestorder_sup1(t_p *p, int *i, int *j, int *connections)
{
	p->bestconnections = 0;
	p->circle = 0;
	p->begin = 0;
	p->end = 0;
	if (*i == 0)
	{
		*j = p->anum - 1;
		while ((p->mas_a[*i] == p->mas_a[*j] + 1 || (p->mas_a[*i] == 0 && p->mas_a[*j] == p->max)) && *j >= 0)
		{
			(*connections)++;
			p->circle = 1;
			if (*connections > p->bestconnections)
			{
				p->bestconnections = *connections;
				p->begin = *j;
			}
			(*j)--;
			if (*j < p->anum - 1)
				*i = *j + 1;
		}
		*i = 0;
		printf("\n");
		printf("!!p->bestconnections = %d\n", p->bestconnections);
		printf("!!connections = %d\n", *connections);
		printf("p->circle = %d\n", p->circle);
		printf("i = %d\n", *i);
		printf("j = %d\n", *j);
		printf("p->mas_a[0] = %d\n", p->mas_a[0]);
		printf("p->mas_a[1] = %d\n", p->mas_a[1]);
		printf("p->begin = %d\n", p->begin);
		printf("p->end = %d\n", p->end);
		printf("\n");
	}
	*i = -1;
}

static void		ft_fb_sup2_1(t_p *p, int *i, int *j, int *connections)
{
	if (*connections > p->bestconnections)
	{
		p->bestconnections = *connections;
		if (p->circle == 1 && *i == 0)
		{
			p->end = *i + *j;
			p->circle = 0;
		}
		else
		{
			p->begin = *i;
			p->end = *i + *j;
		}
	}
}

static void		ft_findbestorder_sup2(t_p *p, int *i, int *j, int *connections)
{
	while (++(*i) < p->anum)
	{
		*j = -1;
		while (++(*j) < p->anum - 1)
		{
			if ((p->mas_a[*i + *j] == p->mas_a[*i + *j + 1] - 1)
				|| (p->mas_a[*i + *j] == p->max && p->mas_a[*i + *j + 1] == 0))
					(*connections)++;
			else
			{
				ft_fb_sup2_1(p, i, j, connections);
				break ;
			}
		}
		*connections = 1;
	}
}

int			ft_findbestorder(t_p *p)
{
	int connections;
	int i;
	int j;

	i = 0;
	connections = 1;
	ft_findbestorder_sup1(p, &i, &j, &connections);
	ft_findbestorder_sup2(p, &i, &j, &connections);
	printf("-----------------------\n");
	printf("| p->begin = %d        |\n", p->begin);
	printf("| p->end = %d          |\n", p->end);
	printf("-----------------------\n");
	if (p->bestconnections >= p->anum)
	{
		printf("p->anum = %d, p->bestconnections = %d \n", p->anum, p->bestconnections);
		printf("All in stack are good \n");
		return (1);
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
	return (0);
}
