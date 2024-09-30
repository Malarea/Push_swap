/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:22:22 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:22:23 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	main(int argc, char **argv)
{
	int		len;
	char	**strs;
	t_list	*pile;

	if (argc > 1)
	{
		strs = 0;
		len = split_argv(&strs, argv + 1, " ");
		if (!len || !verif_valid(strs))
		{
			ft_free(strs);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		pile = 0;
		while (len--)
			ft_lstadd_front(&pile, ft_lstnew(strs[len]));
		if (!verif_tri(pile))
			tri(&pile);
		ft_lstclear(&pile, free);
		free(strs);
	}
	return (0);
}
