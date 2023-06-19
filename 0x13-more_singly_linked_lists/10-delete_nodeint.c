#include "lists.h"

/**
 * delete_nodeint_at_index - delete a node at a given position
 * @head: pointer to head pointer of linked list
 * @index: index to delete node
 * Return: 1 if succeeded.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{

	unsigned int i = 0;
	listint_t *node, *tmp;

	if (*head == NULL)
		return (-1);

	node = *head;

	if (index == 0)
	{
		*head = node->next;
		free(node);
		return (1);
	}

	while (i < (index - 1) && node != NULL)
	{
		node = node->next;
		i++;
	}

	if (i != (index - 1) || node->next == NULL)
		return (-1);

	tmp = node->next;
	node->next = (node->next)->next;
	free(tmp);

	return (1);
}

