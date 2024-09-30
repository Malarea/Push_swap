/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:21:58 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:21:59 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	petit_tri(t_list **pile)
{
	const int	n1 = ft_atoi((*pile)->content);
	const int	n2 = ft_atoi((*pile)->next->content);
	const int	n3 = ft_atoi((*pile)->next->next->content);

	if (n1 == pile_min(*pile) && n2 == pile_max(*pile))
	{
		start("sa", pile, 0, 1);
		start("ra", pile, 0, 1);
	}
	else if (n2 == pile_min(*pile) && n3 == pile_max(*pile))
		start("sa", pile, 0, 1);
	else if (n3 == pile_min(*pile) && n2 == pile_max(*pile))
		start("rra", pile, 0, 1);
	else if (n2 == pile_min(*pile) && n1 == pile_max(*pile))
		start("ra", pile, 0, 1);
	else
	{
		start("sa", pile, 0, 1);
		start("rra", pile, 0, 1);
	}
}

static void	gros_tri(t_list **pile_a)
{
	int		a;
	int		b;
	t_list	*pile_b;

	pile_b = 0;
	while (ft_lstsize(*pile_a) > 3)
		start("pb", pile_a, &pile_b, 1);
	if (!verif_tri(*pile_a))
		petit_tri(pile_a);
	while (ft_lstsize(pile_b))
	{
		a = 0;
		b = 0;
		min_rotate(*pile_a, pile_b, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			meme_rotate(pile_a, &pile_b, a, b);
		else
			diff_rotate(pile_a, &pile_b, a, b);
		start("pa", &pile_b, pile_a, 1);
	}
}

static void	tri_final(t_list **pile)
{
	const int	i = pile_minmax(*pile, pile_min(*pile));

	if (i < 0)
		start("rra", pile, 0, -i);
	else
		start("ra", pile, 0, i);
}

void	tri(t_list **pile)
{
	if (ft_lstsize(*pile) == 2)
		start("sa", pile, 0, 1);
	else if (ft_lstsize(*pile) == 3)
		petit_tri(pile);
	else
		gros_tri(pile);
	tri_final(pile);
}
