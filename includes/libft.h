/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 08:33:59 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/08 16:47:47 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int arg);
int		ft_isdigit(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int c);
int		ft_isprint(int arg);
char	*ft_inttohex(unsigned long long decimal);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_chrncmp(const char *str, const char c, int n);
int		ft_chrcmp(const char *str, const char c);
char	*ft_strrev(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
void	*ft_memset(void *str, int c, int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	ft_bzero(void *str, size_t n);
int		ft_toupper(int c);
char	*ft_strtoupper(char *str);
int		ft_tolower(int c);
char	*ft_strtolower(char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);
char	**ft_realloc_dp(char **str, int len);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int index, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *str1, char const *str2, int n);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str1, char c);
char	ft_itoc_base(int i, int base);
char	*ft_itoa_base(__int128 nbr, int base);
char	*ft_itoa(int nbr);
int		ft_floor(__int128 nbr);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putendl_fd(char *str, int fd);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

#endif
