/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/31 18:16:53 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int			main(int argc, char *argv[])
{
	t_p		p;
	char	*line;

	line = NULL;
	if (argc > 1)
	{
		ft_parser(argc, argv, &p);
		ft_worker(&line, &p);
		ft_freebufs(&p);
	}
	return (0);
}
