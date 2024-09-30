/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:22:30 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:22:31 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

static int	verif_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

static int	verif_doublons(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
			if (nums[i] == nums[j++])
				return (1);
		++i;
	}
	return (0);
}

int	split_argv(char ***strs, char **argv, char *sep)
{
	int		ret;
	char	*str;
	char	*tmp;

	str = 0;
	while (*argv)
	{
		if (!str)
			str = ft_strdup(*argv++);
		else
		{
			tmp = str;
			str = ft_strjoin(str, sep);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, *argv++);
			free(tmp);
		}
	}
	*strs = ft_split(str, *sep);
	free(str);
	ret = 0;
	while ((*strs)[ret])
		++ret;
	return (ret);
}

int	verif_valid(char **strs)
{
	int	i;
	int	tmp;
	int	ret;
	int	*nums;

	i = 0;
	ret = 0;
	while (strs[i])
		if (!verif_int(strs[i++]))
			return (ret);
	nums = malloc(sizeof(int) * i);
	if (!nums)
		return (ret);
	tmp = i;
	while (i--)
		nums[i] = ft_atoi(strs[i]);
	if (!verif_doublons(nums, tmp))
		ret = 1;
	free(nums);
	return (ret);
}

int	verif_tri(t_list *pile)
{
	while (pile->next)
	{
		if (ft_atoi(pile->content) > ft_atoi(pile->next->content))
			return (0);
		pile = pile->next;
	}
	return (1);
}
