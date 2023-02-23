/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:43:29 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/09 18:29:29 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		size;

	sdup = (char *)malloc(sizeof(char) * ft_strlen_lib(s) + 1);
	if (sdup == NULL)
		return (NULL);
	size = 0;
	while (s[size])
	{
		sdup[size] = s[size];
		size++;
	}
	sdup[size] = '\0';
	return (sdup);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("\nRegular Function::::%s::::\n", strdup(av[1]));
		printf("Amazing Function::::%s::::\n\n", ft_strdup(av[1]));
		return (0);
	}
	return (0);
}
*/
