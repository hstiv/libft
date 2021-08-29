/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:34:18 by hstiv             #+#    #+#             */
/*   Updated: 2018/12/24 20:37:45 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}
