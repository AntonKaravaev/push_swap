/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:29:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/08 02:22:17 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_p
{
	int		*mas_a;
	int		*mas_a2;
	int		anum2;
	int		*mas_b;
	int		*sorted;
	int		*bad_buf;
	int		i;
	int		bad_numbers;
	int		cycle_ok : 1;
	int		anum;
	int		bnum;
	int		goodline;
	int		howmuch;
	int		zeropos;
	int		max;
	int		circle;
	int		begin;
	int		end;
	int		bestconnections;
}				t_p;

int				main(int argc, char *argv[]);
void			ft_parser(int ac, char **line, t_p *p);
void			ft_sorting(t_p *p);
void			ft_preworker(t_p *p);
void			ft_prewhirling(t_p *p);
void			ft_prefrom_b_to_a(t_p *p);
int				ft_findbestorder(t_p *p);
void			ft_sa2(t_p *p);
void			ft_sb2(t_p *p);
void			ft_ss2(t_p *p);
void			ft_pa2(t_p *p);
void			ft_pb2(t_p *p);
void			ft_ra2(t_p *p);
void			ft_rb2(t_p *p);
void			ft_rr2(t_p *p);
void			ft_rra2(t_p *p);
void			ft_rrb2(t_p *p);
void			ft_rrr2(t_p *p);

void			ft_whirling(t_p *p);
void			ft_whirling_2(t_p *p);
void			ft_from_b_to_a(t_p *p);
int				ft_cycle_ok(t_p *p);

void			ft_sa(t_p *p);
void			ft_sb(t_p *p);
void			ft_ss(t_p *p);
void			ft_pa(t_p *p);
void			ft_pb(t_p *p);
void			ft_ra(t_p *p);
void			ft_rb(t_p *p);
void			ft_rr(t_p *p);
void			ft_rra(t_p *p);
void			ft_rrb(t_p *p);
void			ft_rrr(t_p *p);

void			ft_error();
void			ft_freebufs(t_p *p);
void			ft_intstrdel(int **as);
void			ft_printstacks(t_p *p); // delete after finishing

#endif
