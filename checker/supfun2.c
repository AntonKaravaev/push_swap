/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:30:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/30 22:19:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_p *p)
{
	int i;
	int temp;

	i = 0;
	if (p->anum > 0)
	{
		temp = p->mas_a[0];
		while (i < p->anum - 1)
		{
			p->mas_a[i] = p->mas_a[i + 1];
			i++;
		}
		p->mas_a[i] = temp;
	}
}

void	ft_rb(t_p *p)
{
	int i;
	int temp;

	i = 0;
	if (p->bnum > 0)
	{
		temp = p->mas_b[0];
		while (i < p->bnum - 1)
		{
			p->mas_b[i] = p->mas_b[i + 1];
			i++;
		}
		p->mas_b[i] = temp;
	}
}

void	ft_rr(t_p *p)
{
	ft_ra(p);
	ft_rb(p);
}

void	ft_rra(t_p *p)
{
	int i;
	int temp;
	int temp2;

	i = 0;
	if (p->anum > 0)
	{
		temp = p->mas_a[0];
		p->mas_a[0] = p->mas_a[p->anum - 1];
		while (i < p->anum - 1)
		{
			temp2 = p->mas_a[i + 1];
			p->mas_a[i + 1] = temp;
			temp = temp2;
			i++;
		}
	}
}

void	ft_rrb(t_p *p)
{
	int i;
	int temp;
	int temp2;

	i = 0;
	if (p->bnum > 0)
	{
		temp = p->mas_b[0];
		p->mas_b[0] = p->mas_b[p->bnum - 1];
		while (i < p->bnum - 1)
		{
			temp2 = p->mas_b[i + 1];
			p->mas_b[i + 1] = temp;
			temp = temp2;
			i++;
		}
	}
}
