/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_to_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:47:56 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/25 12:53:41 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*byte_to_bits(unsigned char octet)
{
	int		size;
	char	*bits;

	size = 8;
	if (!(bits = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	bits[size--] = '\0';
	while (size >= 0)
	{
		if (octet)
		{
			bits[size--] = octet % 2 + '0';
			octet /= 2;
		}
		else
			bits[size--] = '0';
	}
	return (bits);
}
