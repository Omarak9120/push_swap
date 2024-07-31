/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:31:47 by oabdelka          #+#    #+#             */
/*   Updated: 2024/07/30 18:33:57 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	char	*psrc;

	psrc = (char *)src;
	a = 0;
	while (*dst && a < size)
	{
		dst++;
		a++;
	}
	if (a == size)
		return (a + ft_strlen(src));
	b = 0;
	while (psrc[b])
	{
		if (b < size - a - 1)
			*dst++ = psrc[b];
		b++;
	}
	*dst = 0;
	return (a + b);
}
/*
int main(void) {
    char dst[20] = "Hello ";
    const char *src = "world!";
    size_t size = sizeof(dst);

    printf("Before ft_strlcat: dst = \"%s\"\n", dst);
    size_t result = ft_strlcat(dst, src, size);
    printf("After ft_strlcat: dst = \"%s\"\n", dst);
    printf("Return value: %zu\n", result);

    return 0;
}
*/
