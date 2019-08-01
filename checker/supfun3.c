/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfun3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:49:35 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/01 22:01:17 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_printmassive(t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("aa massive = \n");
	printf("p->anum = %d \n", p->anum);
	// if (p->anum > 0)
	// {
	// 	while (i < p->anum && p->mas_b != NULL && p->mas_a[i])
	// 	{
	// 		printf("%d ", p->mas_a[i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// }
	printf("bb massive = \n");
	printf("p->bnum = %d \n", p->bnum);
	// if (p->bnum > 0)
	// {
	// 	while (j < p->bnum && p->mas_b != NULL && p->mas_b[j])
	// 	{
	// 		printf("%d ", p->mas_b[j]);
	// 		j++;
	// 	}
	// }
	printf("\n");
}
