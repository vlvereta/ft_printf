/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:45:56 by vlvereta          #+#    #+#             */
/*   Updated: 2017/10/26 14:48:39 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	size += 1;
	if ((ptr = (char *)malloc(sizeof(char) * size)))
		ft_bzero(ptr, size);
	else
		return (NULL);
	return (ptr);
}
