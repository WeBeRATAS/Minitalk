/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:59:08 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/02/29 13:18:14 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;
	int				let;

	i = 0;
	let = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == let)
			return ((char *)&s[i]);
		i++;
	}
	if (let == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
