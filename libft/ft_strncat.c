/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:29:55 by vlvereta          #+#    #+#             */
/*   Updated: 2017/10/27 13:36:38 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	while (j < n && s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
