/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:29:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/30 23:25:22 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
# define CHECKER

# include "../libft/libft.h"

typedef struct	s_p
{
	int		*mas_a;
	int		*mas_b;
	int		anum;
	int		bnum;
	int		i;
}				t_p;

int				main(int argc, char *argv[]);
void			ft_parselines(int ac, char **line, t_p *p);
void			ft_checkduplicates(t_p *p);
void			ft_createmasb(t_p *p);
void			ft_allreadesorted(t_p *p);
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


void			ft_printmassive(t_p *p); // delete after finishing


#endif
