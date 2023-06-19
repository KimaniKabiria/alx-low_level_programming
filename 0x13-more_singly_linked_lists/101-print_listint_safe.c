#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _new - add new node to list
 * @l: the old list
 * @s: size of the new list
 * @n: new node
 * Return: pointer to the new list
 */

const listint_t **_new(const listint_t **l, size_t s, const listint_t *n)
{
	const listint_t **newlist;
	size_t i;

	newlist = malloc(s * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(l);
		exit(98);
	}
	for (i = 0; i < s - 1; i++)
		newlist[i] = l[i];
	newlist[i] = n;
	free(l);
	return (newlist);
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, num = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (i = 0; i < num; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (num);
			}
		}
		num++;
		list = _new(list, num, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (num);
}
