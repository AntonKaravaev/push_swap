/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_sup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:24:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/05 18:49:05 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_w1(t_p *p)
{
	if ((p->mas_a[0] == p->mas_a[1] - 1) || (p->mas_a[0] == p->max && p->mas_a[1] == 0))
	{
		if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
			ft_rr(p);
		else
			ft_ra(p);
		return (1);
	}
	return (0);
}
