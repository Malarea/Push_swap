/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gros_tri_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:22:13 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:22:14 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	pile_mid(t_list *pile, int num)
{
	int			current;
	int			next;
	int			ret;
	const int	size = ft_lstsize(pile);

	ret = 1;
	while (pile->next)
	{
		current = ft_atoi(pile->content);
		next = ft_atoi(pile->next->content);
		if (num > current && num < next)
			break ;
		++ret;
		pile = pile->next;
	}
	if (ret == size)
		ret = 0;
	else if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	pile_minmax(t_list *pile, int num)
{
	int			ret;
	int			x;
	const int	size = ft_lstsize(pile);

	ret = 0;
	x = pile_max(pile);
	if (num <= pile_min(pile))
		x = pile_min(pile);
	else
		++ret;
	while (pile)
	{
		if (ft_atoi(pile->content) == x)
			break ;
		++ret;
		pile = pile->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

void	min_rotate(t_list *pile_a, t_list *pile_b, int *a, int *b)
{
	int			i;
	int			j;
	int			num;
	int			x;
	const int	size_b = ft_lstsize(pile_b);

	x = -1;
	while (pile_b && ++x >= 0)
	{
		num = ft_atoi(pile_b->content);
		if (num < pile_min(pile_a) || num > pile_max(pile_a))
			i = pile_minmax(pile_a, num);
		else
			i = pile_mid(pile_a, num);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*a) + ft_abs(*b) > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
		}
		pile_b = pile_b->next;
	}
}

void	meme_rotate(t_list **pile_a, t_list **pile_b, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		start("rr", pile_a, pile_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			start("rb", pile_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			start("ra", pile_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
	else
	{
		start("rrr", pile_a, pile_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			start("rrb", pile_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			start("rra", pile_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
}

void	diff_rotate(t_list **pile_a, t_list **pile_b, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		start("ra", pile_a, 0, a);
		start("rrb", pile_b, 0, ft_abs(min(a, b)));
	}
	else
	{
		start("rb", pile_b, 0, b);
		start("rra", pile_a, 0, ft_abs(min(a, b)));
	}
}
