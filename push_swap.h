/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:21:49 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:21:50 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 5

# include "libft/libft.h"

/* push_swap_utils.c */
int		split_argv(char ***strs, char **argv, char *sep);
int		verif_valid(char **strs);
int		verif_tri(t_list *pile);

/* instructions.c */
void	start(char *str, t_list **pile_1, t_list **pile_2, int x);

/* tri.c */
void	tri(t_list **pile);

/* petit_tri_utils.c */
int		pile_min(t_list *pile);
int		pile_max(t_list *pile);
int		min(int a, int b);

/* gros_tri_utils.c */
int		pile_minmax(t_list *pile, int num);
void	min_rotate(t_list *pile_a, t_list *pile_b, int *a, int *b);
void	meme_rotate(t_list **pile_a, t_list **pile_b, int a, int b);
void	diff_rotate(t_list **pile_a, t_list **pile_b, int a, int b);

/* get_next_line.c */
char	*get_next_line(char **str);

#endif
