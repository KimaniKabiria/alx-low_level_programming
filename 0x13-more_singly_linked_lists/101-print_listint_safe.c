#include <stdio.h>
#include "lists.h"

/**
 * check_node - check for unique nodes, and add to listint_t linked list
 * @head: pointer to a pointer to a linked list
 * @n: pointer to value
 *
 * Return: pointer to new element
 */
size_t check_node(listptr_t **head, const listptr_t *n)
{
	listptr_t *new;

	new = malloc(sizeof(listptr_t));
	if (new == NULL)
	{
		free_node(*head);
		exit(98);
	}
	new->store = (void *)n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * free_node - free dynamic memory
 * @head: pointer to a pointer to a linked list
 *
 * Return: void
 */
void free_node(listptr_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * print_listint_safe - prints a linked list containing loops
 * @head: pointer to listint_t linked list
 *
 * Return: number of elements
 */
size_t print_listint_safe(const listint_t *head)
{
	listptr_t *temp, *new;
	size_t count;

	new = NULL;
	count = 0;
	while (head)
	{
		temp = new;
		while (temp)
		{
			if (temp->store == head)
			{
				printf("-> [%p] %d", &head, head->n);
				free_node(temp);
				return (count);
			}
			temp = temp->next;
		}
		printf("[%p] %d", &head, head->n);
		check_node(new, head);
		head = head->next;
		count++;
	}
	free_node(new);
	return (count);
}

