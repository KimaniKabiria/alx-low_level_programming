#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _new_node - add new node to list
 * @l: old list
 * @s: size of the new list
 * @n: new node
 * Return: pointer to the new list
 */

listint_t **_new_node(listint_t **l, size_t s, listint_t *n)
{
	listint_t **newlist;
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
 * free_listint_safe - frees a listint_t linked list.
 * @head: double pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t i, num = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (num);
	while (*head != NULL)
	{
		for (i = 0; i < num; i++)
		{
			if (*head == list[i])
			{
				*head = NULL;
				free(list);
				return (num);
			}
		}
		num++;
		list = _new_node(list, num, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (num);
}
