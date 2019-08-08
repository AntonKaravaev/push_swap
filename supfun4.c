/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:58:21 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/07 19:20:16 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa2(t_p *p)
{
	int temp;

	if (p->anum >= 2)
	{
		temp = p->mas_a[0];
		p->mas_a[0] = p->mas_a[1];
		p->mas_a[1] = temp;
	}
}

void	ft_sb2(t_p *p)
{
	int temp;

	if (p->bnum >= 2)
	{
		temp = p->mas_a[0];
		p->mas_b[0] = p->mas_b[1];
		p->mas_b[1] = temp;
	}
}

void	ft_ss2(t_p *p)
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
		temp = p->mas_b[0];
		p->mas_b[0] = p->mas_b[1];
		p->mas_b[1] = temp;
	}
}

void	ft_rr2(t_p *p)
{
	ft_ra2(p);
	ft_rb2(p);
}

void	ft_rrr2(t_p *p)
{
	ft_rra2(p);
	ft_rrb2(p);
}
