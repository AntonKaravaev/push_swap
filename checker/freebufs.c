#include "checker.h"

static void	ft_intstrdel(int **as)
{
	if (as)
	{
		if (*as != NULL)
		{
			free(*as);
			*as = NULL;
		}
	}
}

void		ft_freebufs(t_p *p)
{
	ft_intstrdel(&p->mas_a);
	ft_intstrdel(&p->mas_b);
}

void		ft_error(t_p *p)
{
	ft_intstrdel(&p->mas_a);
	ft_intstrdel(&p->mas_b);
	write(1, "Error\n", 6);
	exit (-1);
}
