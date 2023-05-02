#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to head pointer of linked list
 * @n: data to add to new node
 * Return: address of new element, or NULL if failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *n_node, *tmp_node;

	new_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
		return (NULL);

	n_node->n = n;
	n_node->next = NULL;

	if (*head == NULL)
		*head = n_node;
	else
	{
		tmp_node = *head;

		while (tmp_node->next != NULL)
			tmp_node = tmp_node->next;
		tmp_node->next = n_node;
	}

	return (n_node);
}

