/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:16:38 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:16:39 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (*s)
		while (s[i])
			write(fd, &s[i++], 1);
}
