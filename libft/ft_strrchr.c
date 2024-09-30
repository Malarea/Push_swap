/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:19:09 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:19:11 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_pos;

	last_pos = (0);
	while (*s)
	{
		if (*s == c)
			last_pos = (char *)s;
		++s;
	}
	if (last_pos)
		return (last_pos);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
