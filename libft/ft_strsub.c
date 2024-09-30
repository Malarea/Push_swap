/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:19:38 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:19:39 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = ft_memalloc(len + 1);
	if (!s || !result)
		return (NULL);
	result = ft_strncpy(result, (char *)s + start, len);
	return (result);
}
