/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/08 03:02:03 by crenly-b         ###   ########.fr       */
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

static void ft_rebufmas_a(t_p *p)
{
	int i;

	i = 0;
	ft_freebufs(p);
	if (!(p->mas_a = (int *)malloc(sizeof(int) * p->anum2)))
		exit(-1);
	while (i < p->anum2)
	{
		p->mas_a[i] = p->mas_a2[i];
		i++;
	}
	p->anum = p->anum2;
	ft_intstrdel(&p->mas_a2);
	p->bnum = 0;
}

void			ft_bad_buf_create(t_p *p)
{
	p->i = -1;
	p->bad_numbers = 0;
	if (!(p->bad_buf = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
}

void			ft_bad_buf_fill_in(t_p *p, int number)
{
	p->i++;
	p->bad_numbers++;
	p->bad_buf[p->i] = number;
}

void			ft_check_bad_numbers(t_p *p)
{
	int i;
	int number;

	i = p->end - 1;
	number = p->mas_a2[p->end];
	ft_bad_buf_create(p);
	if (p->begin < p->end)
	{
		while (++i < p->anum - 1)
		{
			if (number < p->mas_a2[i + 1])
				number = p->mas_a2[i + 1];
			else
				ft_bad_buf_fill_in(p, p->mas_a2[i + 1]);
		}
		i = p->begin + 1;
		number = p->mas_a2[p->begin];
		while (--i > 0)
		{
			if (number > p->mas_a2[i - 1])
				number = p->mas_a2[i - 1];
			else
				ft_bad_buf_fill_in(p, p->mas_a2[i - 1]);
		}
	}
}

void			ft_preworker(t_p *p)
{
	ft_sorting(p);
	ft_prewhirling(p);
	if (p->cycle_ok == 1)
	{
		printf("1\n");
		ft_rebufmas_a(p);
		ft_whirling(p);
		ft_find_zero_pos_and_twist(p);
	}
	else if (ft_findbestorder(p) == 1)
	{
		printf("2\n");
		ft_rebufmas_a(p);
		ft_whirling(p);
		ft_find_zero_pos_and_twist(p);
	}
	else
	{
		printf("3\n");
		ft_check_bad_numbers(p);
		ft_rebufmas_a(p);
		ft_whirling_2(p);
		ft_whirling(p);
		ft_find_zero_pos_and_twist(p);
	}
	printf("Last stack \n");
	ft_printstacks(p);
}
