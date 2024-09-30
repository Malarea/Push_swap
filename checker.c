/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:22:05 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:22:07 by emachrek         ###   ########.fr       */
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

static int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	parse(char *str, t_list **pile_1, t_list **pile_2)
{
	int	len;
	int	(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ft_error());
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && (!f(str, "sa", 2)
				|| !f(str, "ra", 2))))
		start(str, pile_1, 0, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && (!f(str, "sb", 2)
				|| !f(str, "rb", 2))))
		start(str, pile_2, 0, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && (!f(str, "ss", 2)
				|| !f(str, "pb", 2) || !f(str, "rr", 2))))
		start(str, pile_1, pile_2, -1);
	else if (!f(str, "pa", 2))
		start(str, pile_2, pile_1, -1);
	else
		return (ft_error());
	return (0);
}

static void	ft_check(t_list **pile_a)
{
	char		*cmd;
	t_list		*pile_b;
	static char	*str;

	pile_b = 0;
	while (1)
	{
		cmd = get_next_line(&str);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (parse(cmd, pile_a, &pile_b))
		{
			free(str);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (verif_tri(*pile_a) && !ft_lstsize(pile_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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
		ft_check(&pile);
		ft_lstclear(&pile, free);
		free(strs);
	}
	return (0);
}
