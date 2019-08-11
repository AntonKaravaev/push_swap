/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:28:18 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/11 03:45:15 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_p *p)
{
	int temp;

	if (p->anum >= 2)
	{
		temp = p->mas_a[0];
		p->mas_a[0] = p->mas_a[1];
		p->mas_a[1] = temp;
	}
}

void	ft_sb(t_p *p)
{
	int temp;

	if (p->bnum >= 2)
	{
		temp = p->mas_a[0];
		p->mas_b[0] = p->mas_b[1];
		p->mas_b[1] = temp;
	}
}

void	ft_ss(t_p *p)
{
	int temp;

	if (p->anum >= 2)
	{
		temp = p->mas_a[0];
		p->mas_a[0] = p->mas_a[1];
		p->mas_a[1] = temp;
	}
	if (p->bnum >= 2)
	{
		temp = p->mas_a[0];
		p->mas_b[0] = p->mas_b[1];
		p->mas_b[1] = temp;
	}
}

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
