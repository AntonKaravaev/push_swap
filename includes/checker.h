/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:29:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/25 04:38:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

typedef struct	s_p
{
	int		*mas_a;
	int		*mas_b;
	int		anum;
	int		bnum;
	int		i;
}				t_p;

int				main(int argc, char *argv[]);
void			ft_parser(int ac, char **line, t_p *p);
void			ft_worker(char **line, t_p *p);
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

#endif
