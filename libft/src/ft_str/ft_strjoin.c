/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:31:47 by oabdelka          #+#    #+#             */
/*   Updated: 2024/07/30 18:33:55 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	buffer;

	buffer = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (buffer + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1));
	ft_strlcat(res, s2, buffer + 1);
	return (res);
}
