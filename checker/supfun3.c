/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:49:35 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/31 17:55:37 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrr(t_p *p)
{
	ft_rra(p);
	ft_rrb(p);
}

void			ft_sorted(t_p *p)
{
	int i;

	i = 0;
	if (p->anum > 1)
	{
		while (i < p->anum - 1)
		{
			if (p->mas_a[i] < p->mas_a[i + 1] && p->bnum == 0)
				i++;
			else
			{
				write(1, "KO\n", 3);
				return ;
			}
		}
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

void		ft_printmassive(t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("aa massive = \n");
	printf("p->anum = %d \n", p->anum);
	while (i < p->anum)
	{
		printf("%d ", p->mas_a[i]);
		i++;
	}
	printf("\n");
	// printf("bb massive = \n");
	printf("p->bnum = %d \n", p->bnum);
	// while (j < p->bnum)
	// {
	// 	printf("%d ", p->mas_b[j]);
	// 	j++;
	// }
	// printf("\n");
}
