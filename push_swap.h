/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:29:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/04 01:47:49 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_p
{
	int		*mas_a;
	int		*mas_b;
	int		*sorted;
	int		anum;
	int		bnum;
	int		goodline;
	int		howmuch;
	int		max;
}				t_p;

int				main(int argc, char *argv[]);
void			ft_parser(int ac, char **line, t_p *p);
void			ft_worker(t_p *p);
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
