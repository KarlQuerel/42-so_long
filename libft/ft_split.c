/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:07:00 by kquerel           #+#    #+#             */
/*   Updated: 2022/12/02 17:27:32 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

static int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	ft_freetab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}

static char	*ft_putword(char *str, char c, char **tab)
{
	char	*word;
	int		i;
	int		wordlen;

	wordlen = ft_wordlen(str, c);
	word = malloc(sizeof(char) * (wordlen + 1));
	if (word == NULL)
	{
		ft_freetab(tab);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_word;
	int		worldcount;
	int		i;
	char	*new_str;

	new_str = (char *)s;
	worldcount = ft_wordcount(new_str, c);
	tab_word = malloc(sizeof(char *) * (worldcount + 1));
	if (tab_word == NULL)
		return (NULL);
	i = 0;
	while (*new_str != '\0')
	{
		while (*new_str != '\0' && *new_str == c)
			new_str++;
		if (*new_str != '\0')
		{
			tab_word[i] = ft_putword(new_str, c, tab_word);
			i++;
		}
		while (*new_str != '\0' && *new_str != c)
			new_str++;
	}
	tab_word[i] = 0;
	return (tab_word);
}
