/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:21:30 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:21:31 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_s(t_list **pile_1, t_list **pile_2)
{
	t_list	*tmp;

	(void)pile_2;
	if (ft_lstsize(*pile_1) >= 2)
	{
		tmp = (*pile_1)->next;
		(*pile_1)->next = tmp->next;
		ft_lstadd_front(pile_1, tmp);
	}
}

static void	ft_p(t_list **pile_1, t_list **pile_2)
{
	t_list	*tmp;

	if (ft_lstsize(*pile_1))
	{
		tmp = *pile_1;
		*pile_1 = (*pile_1)->next;
		ft_lstadd_front(pile_2, tmp);
	}
}

static void	ft_r(t_list **pile_1, t_list **pile_2)
{
	t_list	*tmp;

	(void)pile_2;
	if (ft_lstsize(*pile_1) >= 2)
	{
		tmp = *pile_1;
		*pile_1 = (*pile_1)->next;
		tmp->next = 0;
		ft_lstadd_back(pile_1, tmp);
	}
}

static void	ft_rr(t_list **pile_1, t_list **pile_2)
{
	t_list	*last;
	t_list	*tmp;

	(void)pile_2;
	if (ft_lstsize(*pile_1) >= 2)
	{
		last = *pile_1;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *pile_1;
		*pile_1 = last;
	}
}

void	start(char *cmd, t_list **pile_1, t_list **pile_2, int x)
{
	int			tmp;
	void		(*f)(t_list **, t_list **);
	const int	len = ft_strlen(cmd);

	tmp = ft_abs(x);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f = &ft_s;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f = &ft_p;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f = &ft_r;
	else
		f = &ft_rr;
	while (tmp--)
	{
		f(pile_1, pile_2);
		if (pile_2 && f != ft_p)
			f(pile_2, 0);
		if (x > 0)
			ft_putendl_fd(cmd, 1);
	}
}
