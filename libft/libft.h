/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emachrek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:20:21 by emachrek          #+#    #+#             */
/*   Updated: 2022/02/05 10:20:23 by emachrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
int		ft_islower(int n);
int		ft_isupper(int n);
int		ft_isalpha(int n);
int		ft_isdigit(int n);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isprint(int n);
int		ft_toupper(int n);
int		ft_tolower(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putnbr(int nb);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strncat(char *dest, const char *src, size_t nb);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strchr(const char *s, int c);
char	*ft_strrev(char *str);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_bzero(void *b, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putendl(char *s);
char	*ft_itoa(int nbr);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
long	ft_atol(const char *str);
int		ft_abs(int i);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_isspace(int c);
int		ft_numlen(int n, int base);

#endif
