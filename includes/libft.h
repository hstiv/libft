/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:09:25 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/01 14:55:48 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <limits.h>
# include <stdint.h>
# include <signal.h>
# include <math.h>
# include <stdarg.h>

# define SQRT_NEWTON_ACCURACY 0.0001
# define W_END "end"
# define W_BEGIN "beginning"
# define BUFF_SIZE 3

void				ft_arraydel(void **array);
size_t				ft_strlenc(char const *s, char c);
size_t				ft_count_char(char const *ar, char c);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *source, size_t n);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *source, size_t len);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlen2(const char **s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(uint64_t n, int base);
char				*str_filled(char *s, size_t final_size,
						char filler_symb, char *position);
uint16_t			rev_uint16(uint16_t n);
uint32_t			rev_uint32(uint32_t n);
uint64_t			rev_uint64(uint64_t n);
uint32_t			rotr32(uint32_t x, uint32_t n);
uint32_t			rotl32(uint32_t x, uint32_t n);
int					ft_abs(int x);
double				ft_pow(double nb, uint8_t power);
double				ft_sqrt_newton(const double nb);
void				mprintf(const char *format, ...);

#endif
