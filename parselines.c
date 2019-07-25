/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parselines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:29:50 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/26 02:33:03 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_parseoneline(char *line, t_p *p)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
		i++;
	if (i != 0)
	{
		if (!(p->mas_a = (int *)malloc(sizeof(int) * i)))
			exit(-1);
		i = -1;
		while (str[++i])
			p->mas_a[i] = ft_atoi(str[i]);
		p->numbers = i;
		ft_str2del(&str);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

void			ft_parselines(int ac, char **line, t_p *p)
{
	int	i;

	i = 0;
	if (ac == 2)
		ft_parseoneline(line[1], p);
	else
	{
		if (!(p->mas_a = (int *)malloc(sizeof(int) * (ac - 1))))
			exit(-1);
		while (ac-- > 1 && line[++i])
			p->mas_a[i - 1] = ft_atoi(line[i]);
		p->numbers = i;
	}
	if (p->numbers == 1)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	printf("p->numbers= %d\n", p->numbers);
	i = -1;
	while (++i < p->numbers)
		printf("p->mas_a[%d]= %d\n", i, p->mas_a[i]);
}
