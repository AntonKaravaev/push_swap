/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:29:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/26 02:31:52 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"

typedef struct	s_p
{
	int		*mas_a;
	int		*mas_b;
	int		numbers;
	int		i;
}				t_p;

int				main(int argc, char *argv[]);
void			ft_parselines(int ac, char **line, t_p *p);

#endif
