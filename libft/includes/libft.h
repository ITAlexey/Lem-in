/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:07:53 by dshala            #+#    #+#             */
/*   Updated: 2019/10/03 15:51:53 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# define ABC(c) ((c) < 0 ? -(c) : (c))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) <= (b) ? (a) : (b))
# define ISNULL(pointer) if ((pointer) == NULL) return (NULL)
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 17

char				*add_prefix(char *str, char *pattern);
char				*add_suffix(char *str, char *pattern);
char				*char_to_string(char ch);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long nbr, unsigned int base);
void				ft_free2darray(void **array);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_nbrlen(long long nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, char const *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *to_find,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *str, char c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
void				swap_int(int *a, int *b);
void				swap_str(char **a, char **b);
int					ft_isprime(size_t nb);
size_t				ft_count_words(const char *str, int c);
int					get_next_line(int const fd, char **line);
char				*nbr_to_string(long long nbr);
char				*reverse_string(char *str);
char				*ft_uitoa_base(unsigned long long n, unsigned base);
char				*sum(char *a, char *b, unsigned len_a, unsigned len_b);
char				*multiplication(char *a, char *b, unsigned len_a,
					unsigned len_b);
void				ft_2dmemdel(void **ap, size_t size);

#endif
