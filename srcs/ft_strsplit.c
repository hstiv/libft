/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:35:35 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/11 17:58:57 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeder(char **argv, size_t i)
{
	while (i)
	{
		ft_memdel((void **)&argv[i]);
		i--;
	}
	ft_memdel((void **)argv);
}

static int	preprocessor(size_t *l, char const **s, char c, char ***argv)
{
	if (!(*s))
		return (0);
	*l = ft_count_char(*s, c);
	*argv = (char **)malloc(sizeof(char **) * (*l + 1));
	if (!(*argv))
		return (0);
	return (1);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**argv;
	size_t			i;
	size_t			l;

	i = 0;
	if (preprocessor(&l, &s, c, &argv) == 0)
		return (NULL);
	while (l--)
	{
		while (*s == c && *s != '\0')
			s++;
		argv[i] = ft_strsub(s, 0, ft_strlenc(s, c));
		if (!argv[i])
		{
			ft_freeder(argv, i);
			return (NULL);
		}
		s += ft_strlenc(s, c);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
