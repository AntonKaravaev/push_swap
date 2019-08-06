/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/06 21:40:30 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	t_p		p;
	char	*line;

	line = NULL;
	if (argc > 1)
	{
		ft_parser(argc, argv, &p);
		ft_worker(&p);
		// ft_freebufs(&p);
	}
	return (0);
}
