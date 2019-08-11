/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:29:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/11 03:32:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_p
{
	int		*mas_a;
	int		*mas_a2;
	int		count_ra2;
	int		count_rra2;
	int		*mas_b;
	int		count_rb2;
	int		count_rrb2;
	int		*sorted;
	int		cycle_ok : 1;
	int		anum;
	int		bnum;
	int		max;
	int		p1;
	int		p2;
	int		best_score;
	int		best_number;
	int		elem_to_move;
	int		way;
	int		best_way;
	int		best_ra2;
	int		best_rra2;
	int		best_rb2;
	int		best_rrb2;
}				t_p;

int				main(int argc, char *argv[]);
void			ft_parser(int ac, char **line, t_p *p);
void			ft_sorting(t_p *p);
void			ft_worker(t_p *p);
void			ft_whirling(t_p *p);
void			ft_from_b_to_a(t_p *p);
void			ft_best_decision(t_p *p);
void			ft_pos_one_elem(t_p *p);
void			ft_sa(t_p *p);
void			ft_sb(t_p *p);
void			ft_ss(t_p *p);
void			ft_pa(t_p *p);
void			ft_pb(t_p *p);
void			ft_ra(t_p *p);
void			ft_rb(t_p *p);
void			ft_ra2(t_p *p);
void			ft_rb2(t_p *p);
void			ft_rr(t_p *p);
void			ft_rra(t_p *p);
void			ft_rrb(t_p *p);
void			ft_rra2(t_p *p);
void			ft_rrb2(t_p *p);
void			ft_rrr(t_p *p);
void			ft_error();
void			ft_freebufs(t_p *p);
void			ft_intstrdel(int **as);

#endif
