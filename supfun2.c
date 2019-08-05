/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:30:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/05 16:59:13 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_p *p)
{
	ft_ra(p);
	ft_rb(p);
	write(1, "rr\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_p *p)
{
	ft_rra(p);
	ft_rrb(p);
	write(1, "rrr\n", 4);
}


void	ft_printstacks(t_p *p)
{
	int i;

	i = -1;
	while(++i < p->anum)
	{
		printf("p->mas_a[%d] = %d\n", i, p->mas_a[i]);
	}
	printf("\n");
	i = -1;
	while(++i < p->bnum)
	{
		printf("p->mas_b[%d] = %d\n", i, p->mas_b[i]);
	}
	printf("\n");
}
