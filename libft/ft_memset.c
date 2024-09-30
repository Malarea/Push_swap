/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:15:13 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:15:14 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)pointer;
	while (count > 0)
	{
		*ptr = (unsigned char)value;
		ptr++;
		count--;
	}
	return (pointer);
}
