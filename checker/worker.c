#include "checker.h"

static void		ft_sorted(t_p *p)
{
	int i;

	i = 0;
	if (p->anum > 1)
	{
		while (i < p->anum - 1)
		{
			if (p->mas_a[i] < p->mas_a[i + 1] && p->bnum == 0)
				i++;
			else
			{
				write(1, "KO\n", 3);
				return ;
			}
		}
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

static void		ft_whattodo(char **line, t_p *p)
{
	if (ft_strequ(*line, "sa\0") == 1)
		ft_sa(p);
	else if (ft_strequ(*line, "sb\0") == 1)
		ft_sb(p);
	else if (ft_strequ(*line, "ss\0") == 1)
		ft_ss(p);
	else if (ft_strequ(*line, "pa\0") == 1)
		ft_pa(p);
	else if (ft_strequ(*line, "pb\0") == 1)
		ft_pb(p);
	else if (ft_strequ(*line, "ra\0") == 1)
		ft_ra(p);
	else if (ft_strequ(*line, "rb\0") == 1)
		ft_rb(p);
	else if (ft_strequ(*line, "rr\0") == 1)
		ft_rr(p);
	else if (ft_strequ(*line, "rra\0") == 1)
		ft_rra(p);
	else if (ft_strequ(*line, "rrb\0") == 1)
		ft_rrb(p);
	else if (ft_strequ(*line, "rrr\0") == 1)
		ft_rrr(p);
	else
		ft_error();
}

void			ft_worker(char **line, t_p *p)
{
	while (1)
	{
		if (get_next_line(0, line) > 0)
		{
			ft_whattodo(line, p);
			ft_strdel(line);
		}
		else
		{
			ft_printmassive(p);
			ft_sorted(p);
			ft_strdel(line);
			break ;
		}
	}
}
