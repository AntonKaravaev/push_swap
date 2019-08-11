/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/11 03:25:59 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_p_fill_in(t_p *p)
{
	p->mas_a = NULL;
	p->mas_a2 = NULL;
	p->count_ra2 = 0;
	p->count_rra2 = 0;
	p->mas_b = NULL;
	p->count_rb2 = 0;
	p->count_rrb2 = 0;
	p->sorted = NULL;
	p->cycle_ok = 0;
	p->anum = 0;
	p->bnum = 0;
	p->max = 0;
	p->p1 = 0;
	p->p2 = 0;
	p->best_way = 0;
	p->best_number = 0;
	p->best_score = 0;
	p->elem_to_move = 0;
	p->best_ra2 = 0;
	p->best_rra2 = 0;
	p->best_rb2 = 0;
	p->best_rrb2 = 0;
	p->way = 0;
}

int			main(int argc, char *argv[])
{
	t_p		p;
	char	*line;

	line = NULL;
	ft_p_fill_in(&p);
	if (argc > 1)
	{
		ft_parser(argc, argv, &p);
		ft_worker(&p);
		ft_freebufs(&p);
	}
	return (0);
}
