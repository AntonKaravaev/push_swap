/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb_supfun5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:49:25 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/01 19:51:12 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_pb_sup1(t_p *p)
{
	int	i;
	int	*mas_temp;

	if (p->bnum == 1)
	{
		if (!(p->mas_b = (int *)malloc(sizeof(int) * 1)))
			exit(-1);
		p->mas_b[0] = p->mas_a[0];
		return ;
	}
	if (!(mas_temp = (int *)malloc(sizeof(int) * p->bnum)))
		exit(-1);
	i = 0;
	mas_temp[i] = p->mas_a[0];
	while (++i < p->bnum)
		mas_temp[i] = p->mas_b[i - 1];
	ft_intstrdel(&p->mas_b);
	if (!(p->mas_b = (int *)malloc(sizeof(int) * p->bnum)))
		exit(-1);
	i = -1;
	while (++i < p->bnum)
		p->mas_b[i] = mas_temp[i];
	ft_intstrdel(&mas_temp);
}

static void	ft_pb_sup2(t_p *p)
{
	int	i;
	int	*mas_temp;

	if (p->anum == 0)
		ft_intstrdel(&p->mas_a);
	else
	{
		if (!(mas_temp = (int *)malloc(sizeof(int) * p->anum)))
			exit(-1);
		i = -1;
		while (++i < p->anum)
			mas_temp[i] = p->mas_a[i + 1];
		ft_intstrdel(&p->mas_a);
		if (!(p->mas_a = (int *)malloc(sizeof(int) * p->anum)))
			exit(-1);
		i = -1;
		while (++i < p->anum)
			p->mas_a[i] = mas_temp[i];
		ft_intstrdel(&mas_temp);
	}
}

void		ft_pb(t_p *p)
{
	if (p->anum > 0)
	{
		p->anum--;
		p->bnum++;
		ft_pb_sup1(p);
		ft_pb_sup2(p);
	}
}
