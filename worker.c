/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/07 01:48:38 by crenly-b         ###   ########.fr       */
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

void			ft_worker(t_p *p)
{
	ft_sorting(p);
	ft_whirling(p);
	if (p->cycle_ok == 1)
		ft_find_zero_pos_and_twist(p);
	printf("Last stack \n");
	ft_printstacks(p);
}
