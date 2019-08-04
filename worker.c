/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:39:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/04 03:59:58 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_maxinsort(t_p *p, int i)
{
	p->max = p->mas_a[0];
	while(++i < p->anum)
		p->max = (p->max < p->mas_a[i]) ? p->mas_a[i] : p->max;
}

static int		ft_equal(t_p *p, int num, int temp)
{
	int i;

	i = -1;
	while(++i < num + 1)
	{
		if (temp == p->sorted[i])
			return (1);
	}
	return (0);
}

void			ft_sorting(t_p *p)
{
	int i;
	int j;

	i = -1;
	p->sorted = NULL;
	if (!(p->sorted = (int *)malloc(sizeof(int) * p->anum)))
		exit(-1);
	ft_maxinsort(p, 0);
	while(++i < p->anum)
	{
		j = -1;
		p->sorted[i] = p->max;
		while(++j < p->anum)
		{
			if (p->sorted[i] > p->mas_a[j] && ft_equal(p, i, p->mas_a[j]) != 1)
				p->sorted[i] = p->mas_a[j];
		}
	}
	p->sorted[i - 1] = p->max;
}

void	ft_value_of_position(t_p *p)
{
	int i;
	int j;

	i = -1;
	while(++i < p->anum)
	{
		j = -1;
		while(++j < p->anum)
		{
			if (p->mas_a[i] == p->sorted[j])
			{
				p->mas_a[i] = j;
				break;
			}
		}
	}

	i = -1;
	// while(++i < p->anum)
	// {
	// 	printf("p->sorted[%d] = %d\n", i, p->sorted[i]);
	// }
	printf("\n");
}

// void ft_checkgoodline(t_p *p)
// {
// 	int temp;
// 	int i;
// 	int j;
//
// 	temp = 1;
// 	i = -1;
// 	j = 0;
// 	p->goodline = 1;
//  	while(++j < p->anum)
// 	{
// 		if (p->mas_a[j] == p->mas_a[j + 1] - 1)
// 			temp++;
// 		else if (p->mas_a[j] == p->mas_a[j + 1] - 1)
// 		{
// 			if (temp > p->goodline)
// 				p->goodline = temp;
// 			temp = 1;
// 		}
// 	}
// 	printf("p->goodline = %d\n", p->goodline);
// }
int		ft_find_optimal_way(t_p *p, int i)
{
	int bot;
	int top;

	bot = 0;
	top = 0;
	if (i <= p->howmuch)
		bot = i;
	else
		bot = -1;
	if (p->bnum - i <= p->howmuch)
		top = p->bnum - i;
	else
		top = -1;
	if (bot == -1 && top == -1)
		return (i);
	if (bot <= top && bot != -1)
	{
		while (i != 0)
		{
			ft_rb(p);
			i--;
		}
	}
	else if (top != -1)
	{
		while (top != 0)
		{
			ft_rrb(p);
			top--;
		}
	}
	return (0);
}

void	ft_from_b_to_a(t_p *p, int num) // int num удалть это для проверки идеи
{
	int i;
	int check;

	i = -1;
	check = 0;
	while (++i < p->bnum)
	{
		if (p->mas_a[p->anum - 1] + 1  == p->mas_b[i] || (num >= 14 && p->mas_a[0] - 1  == p->mas_b[i]))
		// второе условие только тогда, когда все сойдется по 0 или MAX
		{
				printf("I was here\n");
			check = 1;
			if (check == 1)
			{
				if (ft_find_optimal_way(p, i) <= p->howmuch)
					ft_pa(p);
				return ;
			}
		}
	}
}


void ft_firstcycle(t_p *p)
{
	int temp;
	int connection;
	int i;
	int j;

	temp = 1;
	i = -1;
	j = 0;
	connection = 0;
	p->goodline = 1;
	temp = p->anum;
 	while(++i < temp + 5) // подчистить
	{
		if (p->bnum > 0)
			ft_from_b_to_a(p, i); // i - добавлено исключительно для проверки идеи
		if (p->mas_a[j] == p->mas_a[j + 1] - 1)
		{
			p->goodline++;
			if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
				ft_rr(p);
			else
				ft_ra(p);
		}
		else if (p->mas_a[j] - 1 == p->mas_a[j + 1])
		{
			p->goodline++;
			if (p->bnum > 1 && p->mas_b[0] < p->mas_b[1])
			{
				ft_ss(p);
				ft_rr(p);
			}
			if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
			{
				ft_sa(p);
				ft_rr(p);
			}
			else
			{
				ft_sa(p);
				ft_ra(p);
			}
		}
		else if (p->mas_a[j] == 0 && p->mas_a[j + 1] == p->anum - 1)
		{
			p->goodline++;
			if (p->bnum > 1 && p->mas_b[0] < p->mas_b[1])
			{
				ft_ss(p);
				ft_rr(p);
			}
			if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
			{
				ft_sa(p);
				ft_rr(p);
			}
			else
			{
				ft_sa(p);
				ft_ra(p);
			}
		}
		else if (p->mas_a[j + 1] == p->anum - 1 && p->mas_a[p->anum - 1] == 0)
		{
			p->goodline++;
			if (p->bnum > 1 && p->mas_b[0] < p->mas_b[1])
			{
				ft_ss(p);
				ft_rr(p);
			}
			if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
			{
				ft_sa(p);
				ft_rr(p);
			}
			else
			{
				ft_sa(p);
				ft_ra(p);
			}
		}
		else if (p->mas_a[j] != p->mas_a[j + 1] - 1)
		{
			if (p->mas_a[j] == p->mas_a[p->anum - 1] + 1)
			{
				p->goodline++;
				if (p->bnum > 1 && p->mas_b[0] > p->mas_b[1])
					ft_rr(p);
				else
					ft_ra(p);
			}
			else
				ft_pb(p);
		}
	}
	printf ("i = %d\n", i);
}

void		ft_how_much(t_p *p)
{
	if (p->anum <= 10)
		p->howmuch = 5;
	else if (p->anum <= 50)
		p->howmuch = 8;
	else if (p->anum <= 100)
		p->howmuch = 10;
	else if (p->anum <= 500)
		p->howmuch = 25;
	else if (p->anum <= 1000)
		p->howmuch = 30;
	else if (p->anum <= 10000)
		p->howmuch = 160;
	else
		p->howmuch = 1000;
}

void		ft_whattodo(t_p *p)
{
	printf ("p->bnum = %d\n", p->bnum);
	ft_how_much(p);
	ft_firstcycle(p);
	ft_printstacks(p);
}


void			ft_worker(t_p *p)
{
	ft_sorting(p);
	ft_value_of_position(p);
	ft_whattodo(p);
}
