#include "shell.h"

/**
 * _memset - will fill memory with a constant byte
 * @s: The pointer to the mem area
 * @b: The byte to fill *s with
 * @n: The amount of bytes to be filled
 * Return: (s) a Pointer to the mem area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - will free a string of strings
 * @pp: String of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocates a block of memory
 * @ptr: The pointer to previous malloced block
 * @old_size: The byte size of previous block
 * @new_size: The byte size of new block
 *
 * Return: The pointer to the old block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
