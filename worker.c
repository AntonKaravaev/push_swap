/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/02 08:19:01 by crenly-b         ###   ########.fr       */
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

	i = -1;
	while(++i < p->anum)
	{
		printf("p->mas_a[%d] = %d\n", i, p->mas_a[i]);
	}
	i = -1;
	while(++i < p->anum)
	{
		printf("p->sorted[%d] = %d\n", i, p->sorted[i]);
	}
}

void ft_checkgoodline(t_p *p)
{
	int temp;
	int i;
	int j;

	temp = 1;
	i = -1;
	j = 0;
	p->goodline = 1;
 	while(++j < p->anum)
	{
		if (p->mas_a[j] == p->mas_a[j + 1] - 1)
			temp++;
		else
		{
			if (temp > p->goodline)
				p->goodline = temp;
			temp = 1;
		}
	}
	printf("p->goodline = %d\n", p->goodline);
}

void ft_whattodo(t_p *p)
{
	ft_checkgoodline(p);
}

void			ft_worker(t_p *p)
{
	ft_sorting(p);
	ft_value_of_position(p);
	ft_whattodo(p);
}
