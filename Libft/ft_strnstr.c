/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:02:01 by yunjcho           #+#    #+#             */
/*   Updated: 2022/07/23 19:22:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_get_len(size_t hay_len, size_t nee_len, size_t len)
{
	size_t	len_back;

	len_back = 0;
	if (len >= hay_len && hay_len >= nee_len)
		len_back = hay_len;
	else
		len_back = len;
	return (len_back);
}

static	int	ft_cmp(size_t len_back, size_t nee_len,
		const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < len_back)
	{
		k = i;
		j = 0;
		while (j < nee_len && k < len_back)
		{
			if (haystack[k] != needle[j])
				break ;
			if (j == nee_len - 1)
				return (i);
			k++;
			j++;
		}
		i++;
	}
	return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_len;
	size_t	nee_len;
	size_t	len_back;
	int		cmp_res;

	if (!*needle || (!*needle && !*haystack))
		return ((char *)&haystack[0]);
	if (!*haystack || len == 0)
		return (0);
	hay_len = ft_strlen(haystack);
	nee_len = ft_strlen(needle);
	len_back = ft_get_len(hay_len, nee_len, len);
	cmp_res = ft_cmp(len_back, nee_len, haystack, needle);
	if (cmp_res == -1)
		return (0);
	return ((char *)&haystack[cmp_res]);
}
