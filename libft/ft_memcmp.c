/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:14:47 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:14:48 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (*ptr == *ptr2 && ++i < n)
	{
		ptr++;
		ptr2++;
	}
	return ((int)(*ptr - *ptr2));
}
