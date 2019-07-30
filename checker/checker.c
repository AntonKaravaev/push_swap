/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/30 23:36:15 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>


void		ft_whattodo(char *line, t_p *p)
{
	if (ft_strstr(line, "sa") != NULL)
		ft_sa(p);
	else if (ft_strstr(line, "sb") != NULL)
		ft_sb(p);
	else if (ft_strstr(line, "ss") != NULL)
		ft_ss(p);
	else if (ft_strstr(line, "pa") != NULL)
		ft_pa(p);
	else if (ft_strstr(line, "pb") != NULL)
		ft_pb(p);
	else if (ft_strstr(line, "ra") != NULL)
		ft_ra(p);
	else if (ft_strstr(line, "rb") != NULL)
		ft_rb(p);
	else if (ft_strstr(line, "rr") != NULL)
		ft_rr(p);
	else if (ft_strstr(line, "rra") != NULL)
		ft_rra(p);
	else if (ft_strstr(line, "rrb") != NULL)
		ft_rrb(p);
	else if (ft_strstr(line, "rrr") != NULL)
		ft_rrr(p);
	else
	{
		write(1, "Error\n", 6);
		exit (-1);
	}

}

int			main(int argc, char *argv[])
{
	t_p		p;
	char	*line;

	line = NULL;
	if (argc > 1)
	{
		ft_parselines(argc, argv, &p);
		ft_checkduplicates(&p);
		ft_createmasb(&p);
		ft_allreadesorted(&p);
		while (1)
		{
			if (get_next_line(0, &line) > 0)
				exit(-1);
			ft_whattodo(line, &p);
		}
		ft_printmassive(&p);
	}
	else
		write(1, "Error\n", 6);

	return (0);
}
