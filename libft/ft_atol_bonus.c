/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:10:38 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:10:40 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (sign < 0 && ret > 0)
			return (LONG_MIN);
		else if (sign > 0 && ret < 0)
			return (LONG_MAX);
	}
	return (ret);
}
