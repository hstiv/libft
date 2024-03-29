/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_filled.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:42:37 by hstiv             #+#    #+#             */
/*   Updated: 2018/12/31 13:46:18 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pos_encounter(int len, char *position)
{
	if (!ft_strcmp(position, "beginning"))
		return (len);
	else if (!ft_strcmp(position, "end"))
		return (0);
	else
		return (ft_atoi(position) - 1);
}

char	*str_filled(char *s, size_t final_size,
			char filler_symb, char *position)
{
	size_t			len;
	char			*str;

	str = ft_strnew(final_size);
	if (!s || !str)
		return (NULL);
	len = ft_strlen(s);
	ft_memset(str, filler_symb, final_size);
	ft_memcpy(str + pos_encounter(final_size - len, position), s, len);
	ft_strdel(&s);
	return (str);
}
