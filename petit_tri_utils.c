/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_tri_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:21:39 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:21:40 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	pile_min(t_list *pile)
{
	int		min;
	int		num;

	min = ft_atoi(pile->content);
	while (pile)
	{
		num = ft_atoi(pile->content);
		if (min > num)
			min = num;
		pile = pile->next;
	}
	return (min);
}

int	pile_max(t_list *pile)
{
	int		max;
	int		num;

	max = ft_atoi(pile->content);
	while (pile)
	{
		num = ft_atoi(pile->content);
		if (max < num)
			max = num;
		pile = pile->next;
	}
	return (max);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
