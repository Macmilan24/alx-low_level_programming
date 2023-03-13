#include "main.h"
#include <stdlib.h>

int word_len(char *str);
int count_words(char *str);
char **strtow(char *str);

/**
 * word_len - Locates the index marking the end of the
 * first word contained within a string
 * @str: The string to be searched.
 *
 * Return: The index marking the end of the initial word pointed to by str.
 */
int word_len(char *str)
{
	int i = 0, l = 0;

	while (*(str + i) && *(str + i) != ' ')
	{
		l++;
		i++;
	}

	return (l);
}
/**
 * count_words - Count the number of words
 * @str: The string to be searched.
 *
 * Return: The number of words contained within str.
 */
int count_words(char *str)
{
	int i = 0, w = 0, l = 0;

	for (i = 0; *(str + i); i++)
		l++;

	for (i = 0; i < l; i++)
	{
		if (*(str + i) != ' ')
		{
			w++;
			i += word_len(str + i);
		}
	}
	return (w);
}

/**
 * strtow - splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str = NULL, str = "", or the function dails - NULL.
 * Otherwise - a ponter to an array of strings (words).
 */
char **strtow(char *str)
{
	char **strings;
	int i = 0, wo, w, le, l;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	wo = count_words(str);
	if (wo == 0)
		return (NULL);

	strings = malloc(sizeof(char *) * (wo + 1));
	if (strings == NULL)
		return (NULL);

	for (w = 0; w < wo; w++)
	{
		while (str[i] == ' ')
			i++;
		le = word_len(str + i);

		strings[w] = malloc(sizeof(char) * (le + 1));

		if (strings[w] == NULL)
		{
			for (; w >= 0; w--)
				free(strings[w]);

			free(strings);
			return (NULL);
		}

		for (l = 0; l < le; l++)
			strings[w][l] = str[i++];

		strings[w][l] = '\0';
	}
	strings[w] = NULL;

	return (strings);
}
