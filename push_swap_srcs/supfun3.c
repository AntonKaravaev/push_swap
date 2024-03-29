/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:36:38 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/25 00:50:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra2(t_p *p)
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

void	ft_rrb2(t_p *p)
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

void	ft_rrr(t_p *p)
{
	ft_rra2(p);
	ft_rrb2(p);
	write(1, "rrr\n", 4);
}
