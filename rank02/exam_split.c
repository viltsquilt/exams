/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:25:52 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/02 15:59:06 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\n' || (c >= '\t' && c <= '\r'));
}

int	count_words(char *string)
{
	int	in_word;
	int	wordcount;

	in_word = 0;
	wordcount = 0;
	while (*string)
	{
		if (!is_space(*string) && in_word == 0)
		{
			in_word = 1;
			wordcount += 1;
			string++;
		}
		else if (is_space(*string) && in_word != 0)
		{
			in_word = 0;
			string++;
		}
		if (!is_space(*string) && in_word != 0)
			string++;
	}
	return (wordcount);
}

void	free_all(int j, char **result)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
}

char	*alloc_and_copy(char *string)
{
	int	i;
	int	len;
	char	*result;

	i = 0;
	len = 0;
	while (string[len] && !is_space(string[len]))
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = string[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

char	**save_words(char *string, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string[i])
	{
		while (is_space(string[i]))
			i++;
		if (string[i])
		{
			result[j] = alloc_and_copy(&string[i]);
			if (!result[j])
			{
				free_all(j, result);
				return (NULL);
			}
			j++;
		}
		while (string[i] && !is_space(string[i]))
			i++;
	}
	return (result);
}

char	**exam_split(char *string)
{
	char	**result;
	int	wordcount;

	wordcount = count_words(string);
	result = malloc((wordcount + 1) * (sizeof(char *)));
	if (!result)
		return (NULL);
	result = save_words(string, result);
	if (!result)
		return (NULL);
	result[wordcount] = NULL;
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	string[] = "abc def ghi jkl m";
	char	**split;

	split = exam_split(string);
	printf("%s %s %s %s %s", split[0], split[1], split[2], split[3], split[4]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split[3]);
	free(split[4]);
	free(split);
	return (0);
}
